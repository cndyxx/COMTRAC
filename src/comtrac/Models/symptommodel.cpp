#include <QDataStream>
#include "symptommodel.h"
#include <iostream>

SymptomModel::SymptomModel(QObject *parent) : QSqlQueryModel(parent)
{


}

int SymptomModel::addSymptom(QString name, QString intensity, int frequency,  QString duration, QDate entryDate, QTime entryTime)
{
    int newSymptomID;

    QSqlQuery query;
    query.prepare("INSERT INTO symptoms (name, intensity, frequency, duration, entryDate, entryTime) "
                  "VALUES (:name, :intensity, :frequency, :duration, :entryDate, :entryTime)");
    query.bindValue(":name", name);
    query.bindValue(":intensity", intensity);
    query.bindValue(":frequency", frequency);
    query.bindValue(":duration", duration);
    query.bindValue(":entryDate", entryDate);
    query.bindValue(":entryTime", entryTime);

    if(query.exec()) {
        newSymptomID = query.lastInsertId().toInt();
        std::cout << "LETZTE ID: " + newSymptomID << std::endl;
    }

    return newSymptomID;

}

void SymptomModel::deleteSymptom()
{


    int symptomId = m_singleSymptom->id();
    std::cout << "ID die gelöscht wird: " << symptomId << std::endl;
    //Symptom aus der Datenbank entfernen
    QSqlQuery query;
    query.prepare("DELETE FROM symptoms WHERE id = ?");
    query.bindValue(0, symptomId);
    qDebug() << query.exec();

    //Symptom aus der Symptom Liste entfernen
    for (int i = 0; i < m_symptoms.size(); i++)
    {
        Symptom* symptom = m_symptoms.at(i);
        if (symptom->id() == symptomId)
        {
            m_symptoms.removeAt(i);
            delete symptom; // Speicher freigeben
            break;
        }
    }

    emit symptomsChanged();
}

void SymptomModel::updateSymptom(QString name, QString intensity, int frequency, QString duration)
{
    int id = m_singleSymptom->id();
    m_singleSymptom->setName(name);
    m_singleSymptom->setIntensity(intensity);
    m_singleSymptom->setFrequency(frequency);
    m_singleSymptom->setDuration(duration);

    QSqlQuery query;
    query.prepare("UPDATE symptoms set name = ?, intensity = ?, frequency = ?, duration = ? WHERE symptomID = ?");

    query.bindValue(0, name);
    query.bindValue(1, intensity);
    query.bindValue(2, frequency);
    query.bindValue(3, duration);
    query.bindValue(4, id);
    if(!query.exec())
        qDebug() << "Fehler bei der Ausführung der Abfrage:" << query.lastError().text();
    emit symptomsChanged();

}

//Eintragsdatum aus der Datenbank holen - Tage an denen meherere Symptome eingetragen werden wird nur einmal das Datum aus der
//Datenbank entnommen - keine Duplikate
void SymptomModel::getEntryDates(QString month)
{
    QSqlQuery query;
    query.prepare("SELECT entryDate FROM symptoms WHERE strftime('%m', entryDate) = ? GROUP BY [entryDate]");
    query.bindValue(0, month);
    if(query.exec()){
        while(query.next()){
            QDate date = query.value(0).toDate();
            m_symptomsOfMonth.push_back(date);
        }
    } else {
        qDebug() << "Fehler bei der Ausführung der Abfrage:" << query.lastError().text();
    }
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
    //Liste leeren
    if(! m_symptoms.isEmpty()){
        m_symptoms.clear();
    }
    QSqlQuery query;
    query.prepare("SELECT * FROM Symptoms WHERE entryDate = ?");
    query.bindValue(0, entry_Date);
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
        }
    } else {
        qDebug() << "Fehler bei der Ausführung der Abfrage:" << query.lastError().text();
    }
     emit symptomsChanged();
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
void SymptomModel::setSymptoms(QString name, QString intensity, int frequency, QString duration, QString entry_date, QString entry_time)
{
    QDate entryDate = QDate::fromString(entry_date,"dd.MM.yyyy");
    QTime entryTime = QTime::fromString(entry_time, "hh:mm");

    //Symptom in die Datenbank einpflegen
    int newID = addSymptom(name, intensity, frequency, duration, entryDate, entryTime);

    //Symptom zur Symptomliste hinzufügen
    m_symptoms.push_back(new Symptom(newID, name, intensity, frequency, duration, entryDate, entryTime, this));
    emit symptomsChanged();

}


//Alle Symptome aus der Datenbank holen
void SymptomModel::getSymptoms()
{
    if(! m_symptoms.isEmpty()){
        m_symptoms.clear();
    }
    QSqlQuery query;
    query.prepare("SELECT * FROM Symptoms");

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

}




