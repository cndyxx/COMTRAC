
#ifndef SYMPTOM_H
#define SYMPTOM_H

#include <QObject>
#include <QVector>
#include <QTime>



class Symptom  : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int id READ id CONSTANT)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString intensity READ intensity WRITE setIntensity NOTIFY intensityChanged)
    Q_PROPERTY(int frequency READ frequency WRITE setFrequency NOTIFY frequencyChanged)
    Q_PROPERTY(QString duration READ duration WRITE setDuration NOTIFY durationChanged)
    Q_PROPERTY(QDate entryDate READ entryDate WRITE setEntryDate NOTIFY entryDateChanged)
    Q_PROPERTY(QTime entryTime READ entryTime WRITE setEntryTime NOTIFY entryTimeChanged)

public:
    explicit Symptom(int id, QString name, QString intensity, int frequency, QString duration, QDate entryDate, QTime entryTime, QObject *parent = nullptr);



    QString name() const;
    void setName(const QString &newName);

    QString intensity() const;
    void setIntensity(const QString &newIntensity);

    int frequency() const;
    void setFrequency(int newFrequency);

    QString duration() const;
    void setDuration(const QString &newDuration);

    QDate entryDate() const;
    void setEntryDate(const QDate &newEntryDate);

    QTime entryTime() const;
    void setEntryTime(const QTime &newEntryTime);



    int id() const;

signals:


    void nameChanged();

    void intensityChanged();

    void frequencyChanged();

    void durationChanged();

    void entryDateChanged();

    void entryTimeChanged();

private:

    int m_id;
    QString m_name;
    QString m_intensity;
    int m_frequency;
    QString m_duration;
    QDate m_entryDate;
    QTime m_entryTime;




};

#endif // SYMPTOM_H
