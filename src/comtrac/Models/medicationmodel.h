
#ifndef MEDICATIONMODEL_H
#define MEDICATIONMODEL_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQueryModel>


#include "Models/medication.h"

class MedicationModel : public QSqlQueryModel
{
    Q_OBJECT
    Q_PROPERTY(QList<Medication *> medications READ medications WRITE setMedications NOTIFY medicationsChanged)
    Q_PROPERTY(Medication *singleMedication READ singleMedication WRITE setSingleMedication NOTIFY singleMedicationChanged)


public:

    explicit MedicationModel(QObject *parent = nullptr);
    ~MedicationModel();
    QList<Medication *> medications() const;
    void setMedications(const QList<Medication *> &newMedications);



    Medication *singleMedication() const;


private:

    //Medikamenten Liste

    //Daten aus Datenbank holen
    void getMedication();
    void addIntakeTime(int medicationID, QList<QTime> intakeTimes);
    void addMedicationIntake(int medicationID, int intakeID);
    QList<Medication *> m_medications;
    Medication * m_singleMedication;


public slots:

    void addMedication(QString name, int intakePerDay, QList<QTime> intakeTimes, QString reminderTime);
    void setSingleMedication(Medication *newSingleMedication);
    void setIntakeTime(QString time, int index);
    void initializeIntakeTimeList(int size);
    void deleteMedication();
    void updateMedication(QString name, int intakePerDay, QList<QTime> intakeTimes, QString reminderTime);

signals:
    void medicationChanged();
    void medicationsChanged();
    void singleMedicationChanged();
};


#endif // MEDICATIONMODEL_H
