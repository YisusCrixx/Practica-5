#ifndef WINDOW_H
#define WINDOW_H

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include "pacman.h"
#include "map.h"
#include "ball.h"
#include "powerball.h"

namespace Ui {
class window;
}

class window : public QDialog
{
    Q_OBJECT

public:
    explicit window(QWidget *parent = 0);
    void pacman_move();
    void delay();
    void start_Game();

    Pacman *pacman;

    Map *pac_map;
    Ball *ball;
    PowerBall *powerball;

    int pacx,pacy,direction,nextdirection;
    bool moving;
    bool start,delayb;
    bool playing;
    QVector<QPoint> ballpoints;
    QVector<QPoint> Powerballpoints;
    QThread *sleeper;
    ~window();
public slots:
    void updater();
protected:
    void keyPressEvent(QKeyEvent *event);


private:
    Ui::window *ui;
    QGraphicsScene *scene;
    QTimer *timer;
};

#endif // WINDOW_H
