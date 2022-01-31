#ifndef KMSLOGIC_H
#define KMSLOGIC_H

#include <kmsresponse.h>
#include <IDataReceiver.h>
#include <IDBReader.h>
#include <IDBWriter.h>
#include <QObject>

class KMSLogic : public QObject
{

Q_OBJECT

private:
    IDataReceiver* m_dataReceiver;
    IDBReader* m_db_reader;
    IDBWriter* m_db_writer;
    void initialize();

signals:
        void kmssignal();
public slots:
        KmsResponse kmsQueueData();
        void processDataReceiver(int so2ppm);
public:
    KMSLogic();
    void kmsLogicFunction(double ppmLevel);
    void KmsDataReceiverFunction();
    bool startProcessing();
};

#endif // KMSLOGIC_H
