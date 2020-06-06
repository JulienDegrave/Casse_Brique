#ifndef BALL_H
#define BALL_H

#include "GameObject.h"

class Ball : public GameObject
{
    public:
        Ball();
        QGraphicsItem* getItem();
        void update();

    private:
        QGraphicsEllipseItem* ball;

};

#endif // BALL_H
