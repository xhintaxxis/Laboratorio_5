#ifndef CONTADOR_H
#define CONTADOR_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class Contador:QObject,
        public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Contador(QGraphicsItem* carr = 0);
    void posiNum(int newX, int newY);
};

#endif // CONTADOR_H
