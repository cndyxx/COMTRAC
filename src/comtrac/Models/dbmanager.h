
#ifndef DBMANAGER_H
#define DBMANAGER_H


#include <QSqlDatabase>
#include <QDebug>


class DbManager
{
public:
    DbManager();

private:
    QSqlDatabase m_db;

};

#endif // DBMANAGER_H
