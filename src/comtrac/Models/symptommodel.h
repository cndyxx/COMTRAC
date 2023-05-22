
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
#include "Controllers/Symptom.h"

class SymptomModel : public QSqlQueryModel
{
    Q_OBJECT
     Q_PROPERTY(QList<Symptom *> symptoms READ symptoms WRITE setSymptoms NOTIFY symptomsChanged)

public:
    explicit SymptomModel(QObject *parent = nullptr);

    void addSymptom(const QString& name, const QString& intensity,const int& frequency, const QString& duration);

    QList<Symptom *> symptoms() const;
    void setSymptoms(const QList<Symptom *> &newSymptoms);

    void getSymptoms();

signals:
    void symptomsChanged();

private:
    void updateModel();
    QList<Symptom*> m_symptoms;


};

#endif // SYMPTOMMODEL_H
