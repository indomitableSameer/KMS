#include "DBAccessProvider.h"
#include <QSqlDatabase>
#include <ISqlTableList.h>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

CDBAccessProvider::CDBAccessProvider()
{
        QSqlDatabase dbtmp = QSqlDatabase::addDatabase("QSQLITE");
        db = new QSqlDatabase(dbtmp);
        // TODO : need to set proper location
        db->setDatabaseName("E:\\QtLearning\\KMS_T\\kml.db");
}

bool CDBAccessProvider::openDB()
{
    return db->open();
}

bool CDBAccessProvider::isDBOpen()
{
    return db->isOpen();
}

void CDBAccessProvider::close()
{
    return db->close();
}

bool CDBAccessProvider::WriteToDatabase(TABLE aTableName, ...)
{
    va_list args;
    va_start(args, aTableName);

    if(aTableName == TABLE::SO2_LEVEL)
    {
        QString so2Value;
        QString prepareQuery = "insert into so2_level (date, time, value) VALUES (strftime('%Y-%m-%d', 'now'), strftime('%H:%M:%S','now')," + so2Value +")";
        if(!db->open())
        {
            qInfo() << "ERROR : Opening database failed.";
            return false;
        }

        QSqlQuery query(prepareQuery);
        bool ret = query.exec();

        if(!ret)
        {
            // Error while running query, log error
            qInfo() << "ERROR :" << query.lastError();
        }

        db->close();
        return ret;
    }

    if(aTableName == TABLE::ALARM_DATA)
    {

    }

    if(aTableName == TABLE::NOTIFICATION_DATA)
    {

    }
}

void CDBAccessProvider::readTableRecords(TABLE aTable)
{

}
