#include <QDataStream>
#include "symptommodel.h"
#include <iostream>
#include <chrono>
#include <sstream>
#include <iomanip>


using std::ostringstream;

SymptomModel::SymptomModel(QObject *parent) : QSqlQueryModel(parent)
{
    QDate date;
    QTime time;
    //Kalenderwoche 24
    m_symptoms.push_back(new Symptom(0, "Fieber", "leicht", 1, "Seit weniger als 24 Stunden", QDate(2023,6,12) , QTime(9,30,0), this));
    m_symptoms.push_back(new Symptom(1, "Gliederschmerzen", "leicht", 1, "Seit weniger als 24 Stunden", QDate(2023,6,13) , QTime(9,30,0),  this));
    m_symptoms.push_back(new Symptom(2, "Durchfall", "leicht", 6, "Seit weniger als 24 Stunden", QDate(2023,6,14) , QTime(9,30,0),  this));
    m_symptoms.push_back(new Symptom(3, "Hautausschlag", "leicht", 1, "Seit weniger als 24 Stunden", QDate(2023,6,15) , QTime(9,30,0),  this));
    m_symptoms.push_back(new Symptom(4, "Nachtschweiß", "leicht", 1, "Seit weniger als 24 Stunden", QDate(2023,6,17) , QTime(9,30,0),  this));
        //Kalenderwoche 25
    m_symptoms.push_back(new Symptom(5, "Fieber", "leicht", 1, "Seit weniger als 24 Stunden", QDate(2023,6,19) , QTime(9,30,0),  this));
    m_symptoms.push_back(new Symptom(6, "Gliederschmerzen", "leicht", 1, "Seit weniger als 24 Stunden", QDate(2023,6,20) , QTime(9,30,0),  this));
    m_symptoms.push_back(new Symptom(7, "Durchfall", "leicht", 5, "Seit weniger als 24 Stunden", QDate(2023,6, 22) , QTime(9,30,0),  this));
    //Kalenderwoche 26
   // m_symptoms.push_back(new Symptom(8, "Fieber", "leicht", 1, "", QDate(2023,6,26) , QTime(9,30,0),  this));
    // m_symptoms.push_back(new Symptom(9, "Nachtschweiß", "leicht", 1, "", QDate(2023,6,27) , QTime(9,30,0),  this));
    // m_symptoms.push_back(new Symptom(10, "Durchfall", "leicht", 1, "", QDate(2023,6,29) , QTime(9,30,0),  this));
    date = QDate(2023, 6,26);
    m_symptoms.push_back(new Symptom(8, "Fieber", "leicht", 1, "Seit mehr als 24 Stunden", date , QTime(9,30,0),  this));
    for(int i = 0; i < 8; i++){
        primaryKey.push_back(i);
    }
}



std::tm SymptomModel::getWeekendDate(int year, int weekNumber)
{
    std::tm startDate = {};
    startDate.tm_year = year - 1900;
    startDate.tm_mday = 1;

    std::time_t startDateT = std::mktime(&startDate);
    std::tm* startDateTime = std::localtime(&startDateT);

    // Berechnen des Startdatums der angegebenen Kalenderwoche
    int daysToMonday = (startDateTime->tm_wday + 6) % 7; // Tage bis zum Montag
    int daysToAdd = (weekNumber - 1) * 7 + daysToMonday;
    std::chrono::hours hoursToAdd(daysToAdd * 24);
    std::chrono::system_clock::time_point weekStartDate = std::chrono::system_clock::from_time_t(startDateT) + hoursToAdd;
    std::time_t weekStartDateT = std::chrono::system_clock::to_time_t(weekStartDate);
    std::tm* weekStartDateTime = std::localtime(&weekStartDateT);

    // Einstellen des Anfangstages auf Montag
    int daysToMondayShift = (weekStartDateTime->tm_wday + 6) % 7;
    std::chrono::hours hoursToMonday(daysToMondayShift * 24);
    std::chrono::system_clock::time_point mondayStartDate = weekStartDate - hoursToMonday;
    std::time_t mondayStartDateT = std::chrono::system_clock::to_time_t(mondayStartDate);
    std::tm* mondayStartDateTime = std::localtime(&mondayStartDateT);

    return *mondayStartDateTime;;
}
void SymptomModel::deleteSymptom()
{


    int symptomId = m_singleSymptom->id();
    for(int i = 0; i < primaryKey.size(); i++){
        if(primaryKey[i] == symptomId){
            primaryKey.removeAt(i);
        }
    }
    std::cout << "ID die gelöscht wird: " << symptomId << std::endl;
            //Symptom aus der Datenbank entfernen
            //            QSqlQuery query;
            //    query.prepare("DELETE FROM symptoms WHERE symptomID = ?");
            //    query.bindValue(0, symptomId);
            //    qDebug() << query.exec();

                //Symptom aus der Symptom Liste entfernen


                    //Symptom aus der Symptom Liste entfernen
    deleteSymptomOfList(m_daySymptoms, symptomId);
    deleteSymptomOfList(m_symptoms, symptomId);

    emit symptomsChanged();
    emit daySymptomsChanged();

}

