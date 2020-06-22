#include "GameObject.h"
#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QVBoxLayout>
#include <QVector2D>
#include <Brick.h>
#include <Ball.h>
#include <QTime>
#include <QVector>
#include <QDebug>

int Brick::score = 0;

Brick::Brick(QList<Ball*>* ball, int x, int y) : GameObject(x, y, 50,30, new QVector2D(0,0))
{
    durability = 1;
    hit = false;
    this->ball = ball;
    rect = new QGraphicsRectItem(x, y, 50, 30);
    setColor();
}

QGraphicsItem* Brick::getItem()
{
    return rect;
}

void Brick::update()
{
    QList<Ball*>::iterator balls;
    for(balls = ball->begin(); balls != ball->end(); balls++){

        hit = false;
        if((*balls)->gety() < y + h && (*balls)->getx() > x && (*balls)->getx() < x + w && (*balls)->getv()->y() < 0)
        {
            hit = true;
            (*balls)->getv()->setY(1);
            if(durability < 2)
            {
                del();
                score++;
            }
        }else
        if(((*balls)->getx() + 20) > x && ((*balls)->getx() + 20) < x + w && (*balls)->gety() < y + h-3 && (*balls)->gety() > y && (*balls)->getv()->x()> 0)
        {
            hit = true;
            (*balls)->getv()->setX(-1);
            if(durability < 2)
            {
                del();
                score++;
            }
        }else
        if((*balls)->getx() < x + w && (*balls)->getx() > x && (*balls)->gety() < y + h-1 && (*balls)->gety() > y && (*balls)->getv()->x()< 0)
        {
            hit = true;
            (*balls)->getv()->setX(1);
            if(durability < 2)
            {
                del();
                score++;
            }
        }
    }



}

void Brick::del()
{
    emit brick_broken(this);
}
void Brick::setColor()
{
    int a, b, c;

    a = qrand() % (255 + 1);
    b = 41;
    c = 130;

    QColor* col = new QColor(a,b,c);
    rect->setBrush(*col);

}



/*____________________________*/

Br_Solid::Br_Solid(QList<Ball*>* ball, int x, int y) : Brick(ball,  x,  y)
{
    rect->setBrush(QColor(10,10,10));
    rect->setBrush(Qt::Dense4Pattern);
    durability = 3;
}

QGraphicsItem* Br_Solid::getItem()
{
    return rect;
}

void Br_Solid::update()
{
    if(hit)
    {
        switch (durability)
        {
            case 3 :
                rect->setBrush(QColor(76,76,76));
                durability--;
                break;
            case 2 :
                rect->setBrush(QColor(150,150,150));
                durability--;
                break;
        }
    }
    Brick::update();
}

/*-------------------------------*/

Br_Ball::Br_Ball(QList<Ball*>* ball, int x, int y) : Brick(ball,  x,  y)
{
    rect->setBrush(QColor(255,64,38));
    rect->setBrush(Qt::Dense1Pattern);

}
QGraphicsItem* Br_Ball::getItem()
{
    return rect;
}

void Br_Ball::update()
{
    if(hit)
    {
        emit new_Ball(this);
    }
    Brick::update();
}


