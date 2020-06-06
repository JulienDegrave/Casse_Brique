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

class MainWindow: public QWidget
{
    Q_OBJECT

    public :
        MainWindow();
        ~MainWindow();
        void keyPressEvent(QKeyEvent *event);
        void keyReleaseEvent(QKeyEvent *event);
    public slots :
        void update();

    private:
        QGraphicsView *view;
        QGraphicsScene *scene;
        QGraphicsRectItem* rect;
        QTimer * timer;
        QList<GameObject*> items;
        Racket* racket;

};

#endif // FENETRE_H