void SymptomModel::updateSymptom(QString name, QString intensity, int frequency, QString duration)
{
    int id = m_singleSymptom->id();
    m_singleSymptom->setName(name);
    m_singleSymptom->setIntensity(intensity);
    m_singleSymptom->setFrequency(frequency);
    m_singleSymptom->setDuration(duration);

    //    QSqlQuery query;
    //    query.prepare("UPDATE symptoms set name = ?, intensity = ?, frequency = ?, duration = ? WHERE symptomID = ?");

    //    query.bindValue(0, name);
    //    query.bindValue(1, intensity);
    //    query.bindValue(2, frequency);
    //    query.bindValue(3, duration);
    //    query.bindValue(4, id);
    //    if(!query.exec())
    //        qDebug() << "Fehler bei der Ausführung der Abfrage:" << query.lastError().text();
    emit symptomsChanged();

}

//Eintragsdatum aus der Datenbank holen - Tage an denen meherere Symptome eingetragen werden wird nur einmal das Datum aus der
//Datenbank entnommen - keine Duplikate
void SymptomModel::getEntryDates(QString month)
{
    if(! m_symptomsOfMonth.isEmpty()){
        m_symptomsOfMonth.clear();
    }


    for (Symptom* symptom : m_symptoms) {
        if(symptom->entryDate().month() == month.toInt()){
            m_symptomsOfMonth.push_back(symptom->entryDate());
        }
    }
    //    QSqlQuery query;
    //    query.prepare("SELECT entryDate FROM symptoms WHERE strftime('%m', entryDate) = ? GROUP BY [entryDate]");
    //    query.bindValue(0, month);
    //    if(query.exec()){
    //        while(query.next()){
    //            QDate date = query.value(0).toDate();
    //            m_symptomsOfMonth.push_back(date);
    //        }
    //    } else {
    //        qDebug() << "Fehler bei der Ausführung der Abfrage:" << query.lastError().text();
    //    }

}

bool SymptomModel::findDate(QString date)
{
    bool isInList = false;

    for(QDate newDate : m_symptomsOfMonth){
        if(newDate.toString("yyyy-MM-dd") == date){
            isInList = true;
            break;
        }
    }
    return isInList;
}




void SymptomModel::updateModel()
{
    //Daten holen -> SELECT

    // Aktualisiere die ListView im QML
    emit layoutChanged();
}

void SymptomModel::deleteSymptomOfList(QList<Symptom *> &list, int symptomId)
{

    //Symptom aus der Symptom Liste entfernen
    for (int i = 0; i < list.size(); i++)
    {
        Symptom* symptom = list.at(i);
        if (symptom->id() == symptomId)
        {
            list.removeAt(i);
            delete symptom; // Speicher freigeben
            break;
        }
    }
}

QList<Symptom *> SymptomModel::symptomEntries() const
{
    return m_symptomEntries;
}

void SymptomModel::setSymptomEntries(const QList<Symptom *> &newSymptomEntries)
{
    if (m_symptomEntries == newSymptomEntries)
        return;
    m_symptomEntries = newSymptomEntries;
    emit symptomEntriesChanged();
}

QList<Symptom *> SymptomModel::weekSymptoms() const
{
    return m_weekSymptoms;
}

void SymptomModel::setWeekSymptoms(const QList<Symptom *> &newWeekSymptoms)
{
    if (m_weekSymptoms == newWeekSymptoms)
        return;
    m_weekSymptoms = newWeekSymptoms;
    emit weekSymptomsChanged();
}


QList<QDate> SymptomModel::symptomsOfMonth() const
{
    return m_symptomsOfMonth;
}

void SymptomModel::setSymptomsOfMonth(const QList<QDate> &newSymptomsOfMonth)
{
    if (m_symptomsOfMonth == newSymptomsOfMonth)
        return;
    m_symptomsOfMonth = newSymptomsOfMonth;
    emit symptomsOfMonthChanged();
}

SymptomModel::~SymptomModel()
{
    delete m_singleSymptom;
    m_singleSymptom = nullptr;

    for (Symptom *symptom : m_symptoms) {
        delete symptom;
    }

    for (Symptom *symptom : m_weekSymptoms) {
        delete symptom;
    }

    for (Symptom *symptom : m_daySymptoms) {
        delete symptom;
    }
    for (Symptom *symptom : m_symptomEntries) {
        delete symptom;
    }
}


