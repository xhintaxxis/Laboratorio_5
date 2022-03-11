#include "bolitas.h"



bolitas::~bolitas()
{
}

bolitas::bolitas(QGraphicsItem *carr):QGraphicsPixmapItem(carr)
{
    setPixmap(QPixmap(":/images/bolita.png"));
}

void bolitas::position(int newX, int newY)
{
    setPos(newX,newY);
}
