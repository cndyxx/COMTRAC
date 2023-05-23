
#include "Dbmanager.h"

bool DbManager::instanceFlag = false;
DbManager *DbManager::instanz = NULL;


DbManager::DbManager()
{
    QString path= "../comtrac/database/dbComtrac.db";
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(path);
    m_db.open();

    if (!m_db.open())
    {

        qDebug() <<"Datenbank konnte nicht geöffnet werden";
    }
    else
    {
        qDebug() << "Database: connection ok";
    }
}




DbManager* DbManager::holeInstanz()
{
    if(!instanceFlag){
        instanz = new DbManager();
        instanceFlag = true;
        return instanz;
    } else {
        return instanz;
    }

}