QList<Symptom *> SymptomModel::daySymptoms() const
{
    return m_daySymptoms;
}

void SymptomModel::setDaySymptoms(const QList<Symptom *> &newDaySymptoms)
{
    if (m_daySymptoms == newDaySymptoms)
        return;
    m_daySymptoms = newDaySymptoms;
    emit daySymptomsChanged();
}

Symptom *SymptomModel::singleSymptom() const
{
    return m_singleSymptom;
}

void SymptomModel::setSingleSymptom(Symptom *newSingleSymptom)
{
    if (m_singleSymptom == newSingleSymptom)
        return;
    m_singleSymptom = newSingleSymptom;
    emit singleSymptomChanged();
}

void SymptomModel::getSymptomsOfDate(QString entry_Date)
{
    if(! m_daySymptoms.isEmpty()){
        m_daySymptoms.clear();
    }
    QDate entryDate = QDate::fromString(entry_Date,"yyyy-MM-dd");
    for (Symptom* symptom : m_symptoms) {
        if (symptom->entryDate() == entryDate) {
            m_daySymptoms.push_back(symptom);
        }

    }
    //    QSqlQuery query;
    //    query.prepare("SELECT * FROM Symptoms WHERE entryDate = ?");
    //    query.bindValue(0, entry_Date);
    //    if(query.exec()){
    //        while(query.next()){
    //            int id = query.value(0).toInt();
    //            QString name = query.value(1).toString();
    //            QString intensity = query.value(2).toString();
    //            int frequency = query.value(3).toInt();
    //            QString duration = query.value(4).toString();
    //            QDate entryDate = query.value(5).toDate();
    //            QTime entryTime = query.value(6).toTime();
    //            m_daySymptoms.push_back(new Symptom(id, name, intensity, frequency, duration, entryDate, entryTime, this));
    //        }
    //    } else {
    //        qDebug() << "Fehler bei der Ausführung der Abfrage:" << query.lastError().text();
    //    }


    emit daySymptomsChanged();
}

void SymptomModel::getSymptomsOfWeek(QString start_date, QString end_date)
{
    if(! m_weekSymptoms.isEmpty()){
        m_weekSymptoms.clear();
    }

    //    QSqlQuery query;
    //    query.prepare("SELECT * FROM Symptoms WHERE entryDate BETWEEN ? AND ? GROUP BY [name]");
    //    query.bindValue(0, startDate);
    //    query.bindValue(1, endDate);
    //    if(query.exec()) {
    //        while(query.next()){
    //            int id = query.value(0).toInt();
    //            QString name = query.value(1).toString();
    //            QString intensity = query.value(2).toString();
    //            int frequency = query.value(3).toInt();
    //            QString duration = query.value(4).toString();
    //            QDate entryDate = query.value(5).toDate();
    //            QTime entryTime = query.value(6).toTime();
    //            m_weekSymptoms.push_back(new Symptom(id, name, intensity, frequency, duration, entryDate, entryTime, this));
    //        }
    //    }else {
    //        qDebug() << "Fehler bei der Ausführung der Abfrage:" << query.lastError().text();
    //    }
    // Funktion zum Filtern der Einträge zwischen den gegebenen Datumsangaben

    QDate startDate = QDate::fromString(start_date,"yyyy-MM-dd");
    QDate endDate = QDate::fromString(end_date,"yyyy-MM-dd");

    for (Symptom* symptom : m_symptoms) {
        if (symptom->entryDate() >= startDate && symptom->entryDate() <= endDate) {
            m_weekSymptoms.push_back(symptom);
        }

    }


    emit weekSymptomsChanged();
}

void SymptomModel::getSymptomEntries(QString name)
{
    if(! m_symptomEntries.isEmpty()){
        m_symptomEntries.clear();
    }
    for(Symptom* symptom : m_symptoms){
        if(symptom->name() == name){
            m_symptomEntries.push_back(symptom);
        }
    }
    //    QSqlQuery query;
    //    query.prepare("SELECT * FROM Symptoms WHERE name = ?");
    //    query.bindValue(0, name);
    //    if(query.exec()) {
    //        while(query.next()){
    //            int id = query.value(0).toInt();
    //            QString name = query.value(1).toString();
    //            QString intensity = query.value(2).toString();
    //            int frequency = query.value(3).toInt();
    //            QString duration = query.value(4).toString();
    //            QDate entryDate = query.value(5).toDate();
    //            QTime entryTime = query.value(6).toTime();
    //            m_symptomEntries.push_back(new Symptom(id, name, intensity, frequency, duration, entryDate, entryTime, this));
    //        }
    //    }else {
    //        qDebug() << "Fehler bei der Ausführung der Abfrage:" << query.lastError().text();
    //    }
    emit symptomEntriesChanged();
}

