
#include "medication.h"


Medication::Medication(int id, QString name, int intakePerDay, QTime intakeTime, QTime reminderTime, QObject *parent)
    : QObject(parent), m_id(id),  m_name(name),  m_intakePerDay(intakePerDay), m_intakeTime(intakeTime), m_reminderTime(reminderTime)
{

}

void Medication::readMedication(QString medication)
{
    //Do something

}

void Medication::addMedication(QString name, int intakePerDay, QTime intakeTimes, QTime reminderTime)
{
    //Medikament in die Datenbank hinzufügen

}

QTime Medication::intakeTime() const
{
    return m_intakeTime;
}

void Medication::setIntakeTime(const QTime &newIntakeTime)
{
    if (m_intakeTime == newIntakeTime)
        return;
    m_intakeTime = newIntakeTime;
    emit intakeTimeChanged();
}

int Medication::intakePerDay() const
{
    return m_intakePerDay;
}

void Medication::setIntakePerDay(int newIntakePerDay)
{
    if (m_intakePerDay == newIntakePerDay)
        return;
    m_intakePerDay = newIntakePerDay;
    emit intakePerDayChanged();
}

QTime Medication::reminderTime() const
{
    return m_reminderTime;
}

void Medication::setReminderTime(const QTime &newReminderTime)
{
    if (m_reminderTime == newReminderTime)
        return;
    m_reminderTime = newReminderTime;
    emit reminderTimeChanged();
}


QString Medication::name() const
{
    return m_name;
}

void Medication::setName(const QString &newName)
{
    if (m_name == newName)
        return;
    m_name = newName;
    emit nameChanged();
}

