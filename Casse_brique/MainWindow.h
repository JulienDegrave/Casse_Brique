#ifndef FENETRE_H
#define FENETRE_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <GameObject.h>
#include <QTimer>
#include <QKeyEvent>
#include <Racket.h>
#include <QLabel>
#include <QList>
#include <Ball.h>
#include <Brick.h>

class MainWindow: public QWidget
{
    Q_OBJECT

    public :
        MainWindow();
        ~MainWindow();
        void keyPressEvent(QKeyEvent *event);
        void keyReleaseEvent(QKeyEvent *event);
    public slots :
        void m_update();
        void m_add_Ball(Brick*);
        void lost_Ball(Ball*);
        void m_brick_broken(Brick*);

    private:
        QGraphicsView *view;
        QGraphicsScene *scene;
        QTimer * timer;
        QList<GameObject*> items;
        Racket* racket;
        QWidget* menu;
        QLabel* score;
        QList<Ball*>* balles;
        int speed;
        int lvl_special_bricks;

};

#endif // FENETRE_H
