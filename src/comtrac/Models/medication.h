
#ifndef MEDICATION_H
#define MEDICATION_H


#include <QObject>
#include <QVector>
#include <QTime>
#include "intaketime.h"



//Delegate Klasse
class Medication : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int id READ id WRITE setId NOTIFY idChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(int intakePerDay READ intakePerDay WRITE setIntakePerDay NOTIFY intakePerDayChanged)
    Q_PROPERTY(QList<QTime> intakeTime READ intakeTime WRITE setIntakeTime NOTIFY intakeTimeChanged)
    Q_PROPERTY(QString reminderTime READ reminderTime WRITE setReminderTime NOTIFY reminderTimeChanged)


public:
    explicit Medication(int id, QString name, int intakePerDay, QList<QTime> intakeTime, QString reminderTime, QObject *parent = nullptr);

    QString name() const;
    void setName(const QString &newName);

    int intakePerDay() const;
    void setIntakePerDay(int newIntakePerDay);


    QList<QTime> intakeTime() const;

    void setIntakeTime(QTime time, int index);
    void initializeIntakeTimeList();

    int id() const;
    void setId(int newId);

    QString reminderTime() const;
    void setReminderTime(const QString &newReminderTime);

signals:
    //Ein neues Medikament wurde hinzugefügt
    void medicationAdded();

    //Ein Medikament wurde entfernt
    void medicationRemoved();

    //Ein Medikament wurde bearbeitet
    void medicationUpdated();

    void nameChanged();

    void intakePerDayChanged();


    void intakeTimeChanged();

    void idChanged();

    void reminderTimeChanged();

public slots:
    void readMedication(QString medication);

    void addMedication(QString name, int intakePerDay, QList<QTime> intakeTimes, QTime reminderTime);

    void setIntakeTime(const QList<QTime> &newIntakeTime);
private:
    int m_id;
    QString m_name;
    int m_intakePerDay;
    QList<QTime> m_intakeTime;
    QString m_reminderTime;








};

#endif // MEDICATION_H
