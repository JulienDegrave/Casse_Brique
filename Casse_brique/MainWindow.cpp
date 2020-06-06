#include "MainWindow.h"
#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QVBoxLayout>
#include <Brick.h>
#include <Ball.h>
#include <Racket.h>
#include <QEvent>
#include <QKeyEvent>
#include <QDebug>
#include <QList>

MainWindow::MainWindow() : QWidget()
{
    this->setFixedSize(600, 700);

    timer = new QTimer(this);
    scene = new QGraphicsScene();

    Ball* ball = new Ball();
    items.append(ball);
    scene->addItem(ball->getItem());

    for(int x = -300; x < 300; x = x + 50)
    {
        for(int y = -700; y < -300; y = y + 30)
        {
            GameObject* brick = new Brick(ball, x, y);
            items.append(brick);
            scene->addItem(brick->getItem());

        }
    }

    racket = new Racket(ball);
    items.append(racket);
    scene->addItem(racket->getItem());

    GameObject* testt = new GameObject(400,20,40,60,0);
    QGraphicsTextItem* test = new QGraphicsTextItem(QString::number(Brick::score));
    test->setFont(QFont("Times", 20, QFont::Bold));
    test->setHtml("<p style=\"text-indent:0px; background-color:red; font-size:20pt;\"></p>");
    testt->setItem(test);
    items.append(testt);
    scene->addItem(testt->getItem());

    scene->setSceneRect(-300,-695, 600, 700);

    view = new QGraphicsView(scene, this);
    view->setFixedSize(606,703);
    view->move(-3,0);

    view->show();

    timer->start(5);

    connect(timer, SIGNAL(timeout()), this, SLOT(update()));

}

MainWindow::~MainWindow()
{

}

void MainWindow::update()
{
    QList<GameObject*>::iterator gameObject;
    for(gameObject = items.begin(); gameObject != items.end(); gameObject++){
        (*gameObject)->update();
    }

}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->nativeScanCode() == 24 && !racket->keyLeft)
    {
        racket->keyLeft = true;
    }
    if(event->nativeScanCode() == 25 && !racket->keyRight)
    {
        racket->keyRight = true;
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    if(event->nativeScanCode() == 24 && racket->keyLeft)
    {
        racket->keyLeft = false;
    }
    if(event->nativeScanCode() == 25 && racket->keyRight)
    {
        racket->keyRight = false;
    }
}

