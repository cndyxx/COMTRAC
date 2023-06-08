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
    QTime time(8,0,0);
    QList<QTime> m_intakeTime;
    m_intakeTime.push_back(time);
    m_singleMedication = new Medication(0, "", 1, m_intakeTime, "", this);
}

MedicationModel::~MedicationModel()
{
    delete m_singleMedication;
    m_singleMedication = nullptr;

    for (Medication *medication : m_medications) {
        delete medication;
    }


}

void MedicationModel::getMedication()
{
    QSqlQuery query;
    query.prepare("SELECT m.medicationID, m.name, e.intakeTime, reminderTime, intakePerDay FROM Medications m LEFT JOIN MedicationIntake me ON m.medicationID = me.medicationID LEFT JOIN Intake e ON me.intakeID = e.intakeID");

    int previousId = -1;
    bool firstTimeInLoop = false;
    QList<QTime> intakeTimes;
    QString name;
    int intakePerDay;
    QString reminderTime;
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
                std::cout << "ID: " + previousId;
            }
            name = query.value(1).toString();
            intakePerDay = query.value(4).toInt();
            reminderTime = query.value(3).toString();
            QTime intakeTime = query.value(2).toTime();
            intakeTimes.push_back(intakeTime);


            qDebug() << "TEST: " << name;
        }

    } else {
        qDebug() << "Fehler bei der Ausführung der Abfrage:" << query.lastError().text();
    }
    m_medications.push_back(new Medication(previousId, name, intakePerDay, intakeTimes, reminderTime, this));
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

Medication *MedicationModel::singleMedication() const
{
    return m_singleMedication;
}

void MedicationModel::setSingleMedication(Medication *newSingleMedication)
{
    if (m_singleMedication == newSingleMedication)
        return;
    m_singleMedication = newSingleMedication;
    emit singleMedicationChanged();
}

void MedicationModel::setIntakeTime(QString m_time, int index)
{
    QTime time = QTime::fromString(m_time, "hh:mm");
    m_singleMedication->setIntakeTime(time, index);
    emit singleMedicationChanged();
}

void MedicationModel::initializeIntakeTimeList(int size)
{
    m_singleMedication->setIntakePerDay(size);
    QTime time(8,0,0);
    QList<QTime> m_intakeTime;

    for(int i = 0; i < size; i++){
        m_intakeTime.push_back(time);
    }
    m_singleMedication->setIntakeTime(m_intakeTime);
     emit singleMedicationChanged();
}



void MedicationModel::deleteMedication()
{
    int id = m_singleMedication->id();
    std::cout << "ID IN MODEL: " << id;
    QSqlQuery query;
    query.prepare("DELETE FROM MedicationIntake WHERE medicationID = :medicationID");
    query.bindValue(":medicationID", id);
    if (!query.exec()) {
        qDebug() << "Error deleting records from MedicationIntake table:" << query.lastError().text();
        return;
    }
    query.prepare("DELETE FROM Medications WHERE medicationID = ?");
    query.bindValue(0, id);
    if(query.exec()) {
        for (int i = 0; i < m_medications.size(); i++)
        {
            Medication* medication = m_medications.at(i);
            if (medication->id() == id)
            {
                m_medications.removeAt(i);
                delete medication; // Speicher freigeben
                break;
            }
        }
    } else {
         qDebug() << "Fehler bei der Ausführung der Abfrage:" << query.lastError().text();
    }

    emit medicationsChanged();

}

void MedicationModel::updateMedication(QString name, int intakePerDay, QList<QTime> intakeTimes, QString reminderTime)
{
    //UPDATE MedicationIntake SET intakeTime = :intakeTime WHERE medicationID = :medicationID
}

void MedicationModel::addMedication(QString name,int intakePerDay,QList<QTime> intakeTimes, QString reminderTime)
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
        m_medications.push_back(new Medication(medicationID, name, intakePerDay, intakeTimes, reminderTime, this));
    }
    else {
        qDebug() << "Fehler bei der Ausführung der Abfrage:" << query.lastError().text();
    }
    emit medicationsChanged();
}




