QT       += core gui

#QSerialPort posłuży nam do obsługi portu w komunikacji z płytką Arduino
QT       += serialport

<<<<<<< HEAD
#printsupport do obsługi wykresów
QT      += charts
#printsupport do obsługi wykresów qcustomplot (3-rd part add-in)
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport
=======
#QCharts posłuży nam do obsługi wykresów
QT      += charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
>>>>>>> e1a18cf145c2204eaae565638cb0d50a38580484

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    connectdialog.cpp \
    main.cpp \
    mainwindow.cpp \
<<<<<<< HEAD
    plant.cpp \
    qcustomplot.cpp

HEADERS += \
    connectdialog.h \
    device.h \
    mainwindow.h \
    plant.h \
    qcustomplot.h

HEADERS += src/*.png
=======
    plant.cpp

HEADERS += \
    connectdialog.h \
    mainwindow.h \
    plant.h
>>>>>>> e1a18cf145c2204eaae565638cb0d50a38580484

FORMS += \
    connectdialog.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

<<<<<<< HEAD
DISTFILES += \
    README.md
=======
RESOURCES += \
    resource_images.qrc
>>>>>>> e1a18cf145c2204eaae565638cb0d50a38580484
