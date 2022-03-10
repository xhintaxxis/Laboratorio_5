#ifndef PACMAN_H
#define PACMAN_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

class pacman: public QObject,
        public QGraphicsPixmapItem
{
    Q_OBJECT

private:
    int x;
    int y;
    bool flag=true;
    int cont=0;
public:

    pacman(QGraphicsItem* carr = 0);
    int getX() const;
    void setX(int newX);
    int getY() const;
    void setY(int newY);
    void posicion();
    void posicion(int newX,int newY);
    void mov(int posi);
};

#endif // PACMAN_H
