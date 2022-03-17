#include "window.h"
#include "ui_window.h"
#include <QThread>

window::window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::window)
{
    pacx=410/2;
    pacy=360;
    start=false;
    direction=0;
    moving=false;
    delayb=false;
    playing=false;
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    scene->setSceneRect(0,0,640,480);
    ui->graphicsView->setSceneRect(scene->sceneRect());
    pacman=new Pacman;
    pacx=410/2;
    pacy=410;
    start_Game();
}
void window::start_Game()
{
    pacx=410/2;
    pacy=360;
    pac_map=new Map;
    ballpoints=pac_map->getballpoints();
    Powerballpoints=pac_map->getpowerballpoints();
    ball=new Ball;
    powerball=new PowerBall;
    ball->setpoints(ballpoints);

    powerball->setpoints(Powerballpoints);
    scene->addItem(pac_map);
    scene->addItem(pacman);
    direction=0;
    moving=false;
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this,SLOT(updater()));
    this->show();
    scene->update();
    this->update();
    delayb=true;


       timer->start(10);
       this->setFocus();
}
void window::delay()
{
   QTime dieTime= QTime::currentTime().addSecs(2);
    while( QTime::currentTime() < dieTime ){}
    delayb=false;
}

void window::pacman_move()
{
    QPoint p;
    if(nextdirection!=direction){
        switch(nextdirection)
        {
            case 1:
            p.setX(pacx-5);
            p.setY(pacy);

            if(pac_map->canmove(p)){
                direction=nextdirection;
                nextdirection=0;

            }

                break;

            case 4:
            p.setX(pacx+5);
            p.setY(pacy);
            if(pac_map->canmove(p)){
                direction=nextdirection;
                nextdirection=0;

            }

                break;
            case 3:
            p.setX(pacx);
            p.setY(pacy+5);
            if(pac_map->canmove(p)){
                direction=nextdirection;
                nextdirection=0;

            }

                break;
            case 2:
            p.setX(pacx);
            p.setY(pacy-5);
            if(pac_map->canmove(p)){
                direction=nextdirection;
                nextdirection=0;

            }

                break;
        }

    }
        switch(direction)
        {
            case 1:
            p.setX(pacx-5);
            p.setY(pacy);
            pacman->setDirection(direction);

            if(pac_map->canmove(p)){
                pacx-=5;


                moving=true;

            }else{
                moving=false;
            }

                break;

            case 4:
            pacman->setDirection(direction);
            p.setX(pacx+5);
            p.setY(pacy);
            if(pac_map->canmove(p)){
                pacx+=5;

                moving=true;

            }else{
                moving=false;
            }

                break;
            case 3:
            pacman->setDirection(direction);
            p.setX(pacx);
            p.setY(pacy+5);
            if(pac_map->canmove(p)){
                pacy+=5;
                moving=true;

            }else{
                moving=false;
            }

                break;
            case 2:
            pacman->setDirection(direction);
            p.setX(pacx);
            p.setY(pacy-5);
            if(pac_map->canmove(p)){
                pacy-=5;
                moving=true;

            }else{
                moving=false;
            }

                break;
        }


        if(pacx<=0){
            pacx=450;
            pacy=230;
        }else if(pacx>=450){
            pacx=0;
            pacy=230;
        }
    pacman->setpacx(pacx);
    pacman->setpacy(pacy);
}
void window::keyPressEvent(QKeyEvent *event)
{
QPoint p;

        switch(event->key())
        {
            case Qt::Key_Left:

            if(!moving){


                direction=1;

            }else{
               nextdirection=1;
            }

                break;
            case Qt::Key_Right:

            if(!moving){


                direction=4;

            }else{

                nextdirection=4;
            }

                break;
            case Qt::Key_Down:
            if(!moving){
                direction=3;
            }else{
               nextdirection=3;
            }
                break;
            case Qt::Key_Up:
            if(!moving){
                direction=2;
            }else{
                nextdirection=2;
            }
                break;
         default:
                break;
        }

}
void window::updater()
{
    pacman_move();
    for(int i=0;i<ballpoints.size();i++){
        if(pacman->pacx==ballpoints[i].x() && pacman->pacy==ballpoints[i].y()){
            ballpoints.remove(i);
        }
    }
    for(int i=0;i<Powerballpoints.size();i++){
        if(pacman->pacx==Powerballpoints[i].x() && pacman->pacy==Powerballpoints[i].y()){
            Powerballpoints.remove(i);
        }
    }

    ball->setpoints(ballpoints);
    powerball->setpoints(Powerballpoints);
    pac_map->setballpoints(ballpoints);
    pac_map->setpowerballpoints(Powerballpoints);
    pac_map->fillpacpoints(pacx,pacy);
    pacman->advance();
    this->setFocus();
    scene->update(pac_map->boundingRect());
    if(delayb){delay();}
}



window::~window()
{
    delete ui;
}

