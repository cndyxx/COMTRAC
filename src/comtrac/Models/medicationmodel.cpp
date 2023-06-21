#include "medicationmodel.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QTime>
#include <QDebug>

#include <iostream>



MedicationModel::MedicationModel(QObject *parent) : QSqlQueryModel(parent)
{
    //getMedication();
    QTime time(8,0,0);
    QList<QTime> m_intakeTime;
    m_intakeTime.push_back(time);
    m_singleMedication = new Medication(0, "", 1, m_intakeTime, "", this);
    m_medications.push_back(new Medication(1, "Hustensaft", 2, m_intakeTime, "", this));
    m_medications.push_back(new Medication(2, "Ibuprofen", 3, m_intakeTime, "", this));
    m_medications.push_back(new Medication(3, "Salbe", 3, m_intakeTime, "", this));
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

QList<QString> MedicationModel::orderMedication() const
{
    return m_orderMedication;
}

void MedicationModel::setOrderMedication(const QList<QString> &newOrderMedication)
{
    if (m_orderMedication == newOrderMedication)
        return;
    m_orderMedication = newOrderMedication;
    emit orderMedicationChanged();
}

void MedicationModel::setMessageModel(MessageModel *messageModel)
{

    // Speichern Sie den Zeiger auf das MessageModel-Objekt
    m_messageModel = messageModel;

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
    //    if(query.exec()) {
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
    //    } else {
    //        qDebug() << "Fehler bei der Ausführung der Abfrage:" << query.lastError().text();
    //    }

    emit medicationsChanged();

}

void MedicationModel::updateMedication(QString name, int intakePerDay, QList<QTime> intakeTimes, QString reminderTime)
{
    //UPDATE MedicationIntake SET intakeTime = :intakeTime WHERE medicationID = :medicationID
    int medicationId = m_singleMedication->id();
    QSqlQuery query;
    query.prepare("UPDATE Medications SET name = ?, intakePerDay = ?, reminderTime = ? WHERE medicationID = ?");
    query.bindValue(0, name);
    query.bindValue(1, intakePerDay);
    query.bindValue(2, reminderTime);
    query.bindValue(3, medicationId);
    if(!query.exec())
        qDebug() << "Fehler bei der Ausführung der Abfrage:" << query.lastError().text();

                                                                query.prepare("UPDATE Intake SET intakeTime = ? WHERE intakeID IN (SELECT intakeID FROM MedicationIntake WHERE medicationID = ?)");
    for(int i = 0; i < intakeTimes.size(); i++){
        query.bindValue(0, intakeTimes[i]);
        query.bindValue(1, medicationId);
        if(!query.exec())
            qDebug() << "Fehler bei der Ausführung der Abfrage:" << query.lastError().text();
    }

    emit medicationsChanged();

}

void MedicationModel::addOrderedMedication(QString name)
{
    m_orderMedication.push_back(name);
}

void MedicationModel::deleteOrderedMedication(QString name)
{
    for (int i = 0; i < m_orderMedication.size(); i++)
    {
        QString medication = m_orderMedication.at(i);
        if (medication == name)
        {
            m_orderMedication.removeAt(i);
            break;
        }
    }
}

QString MedicationModel::getOrderedMedication()
{
    QString orderText = "Rezept für ";
        if (m_orderMedication.size() == 1) {
        orderText += m_orderMedication[0] + " bestellen.";
    } else if (m_orderMedication.size() > 1) {
        orderText = "Rezepte für ";
            for (int i = 0; i < m_orderMedication.size() - 1; i++) {
            orderText += m_orderMedication[i] + " und ";
        }
        orderText += m_orderMedication[m_orderMedication.size() -1 ] + " bestellen.";
    }

    QList<Message *> messageList = m_messageModel->getMessages();
    messageList[3]->setText(orderText);
    m_messageModel->setMessages(messageList);
    for (Message *newMessage : messageList) {
        delete newMessage;
    }


    return orderText;
}

void MedicationModel::deleteOrderedMedicationList()
{
    m_orderMedication.clear();
}

void MedicationModel::addMedication(QString name,int intakePerDay,QList<QTime> intakeTimes, QString reminderTime)
{
    int medicationID;
    QSqlQuery query;
    query.prepare("INSERT INTO medications (name, intakePerDay, reminderTime) VALUES (:name, :intakePerDay, :reminderTime)");
    query.bindValue(":name", name);
    query.bindValue(":intakePerDay", intakePerDay);
    query.bindValue(":reminderTime", reminderTime);

//    if(query.exec()) {
        medicationID = query.lastInsertId().toInt();
        addIntakeTime(medicationID, intakeTimes);
        m_medications.push_back(new Medication(medicationID, name, intakePerDay, intakeTimes, reminderTime, this));
//    }
//    else {
//        qDebug() << "Fehler bei der Ausführung der Abfrage:" << query.lastError().text();
//    }
    emit medicationsChanged();
}




