#include "contador.h"

Contador::Contador(QGraphicsItem *carr):QGraphicsPixmapItem(carr)
{
    setPixmap(QPixmap(":/images/numero 0.png"));
}

void Contador::posiNum(int newX, int newY)
{
    setPos(newX,newY);
}

void Contador::changeCont(int numero)
{
    /*
    if(numero==0){setPixmap(QPixmap(":/images/numero 0.png"));}
    else if(numero==1){setPixmap(QPixmap(":/images/numero 1.png"));}
    else if(numero==2){setPixmap(QPixmap(":/images/numero 2.png"));}
    else if(numero==3){setPixmap(QPixmap(":/images/numero 3.png"));}
    else if(numero==4){setPixmap(QPixmap(":/images/numero 4.png"));}
    else if(numero==5){setPixmap(QPixmap(":/images/numero 5.png"));}
    else if(numero==6){setPixmap(QPixmap(":/images/numero 6.png"));}
    else if(numero==7){setPixmap(QPixmap(":/images/numero 7.png"));}
    else if(numero==8){setPixmap(QPixmap(":/images/numero 8.png"));}
    else if(numero==9){setPixmap(QPixmap(":/images/numero 9.png"));}
    */
    switch (numero) {
    case 0:setPixmap(QPixmap(":/images/numero 0.png"));break;
    case 1: setPixmap(QPixmap(":/images/numero 1.png"));break;
    case 2: setPixmap(QPixmap(":/images/numero 2.png"));break;
    case 3: setPixmap(QPixmap(":/images/numero 3.png"));break;
    case 4: setPixmap(QPixmap(":/images/numero 4.png"));break;
    case 5: setPixmap(QPixmap(":/images/numero 5.png"));break;
    case 6: setPixmap(QPixmap(":/images/numero 6.png"));break;
    case 7: setPixmap(QPixmap(":/images/numero 7.png"));break;
    case 8: setPixmap(QPixmap(":/images/numero 8.png"));break;
    case 9: setPixmap(QPixmap(":/images/numero 9.png"));break;
    default: break;
}

}
