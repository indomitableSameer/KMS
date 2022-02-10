#include "kms.h"
#include "ui_kms.h"

QString kms::widgetStyle = "";

kms::kms(KMSLogic* logic, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::kms)
{
    m_logic = logic;

    ui->setupUi(this);

    ui->listWidget->insertItem(0, "initializing..");

    series = new QLineSeries();
    *series << QPointF(0 ,0);

    chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->setTitle("SO2 PPM vs Time");

    QCategoryAxis *axisX = new QCategoryAxis();
    QCategoryAxis *axisY = new QCategoryAxis();

    // Customize grid lines and shades
    axisX->setGridLineVisible(false);
    axisY->setGridLineVisible(false);
    axisY->setShadesPen(Qt::NoPen);
    axisY->setShadesBrush(QBrush(QColor("yellow")));

    axisX->append( "5 min", 5);
    axisX->append("10 min", 10);
    axisX->append("15 min", 15);
    axisX->append("20 min", 20);
    axisX->append("25 min", 25);
    axisX->append("30 min", 30);
    axisX->append("35 min", 35);
    axisX->append("40 min", 40);
    axisX->append("45 min", 45);
    axisX->append("50 min", 50);
    axisX->append("55 min", 55);
    axisX->append("60 min", 60);
    axisX->setRange(0, 60);


    axisY->append("0 PPM", 0);
    axisY->append("5k PPM", 5000);
    axisY->append("10k PPM", 10000);
    axisY->append("15k PPM", 15000);
    axisY->append("20k PPM", 20000);
    axisY->append("25k PPM", 25000);
    axisY->setRange(0, 25000);

    chart->addAxis(axisX, Qt::AlignBottom);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisX);
    series->attachAxis(axisY);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);


    QVBoxLayout *layout = new QVBoxLayout(ui->chartframe);
    layout->addWidget(chartView);

    lcd = new QLCDNumber;
    lcd->display(0);

    QVBoxLayout *layoutLCD = new QVBoxLayout(ui->lcdframe);
    layoutLCD->addWidget(lcd);

    ui->lineEdit->setEchoMode(QLineEdit::Password);
    widgetStyle = ui->frame->styleSheet();
}

void kms::showNotification(QString aMsg)
{
    ui->listWidget->insertItem(0, aMsg);
}

kms::~kms()
{
    delete ui;
}

/*
 * Hazard id : _H10.1_distinctive_state_
*/
void kms::DisplayProcessedData(IUiData aUiData)
{
    try
    {
        static QString style;
        *series << QPointF(aUiData.getDateTime().time().minute(), aUiData.getSo2Ppm());
        //*series << QPointF(i++, aUiData.getSo2Ppm());
        lcd->display(aUiData.getSo2Ppm());

        if(aUiData.getAlarm() == IAlarmType::RED)
        {
            ui->listWidget->insertItem(0, aUiData.getNotificationMsg());
            ui->frame->setStyleSheet("background-color: red");
        }
        else if(aUiData.getAlarm() == IAlarmType::YELLOW)
        {
            ui->listWidget->insertItem(0, aUiData.getNotificationMsg());
            ui->frame->setStyleSheet("background-color: yellow");
        }
        else
        {
            QString msg = aUiData.getNotificationMsg();
            if(!msg.isNull() && !msg.isEmpty())
            {
                ui->listWidget->insertItem(0, aUiData.getNotificationMsg());
            }
            ui->frame->setStyleSheet(style);
        }
    }
    catch(std::exception &ex)
    {
        qDebug() << "Exception : " << ex.what();
        ui->listWidget->insertItem(0, ex.what());
    }
}

/*
 * Hazard id : _H11.1_authorised_alarm_cancel_
*/
void kms::on_pushButton_clicked()
{
    if(ui->lineEdit->text()=="1234"){
        qDebug() << "Alarm Cancelled";
        IUiData aDate = m_logic->cancelAlarm();
        ui->listWidget->insertItem(0, aDate.getNotificationMsg());
    }
    ui->lineEdit->clear();
}
