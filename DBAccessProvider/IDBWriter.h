#ifndef IDBWRITER_H
#define IDBWRITER_H

#include <ISqlTableList.h>
#include <QString>

class IDBWriter
{
public:
    virtual bool WriteSo2LevelToDB(int aSo2Value) = 0;
    virtual bool WriteAlarmDataToDB(int alarm) = 0;
    virtual bool WriteNotificationDataToDB(QString aNotificationMsg) = 0;
};

#endif // IDBWRITER_H
