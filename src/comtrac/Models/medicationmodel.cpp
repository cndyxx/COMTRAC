#include "medicationmodel.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QTime>
#include <QDebug>

#include <iostream>



MedicationModel::MedicationModel(QObject *parent) : QSqlQueryModel(parent)
{
    getMedication();
}


void MedicationModel::getMedication()
{
    QSqlQuery query;
    query.prepare("SELECT * FROM Medications");

    if(query.exec()){
        while(query.next()){
            int id = query.value(0).toInt();
            QString name = query.value(1).toString();
            int intakePerDay = query.value(2).toInt();
            QTime intakeTime = query.value(3).toTime();
            QTime reminderTime = query.value(4).toTime();
            m_medications.push_back(new Medication(id, name, intakePerDay, intakeTime, reminderTime, this));
            qDebug() << "TEST: " << name ;
        }
    } else {
        qDebug() << "Fehler bei der Ausführung der Abfrage:" << query.lastError().text();
    }


}

QList<Medication *> MedicationModel::singleMedication() const
{
    return m_singleMedication;
}

void MedicationModel::setSingleMedication(const QList<Medication *> &newSingleMedication)
{
    if (m_singleMedication == newSingleMedication)
        return;
    m_singleMedication = newSingleMedication;
    emit singleMedicationChanged();
}

QList<Medication *> MedicationModel::medications() const
{
    return m_medications;
}

void MedicationModel::setMedications(const QList<Medication *> &newMedications)
{
    if (m_medications == newMedications)
        return;
    m_medications = newMedications;
    emit medicationsChanged();
}


void MedicationModel::addMedication(QString name,int intakePerDay,QList<QTime> intakeTimes, QTime reminderTime)
{
    QString intakeTimesString;
    for(int i = 0; i < intakePerDay; i++){
        intakeTimesString  += intakeTimes[i].toString("hh:mm") + ",";
    }
    intakeTimesString.chop(1); // Entferne das letzte Komma

    QSqlQuery query;
    query.prepare("INSERT INTO medications (name, intakePerDay, intakeTimes, reminderTime) VALUES (?, ?, ?, ?)");
    query.bindValue(0, name);
    query.bindValue(1, intakePerDay);
    query.bindValue(2, intakeTimesString);
    query.bindValue(3, reminderTime);
    query.exec();
    updateModel();
}


//Medikationsplan updaten
void MedicationModel::updateModel()
{
    //Daten aus Datenbank holen -> SELECT
    // The update is performed SQL-queries to the database
    this->setQuery("SELECT id, name, intakePerDay, intakeTimes, reminderTime FROM Symptoms");
}


