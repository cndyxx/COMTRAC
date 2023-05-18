
#ifndef MEDICATIONMODEL_H
#define MEDICATIONMODEL_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQueryModel>




class MedicationModel : public QSqlQueryModel
{
    Q_OBJECT

    enum Roles {
        idRole = Qt::UserRole + 1,  // id
        nameRole,                   //Medication name
        intakePerDayRole,
        intakeTimesRole,
        reminderTimeRole
    };

public:

    explicit MedicationModel(QObject *parent = nullptr);




    void refresh();

    QVariant data(const QModelIndex &index, int role) const;

protected:
    /* hashed table of roles for speakers.
     * The method used in the wilds of the base class QAbstractItemModel,
     * from which inherits the class QSqlQueryModel
     * */
    QHash<int, QByteArray> roleNames() const;

private:

public slots:
    void updateModel();
    int getId(int row);
    void addMedication(QString name, int intakePerDay, QList<QTime> intakeTimes, QTime reminderTime);


};


#endif // MEDICATIONMODEL_H
