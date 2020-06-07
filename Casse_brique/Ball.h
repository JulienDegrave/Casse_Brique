#ifndef BALL_H
#define BALL_H

#include "GameObject.h"

class Ball : public GameObject
{
    Q_OBJECT

    public:
        Ball(int x = -10, int y = -100);
        QGraphicsItem* getItem();
        void update();
    signals:
        void lose_ball();

    private:
        QGraphicsEllipseItem* ball;

};

#endif // BALL_H
