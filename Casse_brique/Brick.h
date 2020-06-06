#ifndef BRICK_H
#define BRICK_H

#include "GameObject.h"
#include <Ball.h>
#include <QLabel>

class Brick : public GameObject
{
    public:
        Brick(Ball* ball, int x, int y);
        QGraphicsItem* getItem();
        void update();
        void setColor();
        static int score;
    private :
        QGraphicsRectItem* rect;
        Ball* ball;
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
