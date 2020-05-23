#ifndef PLANT_H
#define PLANT_H

#include <QObject>

class plant : public QObject
{
    Q_OBJECT
public:
    explicit plant(QObject *parent = nullptr);

signals:

};

#endif // PLANT_H
