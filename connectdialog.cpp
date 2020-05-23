#include "connectdialog.h"
#include "ui_connectdialog.h"
<<<<<<< HEAD

=======
>>>>>>> e1a18cf145c2204eaae565638cb0d50a38580484
#include <QDebug>
// Lista która przekazuje znalezione urządzenia
#include <QList>
// Biblioteka za której możemy użyć funkcji "availablePorts()
#include <QtSerialPort>

// posiada niezbedną funkcje currentDateTime do obsługi logów
#include <QDateTime>


<<<<<<< HEAD
=======

>>>>>>> e1a18cf145c2204eaae565638cb0d50a38580484
ConnectDialog::ConnectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConnectDialog)
{
    ui->setupUi(this);
    // konstruktor urządzenia oraz automatyczne jego usuwanie w przypadku destrukcji
    // Sprawdź czy ten wskaźnik będzie jeszcze istniał w przypadku zamknięcia samego okna dialog, ponieważ musimy wciąż
    // mieć dostęp do urządzenia po podłączeniu
<<<<<<< HEAD
    this->device = new QSerialPort();
    valConn = false;
=======
    this->device = new QSerialPort(this);
>>>>>>> e1a18cf145c2204eaae565638cb0d50a38580484
}

ConnectDialog::~ConnectDialog()
{
<<<<<<< HEAD
=======

>>>>>>> e1a18cf145c2204eaae565638cb0d50a38580484
    delete ui;
}


<<<<<<< HEAD
=======


>>>>>>> e1a18cf145c2204eaae565638cb0d50a38580484
void ConnectDialog::on_scanButton_clicked()
{
    // Utworzenie listy devices w której zostaną umieszczone urządzenia
    QList<QSerialPortInfo> devices;
    this->addToLogs("Searching for devices..");
    // Urządzenie znalezione przez funckję availablePorts() przechowujemy w zmiennej devices
    devices = QSerialPortInfo::availablePorts();

    // index urządzenia
    int index = 0;
    // Jeśli ilość urządzeń -1 jest większa od indeksu
    if((devices.count() - 1) >= index){
        // Dla każdego urządzenia qDebug nazwę portu oraz opis urządzenia
        for (int i=0; i <devices.count(); i++){
            this->addToLogs("Device found : " + devices.at(i).portName() + devices.at(i).description());
            ui->comboBoxDevices->addItem(devices.at(i).portName() + " " + devices.at(i).description());
<<<<<<< HEAD
=======
            //            append(devices.at(i).portName() + " " + devices.at(i).description());
>>>>>>> e1a18cf145c2204eaae565638cb0d50a38580484
        }

    }else{
        this->addToLogs("No device found.");
        ui->comboBoxDevices->clear();
    }


}

void ConnectDialog::addToLogs(QString message)
{
    QString currentDateTime = QDateTime::currentDateTime().toString("yyyy.MM.dd hh:mm:ss");
    ui->textEdit->append(currentDateTime + "\t" + message);
}

void ConnectDialog::on_connectButton_clicked()
{
    // Przed połączeniem sprawdzamy czy jakieś urządzenie zostało wykryte
    if(ui->comboBoxDevices->count() == 0){
        this->addToLogs("Not able to connect to a device which has not been found");
        return;
    }

    // Przechowywujemy jedynie numer portu do zmiennej portName rozdzielając całość tekstu za pomocą .split() oraz .first()'em otrzymujemy tylko pierwszy wynik
    QString portName = ui->comboBoxDevices->currentText().split(" ").first();
<<<<<<< HEAD
    device_num = {portName};
    this->addToLogs("Connection initialized");
    this->addToLogs("Close the window and from Main click 'Get Data'");
//    valConn = true;
//    // Przekazujemy wartość port'u do device za pomocą funkcji setPortName()
//    this->device->setPortName(portName);

//    // Jeżeli operacja otwarcie się powodzi na tryb read wtedy:
//    // Ustawiamy parametry komunikacji : BAUD , Data Bit , NoParity, OneStop, NoFlowControl

//    if(!device->isOpen()){
//        if(true){
//            device->open(QSerialPort::ReadOnly);
//            this->device->setBaudRate(QSerialPort::Baud115200);
//            this->device->setDataBits(QSerialPort::Data8);
//            this->device->setParity(QSerialPort::NoParity);
//            this->device->setStopBits(QSerialPort::OneStop);
//            this->device->setFlowControl(QSerialPort::NoFlowControl);

//            this->addToLogs("Port is opened");
////            connect(this->device, SIGNAL(readyRead()), this, SLOT(readFromPort()) );

//        }else{
//            this->addToLogs("Could not open port");
//        }
//    }else{
//        this->addToLogs("Port is already opened!");
//        return;
//    }
=======
    // Przekazujemy wartość port'u do device za pomocą funkcji setPortName()
    this->device->setPortName(portName);

    // Jeżeli operacja otwarcie się powodzi na tryb read wtedy:
    // Ustawiamy parametry komunikacji : BAUD , Data Bit , NoParity, OneStop, NoFlowControl

    if(!device->isOpen()){
        if(device->open(QSerialPort::ReadOnly)){
            this->device->setBaudRate(QSerialPort::Baud115200);
            this->device->setDataBits(QSerialPort::Data8);
            this->device->setParity(QSerialPort::NoParity);
            this->device->setStopBits(QSerialPort::OneStop);
            this->device->setFlowControl(QSerialPort::NoFlowControl);

            this->addToLogs("Port is opened");
            // przekazuj za pomocą funkcji bool że wszystko jest ustawione
            deviceSetUp = true;
            give_device_name();
            readFromPort();

        }else{
            this->addToLogs("Could not open port");
            // przekazuj za pomocą funkcji bool że wszystko jest ustawione
            deviceSetUp = false;
        }
    }else{
        this->addToLogs("Port is already opened!");
        return;
    }
>>>>>>> e1a18cf145c2204eaae565638cb0d50a38580484
}

void ConnectDialog::on_disconnectButton_clicked()
{
    if(this->device->isOpen()){
        this->device->close();
        this->addToLogs("Connection closed");
<<<<<<< HEAD
        valConn = false;

=======
>>>>>>> e1a18cf145c2204eaae565638cb0d50a38580484
    }else{
        this->addToLogs("Port is already closed!");
        return;
    }
}

<<<<<<< HEAD
void ConnectDialog::readFromPort()
{
    while(this->device->canReadLine()){
          QString line = this->device->readAll();
          qDebug() << line;
          QString terminator = "\r";
          int pos = line.lastIndexOf(terminator);
          qDebug() << line.left(pos);
          this->addToLogs(line.left(pos));
=======
QString ConnectDialog::give_device_name(){
    if(deviceSetUp){
        QString portName = ui->comboBoxDevices->currentText().split(" ").first();
        return portName;
    }else{
         return 0;
    }
}

QString ConnectDialog::readFromPort(){
    while(this->device->canReadLine()){
        QString line = this->device->readLine();
        QString terminator = "\n\r";
        int pos = line.lastIndexOf(terminator);
        line = line.left(pos);
        return line;
>>>>>>> e1a18cf145c2204eaae565638cb0d50a38580484
    }
}

