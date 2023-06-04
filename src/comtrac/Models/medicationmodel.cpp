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

//Einnahmezeiten von der MedicationID holen
//SELECT e.intakeTime
//    FROM Medications m
//        JOIN MedicationIntake me ON m.medicationID = me.medicationID
//          JOIN Intake e ON me.intakeID = e.intakeID
//          WHERE m.medicationID = 1;
void MedicationModel::getMedication()
{
    QSqlQuery query;
    query.prepare("SELECT m.medicationID, m.name, e.intakeTime, reminderTime, intakePerDay FROM Medications m LEFT JOIN MedicationIntake me ON m.medicationID = me.medicationID LEFT JOIN Intake e ON me.intakeID = e.intakeID");

    int previousId = -1;
    bool firstTimeInLoop = false;
    QList<QTime> intakeTimes;
    QString name;
    int intakePerDay;
    QTime reminderTime;
    if (query.exec()) {
        while (query.next()) {
            int id = query.value(0).toInt();
            if(!firstTimeInLoop){
                firstTimeInLoop = true;
                previousId = id;
            }
            if (id != previousId) {
                m_medications.push_back(new Medication(previousId, name, intakePerDay, intakeTimes, reminderTime, this));
                previousId = id;
                intakeTimes.clear();
            }
            name = query.value(1).toString();
            intakePerDay = query.value(4).toInt();
            reminderTime = query.value(3).toTime();
            QTime intakeTime = query.value(2).toTime();
            intakeTimes.push_back(intakeTime);


            qDebug() << "TEST: " << name;
        }

    } else {
        qDebug() << "Fehler bei der Ausführung der Abfrage:" << query.lastError().text();
    }
    m_medications.push_back(new Medication(previousId, name, intakePerDay, intakeTimes, reminderTime, this));
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

void MedicationModel::addIntakeTime(int medicationID, QList<QTime> intakeTimes)
{
    QSqlQuery query;
    for(int i = 0; i < intakeTimes.size(); i++){
        query.prepare("INSERT INTO Intake (intakeTime) VALUES (?)");
        query.bindValue(0, intakeTimes[i]);
        query.exec();
        int intakeID = query.lastInsertId().toInt();
        std::cout << "LETZTE ID: " + intakeID << std::endl;
        addMedicationIntake(medicationID, intakeID);
    }


}

void MedicationModel::addMedicationIntake(int medicationID, int intakeID)
{
    QSqlQuery query;
    query.prepare("INSERT INTO MedicationIntake (medicationID, intakeID) VALUES (?, ?)");
    query.bindValue(0, medicationID);
    query.bindValue(1, intakeID);
    query.exec();
}

void MedicationModel::addMedication(QString name,int intakePerDay,QList<QTime> intakeTimes, QTime reminderTime)
{
    int medicationID;
    QSqlQuery query;
    query.prepare("INSERT INTO medications (name, intakePerDay, reminderTime) VALUES (:name, :intakePerDay, :reminderTime)");
    query.bindValue(":name", name);
    query.bindValue(":intakePerDay", intakePerDay);
    query.bindValue(":reminderTime", reminderTime);
    if(query.exec()) {
        medicationID = query.lastInsertId().toInt();
        std::cout << "LETZTE ID: " + medicationID << std::endl;
        addIntakeTime(medicationID, intakeTimes);
    }
    else {
        qDebug() << "Fehler bei der Ausführung der Abfrage:" << query.lastError().text();
    }
    emit medicationsChanged();
}




