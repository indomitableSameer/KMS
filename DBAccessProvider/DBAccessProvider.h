#ifndef CDBACCESSPROVIDER_H
#define CDBACCESSPROVIDER_H

class CDBAccessProvider
{
public:
    bool isDBOpen();
    bool close();
    CDBAccessProvider();
};

#endif // CDBACCESSPROVIDER_H
