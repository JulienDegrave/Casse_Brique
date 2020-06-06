#ifndef RACKET_H
#define RACKET_H

#include "GameObject.h"
#include "Ball.h"

class Racket : public GameObject
{
    public:
        Racket(Ball* ball);
        QGraphicsItem* getItem();
        void update();
        bool keyRight;
        bool keyLeft;
        int speed;
        GameObject* ball;

    private:
        QGraphicsRectItem* racket;
};

#endif // RACKET_H
