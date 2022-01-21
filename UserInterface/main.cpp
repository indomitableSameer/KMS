#include "kms.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    kms k;
    kms w;
    w.show();
    return a.exec();
}
