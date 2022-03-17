#ifndef POWERBALL_H
#define POWERBALL_H
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>

class PowerBall : public QGraphicsItem
{
public:
    PowerBall();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setpoints(QVector<QPoint> points);
    int ballx,bally;
    int ballw,ballh;
    QVector<QPoint> points;
    QPixmap pBallPix;
};

#endif // POWERBALL_H
