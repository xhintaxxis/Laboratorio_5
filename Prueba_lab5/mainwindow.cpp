#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pacman.h"
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene= new QGraphicsScene();
    scene->setSceneRect(0,0,400,400);
    ui->graphicsView->setScene(scene);
    scene->addRect(scene->sceneRect());
    jugador= new pacman();
    jugador->posicion(20,20);
    scene->addItem(jugador);
    timer = new QTimer;
    createBordes();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event){//Funciones de teclas
    int posi=0;
    if(event->key()==Qt::Key_F4) close();
    if(event->key()==Qt::Key_D){
        if(!col_D){
            if(jugador->getX()>(400-30))jugador->posicion(0,jugador->getY());
            jugador->setX(jugador->getX()+vel);
        }
        posi=0;
    }
    if(event->key()==Qt::Key_A){
        if(!col_A){
            if(jugador->getX()<(5)) jugador->posicion(400-20,jugador->getY());
            jugador->setX(jugador->getX()-vel);
        }
        else{
        }

        posi=1;
    }
    if(event->key()==Qt::Key_W){
        if(!col_W){
            jugador->setY(jugador->getY()-vel);
        }
        posi=2;
    }
    if(event->key()==Qt::Key_S && !col_S){
        if(!col_S){
            jugador->setY(jugador->getY()+vel);
        }
        posi=3;
    }
    jugador->mov(posi);
    jugador->posicion();
    bordesColisiones(event);
}

void MainWindow::createBordes()
{
    LbordeU = new QGraphicsRectItem(0,0,12,180);
    scene->addItem(LbordeU);
    LbordeU->setPos(0,0);
    LbordeD = new QGraphicsRectItem(0,220,12,180);
    scene->addItem(LbordeD);
    LbordeD->setPos(0,0);
    Uborde = new QGraphicsRectItem(0,0,400,12);
    scene->addItem(Uborde);
    Uborde->setPos(0,0);
    RbordeU = new QGraphicsRectItem(388,0,12,180);
    scene->addItem(RbordeU);
    RbordeU->setPos(0,0);
    RbordeD = new QGraphicsRectItem(388,220,12,180);
    scene->addItem(RbordeD);
    RbordeD->setPos(0,0);
    Dborde = new QGraphicsRectItem(0,388,400,12);
    scene->addItem(Dborde);
    Dborde->setPos(0,0);
}

void MainWindow::bordesColisiones(QKeyEvent *event)
{
    if (jugador->collidesWithItem(LbordeU) || jugador->collidesWithItem(LbordeD) || jugador->collidesWithItem(Uborde)|| jugador->collidesWithItem(RbordeU) || jugador->collidesWithItem(RbordeD) || jugador->collidesWithItem(Dborde)){

        switch (event->key()) {
        case Qt::Key_D:
            col_D=true;
            break;


        case Qt::Key_A:
            col_A=true;
            //jugador->setX(15);
            break;


        case Qt::Key_W:
            col_W=true;
            break;

        case Qt::Key_S:
            col_S=true;
            break;

        default:
            break;
        }

    }
    else{
        col_D=false;
        col_A=false;
        col_W=false;
        col_S=false;
    }
}
