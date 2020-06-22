#ifndef BRICK_H
#define BRICK_H

#include "GameObject.h"
#include <Ball.h>
#include <QLabel>

class Brick : public GameObject
{
    Q_OBJECT
    public:
        Brick(QList<Ball*>* ball, int x, int y);
        QGraphicsItem* getItem();
        void update();
        void del();
        void setColor();
        static int score;
    signals :
        void brick_broken(Brick*);
    protected:
        QGraphicsRectItem* rect;
        QList<Ball*>* ball;
        int durability;
        bool hit;
};

class Br_Solid: public Brick
{
    public:
        Br_Solid(QList<Ball*>* ball, int x, int y);
        QGraphicsItem* getItem();
        void update();
    private:
};

class Br_Ball: public Brick
{
    Q_OBJECT

    public:
        Br_Ball(QList<Ball*>* ball, int x, int y);
        QGraphicsItem* getItem();
        void update();
    signals:
        void new_Ball(Brick*);
    private:
};

class Score : public GameObject
{
public:
    Score();
    QGraphicsItem* getItem();
    void update();
private:

};

#endif // BRICK_H
