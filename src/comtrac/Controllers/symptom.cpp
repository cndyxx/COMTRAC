
#include "symptom.h"




Symptom::Symptom(int id, QString name, QString intensity, int frequency, QString duration, QDate entryDate, QTime entryTime, QObject *parent)
    : QObject(parent), m_id(id),  m_name(name),  m_intensity(intensity), m_frequency(frequency), m_duration(duration), m_entryDate(entryDate), m_entryTime(entryTime)
{

}

int Symptom::id() const
{
    return m_id;
}

void Symptom::setId(int newId)
{
    if (m_id == newId)
        return;
    m_id = newId;
    emit idChanged();
}

QString Symptom::name() const
{
    return m_name;
}

void Symptom::setName(const QString &newName)
{
    if (m_name == newName)
        return;
    m_name = newName;
    emit nameChanged();
}

QString Symptom::intensity() const
{
    return m_intensity;
}

void Symptom::setIntensity(const QString &newIntensity)
{
    if (m_intensity == newIntensity)
        return;
    m_intensity = newIntensity;
    emit intensityChanged();
}

int Symptom::frequency() const
{
    return m_frequency;
}

void Symptom::setFrequency(int newFrequency)
{
    if (m_frequency == newFrequency)
        return;
    m_frequency = newFrequency;
    emit frequencyChanged();
}

QString Symptom::duration() const
{
    return m_duration;
}

void Symptom::setDuration(const QString &newDuration)
{
    if (m_duration == newDuration)
        return;
    m_duration = newDuration;
    emit durationChanged();
}

QDate Symptom::entryDate() const
{
    return m_entryDate;
}

void Symptom::setEntryDate(const QDate &newEntryDate)
{
    if (m_entryDate == newEntryDate)
        return;
    m_entryDate = newEntryDate;
    emit entryDateChanged();
}

QTime Symptom::entryTime() const
{
    return m_entryTime;
}

void Symptom::setEntryTime(const QTime &newEntryTime)
{
    if (m_entryTime == newEntryTime)
        return;
    m_entryTime = newEntryTime;
    emit entryTimeChanged();
}

