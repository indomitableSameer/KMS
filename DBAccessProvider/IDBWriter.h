#ifndef IDBWRITER_H
#define IDBWRITER_H

#include <ISqlTableList.h>

class IDBWriter
{
public:
    virtual bool WriteToDatabase(TABLE aTableName, ...) = 0;
};

#endif // IDBWRITER_H
