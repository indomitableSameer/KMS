#ifndef KMSLOGIC_H
#define KMSLOGIC_H

#include <IDataReceiver.h>
#include <IDBReader.h>
#include <IDBWriter.h>
#include <QObject>
#include <AlarmManager.h>
#include <AlarmPredictionLogic.h>
#include <NotificationGenerator.h>
#include <IUiData.h>
#include <IUnprocessedData.h>

class KMSLogic : public QObject
{

    Q_OBJECT
private:
    IDataReceiver* m_dataReceiver;
    IDBReader* m_db_reader;
    IDBWriter* m_db_writer;
    AlarmManager* m_alarmManager;
    AlarmPredictionLogic* m_predictionLogic;
    NotificationGenerator* m_notificationGenerator;

    int dataReceiverFailCounter;

    void initialize();
    void processor();

signals:
    void processedDataAvailable(IUiData aUiData);

public slots:
    void processDataReceiver();

public:
    KMSLogic();
    bool startProcessing();
    IUiData cancelAlarm();
};

#endif // KMSLOGIC_H
