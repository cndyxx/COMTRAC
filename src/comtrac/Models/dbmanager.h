
#ifndef DBMANAGER_H
#define DBMANAGER_H


#include <QSqlDatabase>
#include <QDebug>


class DbManager
{
public:
    DbManager();
    static DbManager* holeInstanz();

private:
    QSqlDatabase m_db;
    static bool instanceFlag;
    static DbManager* instanz;

};

#endif // DBMANAGER_H
