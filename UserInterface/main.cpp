#include <kms.h>
#include <KmsLogic.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    KMSLogic* logic = new KMSLogic();
    kms* w = new kms(logic);
    KMSLogic::connect(logic, &KMSLogic::processedDataAvailable, w, &kms::DisplayProcessedData);
    logic->startProcessing();
    w->show();
    w->showNotification("initalization done.");
    return a.exec();
}
