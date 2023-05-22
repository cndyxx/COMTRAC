
#ifndef MEDICATION_H
#define MEDICATION_H


#include <QObject>
#include <QVector>
#include <QTime>



//Delegate Klasse
class Medication : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(int intakePerDay READ intakePerDay WRITE setIntakePerDay NOTIFY intakePerDayChanged)
    Q_PROPERTY(QTime intakeTime READ intakeTime WRITE setIntakeTime NOTIFY intakeTimeChanged)
    Q_PROPERTY(QTime reminderTime READ reminderTime WRITE setReminderTime NOTIFY reminderTimeChanged)


public:
    explicit Medication(int id, QString name, int intakePerDay, QTime intakeTime, QTime reminderTime, QObject *parent = nullptr);

    QString name() const;
    void setName(const QString &newName);

    QTime reminderTime() const;
    void setReminderTime(const QTime &newReminderTime);

    int intakePerDay() const;
    void setIntakePerDay(int newIntakePerDay);

    QTime intakeTime() const;
    void setIntakeTime(const QTime &newIntakeTime);

signals:
    //Ein neues Medikament wurde hinzugefügt
    void medicationAdded();

    //Ein Medikament wurde entfernt
    void medicationRemoved();

    //Ein Medikament wurde bearbeitet
    void medicationUpdated();



    void nameChanged();

    void reminderTimeChanged();

    void intakePerDayChanged();

    void intakeTimeChanged();

public slots:
    void readMedication(QString medication);

    void addMedication(QString name, int intakePerDay, QTime intakeTimes, QTime reminderTime);

private:
    int m_id;
    QString m_name;
    int m_intakePerDay;
    QTime m_intakeTime;
    QTime m_reminderTime;



};

#endif // MEDICATION_H
