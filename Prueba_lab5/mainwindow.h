#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "pacman.h"
#include "QKeyEvent"
#include <QTimer>
#include <QGraphicsRectItem>
#include "bolitas.h"
#include "contador.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void keyPressEvent(QKeyEvent *event);
    void createBordes();
    void createParedes();
    void bordesColisiones(QKeyEvent *event);
    void comerBolitas();

private:
    int vel=3;
    int U=0;
    int D=0;
    int numero=0;
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    pacman *jugador;
    Contador * unidades;
    Contador * decenas;
    bolitas * bolas[50];
    QTimer *timer;


    //bordes del cuadrado
    QGraphicsRectItem * LbordeU;
    QGraphicsRectItem * LbordeD;
    QGraphicsRectItem * Uborde;
    QGraphicsRectItem * RbordeU;
    QGraphicsRectItem * RbordeD;
    QGraphicsRectItem * Dborde;

    //Marcos del contador
    QGraphicsRectItem * McontU;
    QGraphicsRectItem * McontL;

    //Marcos del contador
    QGraphicsRectItem * barra1;
    QGraphicsRectItem * barra2;
    QGraphicsRectItem * barra3;
    QGraphicsRectItem * barra4;
    QGraphicsRectItem * barra5;
    QGraphicsRectItem * barra6;
    QGraphicsRectItem * barra7;
    QGraphicsRectItem * barra8;
    QGraphicsRectItem * barra9;
    QGraphicsRectItem * barra10;
    QGraphicsRectItem * barra11;


    //baderas de colisiones
    bool col_D=false;
    bool col_A=false;
    bool col_W=false;
    bool col_S=false;
    //QGraphicsRectItem* array[10];
};
#endif // MAINWINDOW_H
