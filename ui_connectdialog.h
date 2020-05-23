/********************************************************************************
** Form generated from reading UI file 'connectdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECTDIALOG_H
#define UI_CONNECTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_ConnectDialog
{
public:
    QGroupBox *connectionBox;
    QPushButton *scanButton;
    QPushButton *connectButton;
    QPushButton *disconnectButton;
    QTextBrowser *textBrowser_2;
    QComboBox *comboBoxDevices;
    QTextEdit *textEdit;

    void setupUi(QDialog *ConnectDialog)
    {
        if (ConnectDialog->objectName().isEmpty())
            ConnectDialog->setObjectName(QString::fromUtf8("ConnectDialog"));
        ConnectDialog->resize(423, 432);
        connectionBox = new QGroupBox(ConnectDialog);
        connectionBox->setObjectName(QString::fromUtf8("connectionBox"));
        connectionBox->setGeometry(QRect(10, 20, 401, 391));
        scanButton = new QPushButton(connectionBox);
        scanButton->setObjectName(QString::fromUtf8("scanButton"));
        scanButton->setGeometry(QRect(10, 50, 111, 31));
        connectButton = new QPushButton(connectionBox);
        connectButton->setObjectName(QString::fromUtf8("connectButton"));
        connectButton->setGeometry(QRect(60, 334, 111, 31));
        disconnectButton = new QPushButton(connectionBox);
        disconnectButton->setObjectName(QString::fromUtf8("disconnectButton"));
        disconnectButton->setGeometry(QRect(200, 334, 111, 31));
        textBrowser_2 = new QTextBrowser(connectionBox);
        textBrowser_2->setObjectName(QString::fromUtf8("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(30, 260, 91, 31));
        comboBoxDevices = new QComboBox(connectionBox);
        comboBoxDevices->setObjectName(QString::fromUtf8("comboBoxDevices"));
        comboBoxDevices->setGeometry(QRect(160, 260, 231, 31));
        textEdit = new QTextEdit(connectionBox);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(10, 90, 381, 161));

        retranslateUi(ConnectDialog);

        QMetaObject::connectSlotsByName(ConnectDialog);
    } // setupUi

    void retranslateUi(QDialog *ConnectDialog)
    {
        ConnectDialog->setWindowTitle(QCoreApplication::translate("ConnectDialog", "Dialog", nullptr));
        connectionBox->setTitle(QCoreApplication::translate("ConnectDialog", "Connection", nullptr));
        scanButton->setText(QCoreApplication::translate("ConnectDialog", "Scan", nullptr));
        connectButton->setText(QCoreApplication::translate("ConnectDialog", "Connect", nullptr));
        disconnectButton->setText(QCoreApplication::translate("ConnectDialog", "Disconnect", nullptr));
        textBrowser_2->setHtml(QCoreApplication::translate("ConnectDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">Device : </span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConnectDialog: public Ui_ConnectDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTDIALOG_H
