#include "ball.h"

Ball::Ball()
{
    ballx=0;
    bally=0;
    ballw=5;
    ballh=5;

}

QRectF Ball::boundingRect() const
{
    return QRect(0, 0, 450, 480);
}

void Ball::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

}
void Ball::setpoints(QVector<QPoint> points)
{
    this->points.clear();
    this->points=points;
}


