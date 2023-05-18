
#include "medication.h"


Medication::Medication(QObject *parent)
    : QObject{parent}
{

}

void Medication::readMedication(QString medication)
{
    //Do something

}

void Medication::addMedication(QString name, int intakePerDay, QList<QTime> intakeTimes, QTime reminderTime)
{
    //Medikament in die Datenbank hinzufügen
    medModel.addMedication(name, intakePerDay,intakeTimes,reminderTime);
}
