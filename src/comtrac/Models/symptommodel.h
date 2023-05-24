
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
#include "Controllers/Symptom.h"

class SymptomModel : public QSqlQueryModel
{
    Q_OBJECT
    Q_PROPERTY(QList<Symptom *> symptoms READ symptoms WRITE setSymptoms NOTIFY symptomsChanged)
    Q_PROPERTY(Symptom *singleSymptom READ singleSymptom WRITE setSingleSymptom NOTIFY singleSymptomChanged)

public:
    explicit SymptomModel(QObject *parent = nullptr);



    QList<Symptom *> symptoms() const;
    void setSymptoms(const QList<Symptom *> &newSymptoms);

    void getSymptoms();

    Symptom *singleSymptom() const;
    void setSingleSymptom(Symptom *newSingleSymptom);

signals:
    void symptomsChanged();

    void singleSymptomChanged();

public slots:
    void addSymptom(const QString& name, const QString& intensity,const int& frequency, const QString& duration, QString entryDate, QString entryTime);
    void setCurrentSymptom(int id);
    int getCurrentSymptom();
    void setSymptom(int id);

private:
    void updateModel();
    QList<Symptom*> m_symptoms;
    int currentSymptom;
    Symptom *m_singleSymptom;



};

#endif // SYMPTOMMODEL_H
