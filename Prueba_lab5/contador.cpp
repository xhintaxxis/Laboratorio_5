#include "contador.h"

Contador::Contador(QGraphicsItem *carr):QGraphicsPixmapItem(carr)
{
    setPixmap(QPixmap(":/images/numero 0.png"));
}

void Contador::posiNum(int newX, int newY)
{
    setPos(newX,newY);
}
