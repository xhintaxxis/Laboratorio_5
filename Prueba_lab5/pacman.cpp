#include "pacman.h"


int pacman::getX() const
{
    return x;
}

void pacman::setX(int newX)
{
    x = newX;
}

int pacman::getY() const
{
    return y;
}

void pacman::setY(int newY)
{
    y = newY;
}

void pacman::posicion()
{
    setPos(x,y);
}

void pacman::posicion(int newX, int newY)
{
    x=newX;
    y=newY;
    setPos(x,y);

}

void pacman::mov(int posi)
{
    if (flag && cont<5)
    {
        if(posi==0){setPixmap(QPixmap(":/images/pmAbiertoPP.png"));}
        if(posi==1){setPixmap(QPixmap(":/images/pmAbiertoPP-x.png"));}
        if(posi==2){setPixmap(QPixmap(":/images/pmAbiertoPP+y.png"));}
        if(posi==3){setPixmap(QPixmap(":/images/pmAbiertoPP-y.png"));}
        flag=false;
    }
    else if (!flag && cont >5)
    {
        setPixmap(QPixmap(":/images/pmCerradoPP.png"));
        flag=true;
    }
    if (cont==10)cont=0;

    cont++;
}

pacman::pacman(QGraphicsItem *carr):QGraphicsPixmapItem(carr)
{
    setPixmap(QPixmap(":/images/pmAbiertoPP.png"));
}
