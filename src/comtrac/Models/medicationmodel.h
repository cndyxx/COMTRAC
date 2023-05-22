
#ifndef MEDICATIONMODEL_H
#define MEDICATIONMODEL_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQueryModel>


#include "Controllers/medication.h"

class MedicationModel : public QSqlQueryModel
{
    Q_OBJECT
    Q_PROPERTY(QList<Medication *> medications READ medications WRITE setMedications NOTIFY medicationsChanged)


public:

    explicit MedicationModel(QObject *parent = nullptr);

    QList<Medication *> medications() const;
    void setMedications(const QList<Medication *> &newMedications);



private:

    //Medikamenten Liste

    //Daten aus Datenbank holen
    void getMedication();

    QList<Medication *> m_medications;




public slots:
    void updateModel();
    void addMedication(QString name, int intakePerDay, QList<QTime> intakeTimes, QTime reminderTime);


signals:
    void medicationChanged();
    void medicationsChanged();
};


#endif // MEDICATIONMODEL_H
