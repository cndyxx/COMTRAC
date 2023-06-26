
#ifndef MEDICATIONMODEL_H
#define MEDICATIONMODEL_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQueryModel>


#include "Models/medication.h"
#include "Models/messagemodel.h"
#include "Models/message.h"


class MedicationModel : public QSqlQueryModel
{
    Q_OBJECT
    Q_PROPERTY(QList<Medication *> medications READ medications WRITE setMedications NOTIFY medicationsChanged)
    Q_PROPERTY(Medication *singleMedication READ singleMedication WRITE setSingleMedication NOTIFY singleMedicationChanged)
    Q_PROPERTY(QList<QString> orderMedication READ orderMedication WRITE setOrderMedication NOTIFY orderMedicationChanged)

private:

    void getMedication();
    void addIntakeTime(int medicationID, QList<QTime> intakeTimes);
    void addMedicationIntake(int medicationID, int intakeID);
    QList<Medication *> m_medications;
    Medication * m_singleMedication;
    QList<QString> m_orderMedication;
    MessageModel* m_messageModel;
    QList<int> primaryKey;


public:

    explicit MedicationModel(QObject *parent = nullptr);
    ~MedicationModel();
    QList<Medication *> medications() const;
    void setMedications(const QList<Medication *> &newMedications);
    Medication *singleMedication() const;

    QList<QString> orderMedication() const;
    void setOrderMedication(const QList<QString> &newOrderMedication);
    void setMessageModel(MessageModel* messageModel);

public slots:

    void addMedication(QString name, int intakePerDay, QList<QTime> intakeTimes, QString reminderTime);
    void setSingleMedication(Medication *newSingleMedication);
    void setIntakeTime(QString time, int index);
    void initializeIntakeTimeList(int size);
    void deleteMedication();
    void updateMedication(QString name, int intakePerDay, QList<QTime> intakeTimes, QString reminderTime);
    void addOrderedMedication(QString name);
    void deleteOrderedMedication(QString name);
    QList<QString>  getOrderedMedication();
    void deleteOrderedMedicationList();

signals:
    void medicationChanged();
    void medicationsChanged();
    void singleMedicationChanged();

    void orderMedicationChanged();
};


#endif // MEDICATIONMODEL_H
