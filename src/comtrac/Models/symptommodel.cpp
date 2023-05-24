
#include "symptommodel.h"


SymptomModel::SymptomModel(QObject *parent) : QSqlQueryModel(parent)
{

    getSymptoms();
}

void SymptomModel::addSymptom(const QString &name, const QString &intensity,const int& frequency, const QString &duration, QString entry_date, QString entry_time)
{
    qDebug() << "Symptommodel";

    QDate entryDate = QDate::fromString(entry_date,"dd.MM.yyyy");
    QTime entryTime = QTime::fromString(entry_time, "hh:mm");

    QSqlQuery query;
    query.prepare("INSERT INTO symptoms (name, intensity, frequency, duration, entryDate, entryTime) "
                  "VALUES (:name, :intensity, :frequency, :duration, :entryDate, :entryTime)");
    query.bindValue(":name", name);
    query.bindValue(":intensity", intensity);
    query.bindValue(":frequency", frequency);
    query.bindValue(":duration", duration);
    query.bindValue(":entryDate", entryDate);
    query.bindValue(":entryTime", entryTime);
    qDebug() << query.exec() << query.lastError().text();


}

void SymptomModel::setCurrentSymptom(int id)
{
    currentSymptom = id;
}

int SymptomModel::getCurrentSymptom()
{
    return currentSymptom;
}

void SymptomModel::setSymptom(int targetID)
{
    Symptom * foundSymptom;
    // Suche nach dem Symptom anhand der ID
    foreach (Symptom* symptom, m_symptoms) {
        if(symptom->id() == targetID){
            foundSymptom = symptom;
            break;
        }
    }
    setSingleSymptom(foundSymptom);

}

void SymptomModel::updateModel()
{
    //Daten holen -> SELECT

    // Aktualisiere die ListView im QML
    emit layoutChanged();
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

void SymptomModel::getSymptoms()
{
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



