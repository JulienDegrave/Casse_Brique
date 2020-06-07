#include "GameObject.h"
#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QVBoxLayout>
#include <QVector2D>
#include <Racket.h>
#include <QKeyEvent>
#include <QDebug>
#include "Ball.h"


Racket::Racket(QList<Ball*>* ball) : GameObject(-23, -80, 50,5, new QVector2D(0,0))
{
    this->balls = ball;
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

    if((x < -300 && keyLeft) || (x + w > 295 && keyRight))
    {
        v->setX(0);
    }

    QRectF prev = racket->rect();
    prev.translate(v->x(), v->y());
    x = prev.x();
    y = prev.y();
    racket->setRect(prev);

    QList<Ball*>::iterator ball;
    for(ball = balls->begin(); ball != balls->end(); ball++){

    if(((*ball)->gety() + (*ball)->geth() > y) && (*ball)->getx()+(*ball)->getw() > x && (*ball)->getx() < x + w)
    {
        (*ball)->getv()->setY(-1);

        if((*ball)->getx() + ((*ball)->getw()/2) > x + (w/2))
        {
            float dirx_ball = (*ball)->getv()->x();
            (*ball)->getv()->setX(dirx_ball+0.2);
            if((*ball)->getv()->x() > 2)
            {
               (*ball)->getv()->setX(2);
            }
        }else
        {
            float dirx_ball = (*ball)->getv()->x();
            (*ball)->getv()->setX(dirx_ball-0.2);
            if((*ball)->getv()->x() < -2)
            {
               (*ball)->getv()->setX(-2);
            }
        }
    }
    }

}
