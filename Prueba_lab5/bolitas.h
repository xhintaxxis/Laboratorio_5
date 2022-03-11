#ifndef BOLITAS_H
#define BOLITAS_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

class bolitas:QObject,
        public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int numero;
public:
    ~bolitas();
    bolitas(QGraphicsItem* carr = 0);
    void position(int newX,int newY);

};

#endif // BOLITAS_H
