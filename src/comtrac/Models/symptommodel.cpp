
#include "symptommodel.h"


SymptomModel::SymptomModel(QObject *parent) : QSqlQueryModel(parent)
{
}

void SymptomModel::addSymptom(const QString &name, const QString &intensity,const int& frequency, const QString &duration)
{
    QDateTime currentDateTime = QDateTime::currentDateTime();
    QString entryDate = currentDateTime.date().toString(Qt::ISODate);
    QString entryTime = currentDateTime.time().toString(Qt::ISODateWithMs);

    QSqlQuery query;
    query.prepare("INSERT INTO symptoms (name, intensity, frequency, duration, entry_date, entry_time) "
                  "VALUES (:name, :intensity, :frequency, :duration, :entry_date, :entry_time)");
    query.bindValue(":name", name);
    query.bindValue(":intensity", intensity);
    query.bindValue(":frequency", frequency);
    query.bindValue(":duration", duration);
    query.bindValue(":entry_date", entryDate);
    query.bindValue(":entry_time", entryTime);
    query.exec();

    updateModel();
}

void SymptomModel::updateModel()
{
    //Daten holen -> SELECT

    // Aktualisiere die ListView im QML
    emit layoutChanged();
}

