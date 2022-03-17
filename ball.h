#ifndef BALL_H
#define BALL_H
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>

class Ball : public QGraphicsItem
{
public:
    Ball();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setpoints(QVector<QPoint> points);
    int ballx,bally;
    int ballw,ballh;
    QPixmap ballpix;
    QRectF rec;
    QVector<QPoint> points;

};

#endif // BALL_H
