
#ifndef MEDICATION_H
#define MEDICATION_H


#include <QObject>
#include <QVector>
#include <QTime>

#include "Models/medicationmodel.h"

//Delegate Klasse
class Medication : public QObject
{
    Q_OBJECT
public:
    explicit Medication(QObject *parent = nullptr);

signals:
    //Ein neues Medikament wurde hinzugefügt
    void medicationAdded();

    //Ein Medikament wurde entfernt
    void medicationRemoved();

    //Ein Medikament wurde bearbeitet
    void medicationUpdated();


public slots:
    void readMedication(QString medication);

    void addMedication(QString name, int intakePerDay, QList<QTime> intakeTimes, QTime reminderTime);

private:
    MedicationModel medModel;
};

#endif // MEDICATION_H
