#include "medicationmodel.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QTime>
#include <QDebug>
#include "dbmanager.h"



MedicationModel::MedicationModel(QObject *parent) : QSqlQueryModel(parent)
{
    getMedication();
    QTime intakeTime(11,0);
    QTime reminderTime(11,0);
    m_medications.push_back(new Medication(1, "Asperin 1", 2, intakeTime, reminderTime, this));
    m_medications.push_back(new Medication(1, "Asperin 2", 2, intakeTime, reminderTime, this));
    m_medications.push_back(new Medication(1, "Asperin 3", 2, intakeTime, reminderTime, this));

    //    m_users.append(new User(2, "Novak", "Djokovic", "https://pbs.twimg.com/profile_images/1219965365226065920/EBF8Rd9v_400x400.jpg", this));
    //    m_users.append(new User(3, "Elon", "Musk", "https://upload.wikimedia.org/wikipedia/commons/thumb/3/34/Elon_Musk_Royal_Society_%28crop2%29.jpg/1200px-Elon_Musk_Royal_Society_%28crop2%29.jpg", this));
    //    m_users.append(new User(4, "Felix", "Kjellberg", "https://staticg.sportskeeda.com/editor/2021/08/b701f-16294304565102-800.jpg", this));
    //    m_users.append(new User(5, "Mom", "", "", this));
    //    m_users.append(new User(6, "Leonardo", "DiCaprio", "https://assets.weforum.org/sf_account/image/GpsMwgoVb5muWo9s5p8Z4XjTRfGnvtUtmQTqJ7dYEJA.jpg", this));
    //    m_users.append(new User(7, "Alexis", "Ren",  "https://media.glamour.com/photos/6165d7aa4beb8802a4c2d7ea/master/pass/unnamed%20(6).jpeg", this));
}


void MedicationModel::getMedication()
{
    QSqlDatabase db;
    const QString DRIVER("QSQLITE");
    if(QSqlDatabase::isDriverAvailable(DRIVER)){
        qDebug("Driver disponible");
        db = QSqlDatabase::addDatabase(DRIVER);
        db.setDatabaseName("C:\\Users\\cindy\\Documents\\GitHub\\COMTRAC\\database\\dbComtrac");
    }
    else {
        qDebug() << "false";
    }
//    QString path= "C:/Users/cindy/Documents/GitHub/COMTRAC/database/dbComtrac";
//    QSqlDatabase m_db = QSqlDatabase::addDatabase("QSQLITE");
//    m_db.setDatabaseName(path);
//    m_db.open();
    if (!db.open())
    {

        qDebug() <<"Datenbank konnte nicht geöffnet werden";
    }
    else
    {
        qDebug() << "Database: connection ok";
    }
    QSqlQuery query;
    query.prepare("SELECT * FROM Medications");
    if(query.exec()){
        while(query.next()){
            int id = query.value(0).toInt();
            QString name = query.value(1).toString();
            int intakePerDay = query.value(2).toInt();
            QTime intakeTime = query.value(3).toTime();
            QTime reminderTime = query.value(4).toTime();
            m_medications.push_back(new Medication(id, name, intakePerDay, intakeTime, reminderTime, this));
            qDebug() << "TEST: " << name ;
        }
    } else {
        qDebug() << "Fehler bei der Ausführung der Abfrage:" << query.lastError().text();
    }


}

QList<Medication *> MedicationModel::medications() const
{
    return m_medications;
}

void MedicationModel::setMedications(const QList<Medication *> &newMedications)
{
    if (m_medications == newMedications)
        return;
    m_medications = newMedications;
    emit medicationsChanged();
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


