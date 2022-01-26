#ifndef CDBACCESSPROVIDER_H
#define CDBACCESSPROVIDER_H

#include <QObject>
#include <IDBWriter.h>
#include <QSqlDatabase>
#include <IDBReader.h>
#include <ISqlTableList.h>

class CDBAccessProvider : public QObject, public IDBWriter, public IDBReader
{
    Q_OBJECT
    QSqlDatabase *db;
    bool openDB();
    bool isDBOpen();
    void close();
public:
    CDBAccessProvider();
    virtual ~CDBAccessProvider() {}
    bool WriteToDatabase(TABLE aTableName, ...);
    void readTableRecords(TABLE aTable);
};

#endif // CDBACCESSPROVIDER_H
