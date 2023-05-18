#include "medicationmodel.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QTime>



MedicationModel::MedicationModel(QObject *parent) : QSqlQueryModel(parent)
{
    this->updateModel();
}

// Methode zum Abrufen von Daten aus dem Modell
QVariant MedicationModel::data(const QModelIndex &index, int role) const
{
    // Define the column number, on the role of number
    int columnId = role - Qt::UserRole - 1;
    // Create the index using a column ID
    QModelIndex modelIndex = this->index(index.row(), columnId);

    return QSqlQueryModel::data(modelIndex, Qt::DisplayRole);
}


QHash<int, QByteArray> MedicationModel::roleNames() const {

    QHash<int, QByteArray> roles;
    roles[idRole] = "id";
    roles[nameRole] = "name";
    roles[intakePerDayRole] = "intakePerDay";
    roles[intakeTimesRole] = "intakeTimes";
    roles[reminderTimeRole] = "reminderTime";
    return roles;
}


void MedicationModel::addMedication(QString name,int intakePerDay,QList<QTime> intakeTimes, QTime reminderTime)
{
    QString intakeTimesString;
    for(int i = 0; i < intakePerDay; i++){
        intakeTimesString  += intakeTimes[i].toString("hh:mm") + ",";
    }
    intakeTimesString.chop(1); // Entferne das letzte Komma

    QSqlQuery query;
    query.prepare("INSERT INTO medications (name, intakePerDay, intakeTimes, reminderTime) VALUES (?, ?, ?, ?)");
    query.bindValue(0, name);
    query.bindValue(1, intakePerDay);
    query.bindValue(2, intakeTimesString);
    query.bindValue(3, reminderTime);
    query.exec();
    updateModel();
}


//Medikationsplan updaten
void MedicationModel::updateModel()
{
    //Daten aus Datenbank holen -> SELECT
    // The update is performed SQL-queries to the database
    this->setQuery("SELECT id, name, intakePerDay, intakeTimes, reminderTime FROM Symptoms");
}

// Getting the id of the row in the data view model
int MedicationModel::getId(int row)
{
    return this->data(this->index(row, 0), idRole).toInt();
}
