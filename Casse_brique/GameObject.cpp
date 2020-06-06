#include "GameObject.h"
#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QVBoxLayout>
#include <QVector2D>

GameObject::GameObject(int x, int y, int w, int h , QVector2D *v)
{
    this->x=x;
    this->y=y;
    this->w=w;
    this->h=h;
    this->v=v;
}

GameObject::~GameObject()
{
    delete(v);
}

int GameObject::getx()
{
    return x;
}

int GameObject::gety()
{
    return y;
}

int GameObject::geth()
{
    return h;
}

int GameObject::getw()
{
    return w;
}

QVector2D* GameObject::getv()
{
    return v;
}

QGraphicsItem* GameObject::getItem()
{
    return item;
}

void GameObject::setItem(QGraphicsItem* tem)
{
    item = tem;
}
void GameObject::update(){}
