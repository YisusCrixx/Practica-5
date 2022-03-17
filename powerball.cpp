#include "powerball.h"

PowerBall::PowerBall()
{
    ballx=0;
    bally=0;
    ballw=5;
    ballh=5;
}

QRectF PowerBall::boundingRect() const
{
    return QRect(0, 0, 450, 480);
}

void PowerBall::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
}

void PowerBall::setpoints(QVector<QPoint> points)
{
    this->points.clear();
    this->points=points;
}
