#include "GameObject.h"
#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QVBoxLayout>
#include <QVector2D>
#include <Ball.h>
#include <QTime>
#include <QDebug>
#include <QApplication>

Ball::Ball(int x, int y) : GameObject(x, y, 20,20, new QVector2D((double)((qrand() % (140 + 1)) - 70)/100 , -1))
{
    ball = new QGraphicsEllipseItem(x,y,w,h);
    ball->setBrush(Qt::red);
    qDebug() << "BALLE : " << ball;

}

Ball::~Ball()
{
    delete ball;
}

QGraphicsItem* Ball::getItem()
{
    return ball;
}

void Ball::update()
{
    if(y < -700 )
    {
        v->setY(-v->y());
    }
    if(y>-20)
    {
        emit lose_ball(this);
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
