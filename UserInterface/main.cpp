#include <kms.h>
#include <kmslogic.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    kms w;
    w.show();
    return a.exec();
}
