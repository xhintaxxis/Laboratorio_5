#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pacman.h"
#include "bolitas.h"
#include "contador.h"
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene= new QGraphicsScene();
    scene->setSceneRect(0,0,380,400);
    ui->graphicsView->setScene(scene);
    scene->addRect(scene->sceneRect());
    jugador= new pacman();
    jugador->posicion(330,20);
    scene->addItem(jugador);
    timer = new QTimer;
    createBordes();
    createParedes();

    //
    unidades=new Contador();
    unidades->posiNum(335,352);
    scene->addItem(unidades);

    decenas=new Contador();
    decenas->posiNum(310,352);
    scene->addItem(decenas);


    //bolas del escenario
    for(int i=0;i<50;i++){
        bolas[i] = new bolitas();
    }
    for(int i=0;i<7;i++){
            bolas[i]->position(30,(56*i)+20);
            scene->addItem(bolas[i]);
    }
    for(int i=7;i<14;i++){
            bolas[i]->position(85,(56*i)+20-392);
            scene->addItem(bolas[i]);
    }
    for(int i=14;i<21;i++){
            bolas[i]->position(140,(56*i)+20-(2*392));
            scene->addItem(bolas[i]);
    }
    for(int i=21;i<28;i++){
            bolas[i]->position(205,(56*i)+20-(3*392));
            scene->addItem(bolas[i]);
    }
    for(int i=28;i<35;i++){
            bolas[i]->position(265,(56*i)+20-(4*392));
            scene->addItem(bolas[i]);
    }
    for(int i=35;i<40;i++){

            bolas[i]->position(335,(56*(i+1))+20-(5*392));
            scene->addItem(bolas[i]);
    }

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
            if(jugador->getX()>(380-30))jugador->posicion(0,jugador->getY());
            jugador->setX(jugador->getX()+vel);
        }
        posi=0;
    }
    if(event->key()==Qt::Key_A){
        if(!col_A){
            if(jugador->getX()<(5)) jugador->posicion(380-20,jugador->getY());
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
    comerBolitas();
}

void MainWindow::createBordes()
{
    LbordeU = new QGraphicsRectItem(0,0,12,180);
    scene->addItem(LbordeU);
    LbordeU->setPos(0,0);
    LbordeD = new QGraphicsRectItem(0,220,12,180);
    scene->addItem(LbordeD);
    LbordeD->setPos(0,0);
    Uborde = new QGraphicsRectItem(0,0,380,12);
    scene->addItem(Uborde);
    Uborde->setPos(0,0);
    RbordeU = new QGraphicsRectItem(368,0,12,180);
    scene->addItem(RbordeU);
    RbordeU->setPos(0,0);
    RbordeD = new QGraphicsRectItem(368,220,12,180);
    scene->addItem(RbordeD);
    RbordeD->setPos(0,0);
    Dborde = new QGraphicsRectItem(0,388,380,12);
    scene->addItem(Dborde);
    Dborde->setPos(0,0);
    McontU=new QGraphicsRectItem(290,330,90,12);
    scene->addItem(McontU);
    McontL=new QGraphicsRectItem(290,330,12,70);
    scene->addItem(McontL);
}

void MainWindow::createParedes()
{
    barra1 = new QGraphicsRectItem(60,330,177,12);
    scene->addItem(barra1);
    barra2 = new QGraphicsRectItem(60,270,190,12);
    scene->addItem(barra2);
    barra3 = new QGraphicsRectItem(110,160,12,122);
    scene->addItem(barra3);
    barra4 = new QGraphicsRectItem(55,70,12,150);
    scene->addItem(barra4);
    barra5 = new QGraphicsRectItem(55,58,142,12);
    scene->addItem(barra5);
    barra6 = new QGraphicsRectItem(240,58,12,170);
    scene->addItem(barra6);
    barra7 = new QGraphicsRectItem(170,216,82,12);
    scene->addItem(barra7);
    barra8 = new QGraphicsRectItem(110,160,80,12);
    scene->addItem(barra8);
    barra9 = new QGraphicsRectItem(110,110,142,12);
    scene->addItem(barra9);
    barra10 = new QGraphicsRectItem(305,58,12,65);
    scene->addItem(barra10);
    barra11 = new QGraphicsRectItem(305,170,12,112);
    scene->addItem(barra11);

}

void MainWindow::bordesColisiones(QKeyEvent *event)
{
    if (jugador->collidesWithItem(LbordeU) || jugador->collidesWithItem(LbordeD) || jugador->collidesWithItem(Uborde)||
            jugador->collidesWithItem(RbordeU)|| jugador->collidesWithItem(RbordeD) || jugador->collidesWithItem(Dborde) ||
            jugador->collidesWithItem(McontL) || jugador->collidesWithItem(McontU) || jugador->collidesWithItem(barra1)
            || jugador->collidesWithItem(barra2) || jugador->collidesWithItem(barra3)|| jugador->collidesWithItem(barra4)
            || jugador->collidesWithItem(barra5) || jugador->collidesWithItem(barra6) || jugador->collidesWithItem(barra7)
            || jugador->collidesWithItem(barra8) || jugador->collidesWithItem(barra9) || jugador->collidesWithItem(barra10)
            || jugador->collidesWithItem(barra11)){

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

void MainWindow::comerBolitas()
{
   for(int i=0;i<40;i++){
       if(jugador->collidesWithItem(bolas[i])){
            bolas[i]->position(600,600);
       }
   }

}
