#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "pacman.h"
#include "QKeyEvent"
#include <QTimer>
#include <QGraphicsRectItem>

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
    void bordesColisiones(QKeyEvent *event);

private:
    int vel=3;
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    pacman *jugador;
    QTimer *timer;
    //bordes del cuadrado
    QGraphicsRectItem * LbordeU;
    QGraphicsRectItem * LbordeD;
    QGraphicsRectItem * Uborde;
    QGraphicsRectItem * RbordeU;
    QGraphicsRectItem * RbordeD;
    QGraphicsRectItem * Dborde;

    //baderas de colisiones
    bool col_D=false;
    bool col_A=false;
    bool col_W=false;
    bool col_S=false;
    //QGraphicsRectItem* array[10];
};
#endif // MAINWINDOW_H
