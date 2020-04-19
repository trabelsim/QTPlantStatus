#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "connectdialog.h" // connectdialog zawiera okno do obsługi komunikacji z kontrolerem
#include <QSerialPortInfo>
#include <QSerialPort>
#include <QMessageBox>

#include <QDate>

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug() << "Did connect for test button work?" << connect(ui->test_button,SIGNAL(clicked()), this, SLOT(myCustomSlot()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_exit_button_clicked()
{
    qDebug() << "Exit button has been clicked \n Exiting the application";
}


void MainWindow::on_exit_button_pressed()
{
    qDebug() << "Exit button has been pressed \n Not exiting the application";
}


void MainWindow::on_connectButton_clicked()
{
    /*
     * W przypadku tworzenia drugiego okna w taki sposób, gdy już okno zostanie otwarte,
     * nie bedziemy w stanie powrócić do main window. Czyli cały program czeka na decyzje
     * wychodzącą z connect dialog.
     * */

//    ConnectDialog dialogWindow;
//    dialogWindow.setModal(true);
//    dialogWindow.exec();


    /* Drugi przypadek jest lepszy ze względu na możliwość dalszej pracy nad pierwszym oknem main window,
     * mimo że nie dokonaliśmy ostatecznej decyzji w oknie dialog. */

    secondConnectionWindow = new ConnectDialog(this);
    secondConnectionWindow->show();
    if(secondConnectionWindow){
        qInfo() << "Otwarto nowe okno";
            ui->main_text->append("New connection in progress..");
    }
}



//void ConnectDialog::readFromPort()
//{
//    while(this->device->canReadLine()){
//          QString line = this->device->readAll();
//          qDebug() << line;
//          QString terminator = "\r";
//          int pos = line.lastIndexOf(terminator);
//          qDebug() << line.left(pos);
//          this->addToLogs(line.left(pos));
//    }
//}

//if(secondConnectionWindow){
//        ui->main_text->append("New connection in progress..");
//        if(secondConnectionWindow->deviceSetUp == true){
//            ui->main_text->append("Connected");
//        }else if(secondConnectionWindow->deviceSetUp == false){
//            ui->main_text->append("Not Connected");
//        }

//}

void MainWindow::on_actionConnect_triggered()
{
    QMessageBox::information(this,"title","New Information");
}


void MainWindow::on_test_button_clicked()
{
    secondConnectionWindow->device->setPortName(secondConnectionWindow->give_device_name());
    secondConnectionWindow->device->open(QSerialPort::ReadOnly);
    secondConnectionWindow->device->setBaudRate(QSerialPort::Baud115200);
    secondConnectionWindow->device->setDataBits(QSerialPort::Data8);
    secondConnectionWindow->device->setParity(QSerialPort::NoParity);
    secondConnectionWindow->device->setStopBits(QSerialPort::OneStop);
    secondConnectionWindow->device->setFlowControl(QSerialPort::NoFlowControl);
    connect(secondConnectionWindow->device, SIGNAL(readyRead()) , this, SLOT(secondConnectionWindow->readFromPort()));

    if(secondConnectionWindow->device->canReadLine()){
        QString data = secondConnectionWindow->readFromPort();
        QString currentDateTime = QDateTime::currentDateTime().toString("yyyy.MM.dd hh:mm:ss");
        ui->main_text->append(currentDateTime + "\t" + data);
    }else{
        ui->main_text->append("Could not read data.");
        return;
    }
}
