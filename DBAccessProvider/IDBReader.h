#ifndef IDBREADER_H
#define IDBREADER_H

#include <ISqlTableList.h>

class IDBReader
{
public:
    virtual void readTableRecords(TABLE aTable) = 0;
};

#endif // IDBREADER_H
