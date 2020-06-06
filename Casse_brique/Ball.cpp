#include "GameObject.h"
#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QVBoxLayout>
#include <QVector2D>
#include <Ball.h>
#include <QDebug>

Ball::Ball() : GameObject(0, -30, 20,20, new QVector2D(0.5,2))
{
    ball = new QGraphicsEllipseItem(x,y,w,h);
    ball->setBrush(Qt::red);
}

QGraphicsItem* Ball::getItem()
{
    return ball;
}

void Ball::update()
{
    if((y < -700)|| (y>-20))
    {
        v->setY(-v->y());
    }
    if((x < -305)||(x>270))
    {
        v->setX(-v->x());
    }
    QRectF prev = ball->rect();
    prev.translate(v->x(), v->y());
    x = prev.x();
    y = prev.y();
    ball->setRect(prev);
}
