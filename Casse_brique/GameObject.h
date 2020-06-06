#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QVector2D>

class GameObject
{
    public :
    GameObject(int x, int y, int w, int h , QVector2D *v);
    ~GameObject();
    int getx();
    int gety();
    int geth();
    int getw();
    void setItem(QGraphicsItem* tem);
    QVector2D* getv();
    virtual QGraphicsItem* getItem();
    virtual void update();

    protected :
        int x;
        int y;
        int w;
        int h;
        QVector2D *v;
        QGraphicsItem *item;

};


#endif // GAMEOBJECT_H
