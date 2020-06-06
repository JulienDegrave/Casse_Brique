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

Brick::Brick(Ball* ball, int x, int y) : GameObject(x, y, 50,30, new QVector2D(0,0))
{
    this->ball = ball;
    rect = new QGraphicsRectItem(x, y, 50, 30);
    setColor();
}

QGraphicsItem* Brick::getItem()
{
    return rect;
}

void Brick::update(){
    if(ball->gety() < y + h && ball->getx() > x && ball->getx() < x + w)
    {
        ball->getv()->setY(1);
        this->x += 1000; // Il était tard
        rect->setRect(QRectF(1000, 1000, 0, 0));
        score++;
    }
}

void Brick::setColor()
{

    int a, b, c;

    a = qrand() % ((255 + 1));
    b = 41;
    c = 130;

    QColor* col = new QColor(a,b,c);
    rect->setBrush(*col);

}



