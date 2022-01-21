#include "kms.h"
#include "ui_kms.h"

kms::kms(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::kms)
{
    ui->setupUi(this);
}

kms::~kms()
{
    delete ui;
}