void SymptomModel::getCalendarWeekDate(int year, int weekNumber)
{
    std::tm startDate = getWeekendDate(year, weekNumber);

    std::ostringstream startOss;
    std::ostringstream endOss;

    // Ermittle das Startdatum als QString
    startOss << (startDate.tm_year + 1900) << "-" << std::setw(2) << std::setfill('0') << (startDate.tm_mon + 1) << "-" << std::setw(2) << std::setfill('0') << startDate.tm_mday;
    QString start_date = QString::fromStdString(startOss.str());

    // Erhöhe das Startdatum um 6 Tage und überprüfe, ob ein neuer Monat beginnt
    std::tm endDate = startDate;
    endDate.tm_mday += 6;
    std::mktime(&endDate); // Aktualisiere die Struktur, um den korrekten Monat zu berücksichtigen

    // Ermittle das Enddatum als QString
    endOss << (endDate.tm_year + 1900) << "-" << std::setw(2) << std::setfill('0') << (endDate.tm_mon + 1) << "-" << std::setw(2) << std::setfill('0') << endDate.tm_mday;
    QString end_date = QString::fromStdString(endOss.str());
    getSymptomsOfWeek(start_date, end_date);

}


QList<Symptom *> SymptomModel::symptoms() const
{
    return m_symptoms;
}

void SymptomModel::setSymptoms(const QList<Symptom *> &newSymptoms)
{
    if (m_symptoms == newSymptoms)
        return;
    m_symptoms = newSymptoms;
    emit symptomsChanged();
}

//Neues Symptom zur Liste hinzufügen und in die Datenbank einpflegen
void SymptomModel::addSymptoms(QString name, QString intensity, int frequency, QString duration, QString entry_date, QString entry_time)
{
    int max = primaryKey[0]; // Es wird davon ausgegangen, dass das erste Element das Maximum ist
    for(int i = 0; i < primaryKey.size(); i++){
        if(primaryKey[i] > max)
            max = primaryKey[i];
    }

    int newSymptomID = max + 1;
    QDate entryDate = QDate::fromString(entry_date,"dd.MM.yyyy");
    QTime entryTime = QTime::fromString(entry_time, "hh:mm");  

//    QSqlQuery query;
//    query.prepare("INSERT INTO symptoms (name, intensity, frequency, duration, entryDate, entryTime) "
//                  "VALUES (:name, :intensity, :frequency, :duration, :entryDate, :entryTime)");
//    query.bindValue(":name", name);
//    query.bindValue(":intensity", intensity);
//    query.bindValue(":frequency", frequency);
//    query.bindValue(":duration", duration);
//    query.bindValue(":entryDate", entryDate);
//    query.bindValue(":entryTime", entryTime);

//    if(query.exec()) {
//        newSymptomID = query.lastInsertId().toInt();
//    }
//    else {
//        qDebug() << "Fehler bei der Ausführung der Abfrage:" << query.lastError().text();
//    }

    //Symptom zur Symptomliste hinzufügen
    m_symptoms.push_back(new Symptom(newSymptomID, name, intensity, frequency, duration, entryDate, entryTime, this));
    m_daySymptoms.push_back(new Symptom(newSymptomID, name, intensity, frequency, duration, entryDate, entryTime, this));
    emit symptomsChanged();
    emit daySymptomsChanged();
}


//Alle Symptome aus der Datenbank holen
void SymptomModel::getSymptoms()
{
    if(! m_symptoms.isEmpty()){
        m_symptoms.clear();
    }
    QSqlQuery query;
    query.prepare("SELECT * FROM Symptoms GROUP BY [name]");

    if(query.exec()){
        while(query.next()){
            int id = query.value(0).toInt();
            QString name = query.value(1).toString();
            QString intensity = query.value(2).toString();
            int frequency = query.value(3).toInt();
            QString duration = query.value(4).toString();
            QDate entryDate = query.value(5).toDate();
            QTime entryTime = query.value(6).toTime();
            m_symptoms.push_back(new Symptom(id, name, intensity, frequency, duration, entryDate, entryTime, this));
            qDebug() << "TEST: " << name ;
        }
    } else {
        qDebug() << "Fehler bei der Ausführung der Abfrage:" << query.lastError().text();
    }
    std::reverse(m_symptoms.begin(), m_symptoms.end());

    emit symptomsChanged();
}




