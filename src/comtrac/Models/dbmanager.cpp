
#include "Dbmanager.h"

DbManager::DbManager()
{
    QString path= "C:/Users/cindy/Documents/GitHub/COMTRAC/database/dbComtrac";
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(path);

    if (!m_db.open())
    {
        qDebug() << "Error: connection with database failed";
    }
    else
    {
        qDebug() << "Database: connection ok";
    }
}

