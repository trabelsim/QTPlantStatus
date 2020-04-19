#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "connectdialog.h" // connectdialog zawiera okno do obsługi komunikacji z kontrolerem
#include <QSerialPortInfo>


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


void MainWindow::myCustomSlot(){
    qDebug() << "Test button pushed";
}

int MainWindow::on_connectButton_clicked()
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
    return 1;
}

void MainWindow::get_device_name()
{
    if(on_connectButton_clicked()){
        qInfo() << "Otwarto nowe okno";
        if(secondConnectionWindow){
            ui->main_text->append("New connection in progress..");
            if(secondConnectionWindow->device->open(QSerialPort::ReadOnly) && secondConnectionWindow->device_name != ""){
                ui->main_text->append(secondConnectionWindow->device_name);
                qDebug() << " hola hola " << secondConnectionWindow->device_name;
            }
        }
    }
    return;
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
