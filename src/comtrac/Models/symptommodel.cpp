
#include "symptommodel.h"


SymptomModel::SymptomModel(QObject *parent) : QSqlQueryModel(parent)
{

    getSymptoms();
}

void SymptomModel::addSymptom(const QString &name, const QString &intensity,const int& frequency, const QString &duration)
{
    QDateTime currentDateTime = QDateTime::currentDateTime();
    QString entryDate = currentDateTime.date().toString(Qt::ISODate);
    QString entryTime = currentDateTime.time().toString(Qt::ISODateWithMs);

    QSqlQuery query;
    query.prepare("INSERT INTO symptoms (name, intensity, frequency, duration, entry_date, entry_time) "
                  "VALUES (:name, :intensity, :frequency, :duration, :entry_date, :entry_time)");
    query.bindValue(":name", name);
    query.bindValue(":intensity", intensity);
    query.bindValue(":frequency", frequency);
    query.bindValue(":duration", duration);
    query.bindValue(":entry_date", entryDate);
    query.bindValue(":entry_time", entryTime);
    query.exec();

    updateModel();
}

void SymptomModel::updateModel()
{
    //Daten holen -> SELECT

    // Aktualisiere die ListView im QML
    emit layoutChanged();
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

