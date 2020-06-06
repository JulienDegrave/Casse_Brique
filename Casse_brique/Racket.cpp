#include "GameObject.h"
#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QVBoxLayout>
#include <QVector2D>
#include <Racket.h>
#include <QKeyEvent>
#include "Ball.h"


Racket::Racket(Ball* ball) : GameObject(0, -100, 50,10, new QVector2D(0,0))
{
    this->ball = ball;
    racket = new QGraphicsRectItem(x, y, w, h);
    racket->setBrush(Qt::black);
    keyRight = false;
    keyLeft = false;
    speed = 3;
}

QGraphicsItem* Racket::getItem()
{
    return racket;
}

void Racket::update()
{
    if(keyRight && !keyLeft)
    {
        v->setX(speed);
    }
    else if(keyLeft && !keyRight)
    {
        v->setX(-speed);
    }
    else
    {
        v->setX(0);
    }

    if(x < -300 && keyLeft || x + w > 295 && keyRight)
    {
        v->setX(0);
    }

    QRectF prev = racket->rect();
    prev.translate(v->x(), v->y());
    x = prev.x();
    y = prev.y();
    racket->setRect(prev);

    if((ball->gety() + ball->geth() > y) && ball->getx() > x && ball->getx() < x + w)
    {
        ball->getv()->setY(-1);
    }

}
