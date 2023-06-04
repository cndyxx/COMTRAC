
#ifndef SYMPTOMMODEL_H
#define SYMPTOMMODEL_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QTime>
#include <QDebug>
#include <QSqlQueryModel>
#include <QDateTime>
#include <QSqlError>
#include <iostream>
#include "Models/Symptom.h"

class SymptomModel : public QSqlQueryModel
{
    Q_OBJECT
    Q_PROPERTY(QList<Symptom *> symptoms READ symptoms WRITE setSymptoms NOTIFY symptomsChanged)
    Q_PROPERTY(Symptom *singleSymptom READ singleSymptom WRITE setSingleSymptom NOTIFY singleSymptomChanged)
    Q_PROPERTY(QList<Symptom *> daySymptoms READ daySymptoms WRITE setDaySymptoms NOTIFY daySymptomsChanged)
    Q_PROPERTY(QList<QDate> symptomsOfMonth READ symptomsOfMonth WRITE setSymptomsOfMonth NOTIFY symptomsOfMonthChanged)

public:
    explicit SymptomModel(QObject *parent = nullptr);
    SymptomModel(const QList<Symptom *> &symptoms, int currentSymptom, Symptom *singleSymptom, const QList<Symptom *> &daySymptoms, const QList<Symptom *> &weekSymptoms);

     ~SymptomModel();

    QList<Symptom *> symptoms() const;
    void setSymptoms(const QList<Symptom *> &newSymptom);

    Symptom *singleSymptom() const;


    QList<Symptom *> daySymptoms() const;
    void setDaySymptoms(const QList<Symptom *> &newDaySymptoms);

    QList<QDate> symptomsOfMonth() const;
    void setSymptomsOfMonth(const QList<QDate> &newSymptomsOfMonth);

signals:
    void symptomsChanged();

    void singleSymptomChanged();

    void daySymptomsChanged();

    void symptomsOfMonthChanged();

public slots:

    void deleteSymptom();

    void updateSymptom(QString name, QString intensity, int frequency, QString duration);

    //alle Symptomeinträge eines bestimmten Monats aus der Datenbank holen
    void getEntryDates(QString month);

    //Prüfe, ob der Übergabewert (Datum) in der Liste vorhanden ist
    bool findDate(QString date);

    void getSymptoms();
    void setSymptoms(QString name, QString intensity, int frequency, QString duration, QString entryDate, QString entryTime);
    void setSingleSymptom(Symptom *newSingleSymptom);

    void getSymptomsOfDate(QString entryDate);

private:
    void updateModel();
    QList<Symptom*> m_symptoms; //Liste von allen Symptomen in der Datenbank
    int currentSymptom;
    Symptom *m_singleSymptom; //Einzelnes Symptom
    QList<Symptom *> m_daySymptoms; //Liste von Symptomen für einen Tag
    QList<Symptom *> m_weekSymptoms; //Liste von Symptomen für eine Kalenderwoche
    QList<QDate> m_symptomsOfMonth;


    int addSymptom(QString name, QString intensity, int frequency, QString duration, QDate entryDate, QTime entryTime);




};

#endif // SYMPTOMMODEL_H
