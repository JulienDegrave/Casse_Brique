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
#include <QApplication>

MainWindow::MainWindow() : QWidget()
{

    srand (time(NULL));
    speed = 10;
    lvl_special_bricks = 30;
    this->setFixedSize(600, 750);

    timer = new QTimer(this);
    scene = new QGraphicsScene();

    menu = new QWidget(this);
    menu->setFixedSize(600,50);
    menu->setStyleSheet("background-color: black;");

    score = new QLabel(menu);
    score->setStyleSheet("background-color: rgb(93,93,93); color: white;");
    score->setFont(QFont("Times", 15, QFont::Bold));
    score->setFixedSize(150, 50);


    score->setText("Score : " + QString::number(Brick::score));

    balles = new QList<Ball*>;
    Ball* ball = new Ball();
    balles->append(ball);
    items.append(ball);
    scene->addItem(ball->getItem());

    QVector<int> s_bricks;
    int cpt = 0;
    for(int i = 0 ; i < lvl_special_bricks ; i++)
    {
        s_bricks.append(qrand() % 156 +1);
    }
    for(int x = -300; x < 300; x = x + 50)
    {
        for(int y = -700; y < -300; y = y + 30)
        {
            if(s_bricks.contains(cpt))
            {
                GameObject* brick = new Br_Ball(balles, x, y);
                QObject::connect(brick, SIGNAL(new_Ball(Brick*)), this, SLOT(m_add_Ball(Brick*)));
                //QObject::connect(brick, SIGNAL(brick_broken(Brick*)), this, SLOT(m_brick_broken(Brick*)));
                items.append(brick);
                scene->addItem(brick->getItem());
            }else
            {
                GameObject* brick = new Brick(balles, x, y);
                QObject::connect(brick, SIGNAL(brick_broken(Brick*)), this, SLOT(m_brick_broken(Brick*)));
                items.append(brick);
                scene->addItem(brick->getItem());
            }
            cpt ++;
        }
    }

    racket = new Racket(balles);
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
    view->move(-3,50);

    view->show();

    timer->start(speed);

    connect(timer, SIGNAL(timeout()), this, SLOT(m_update()));
    QObject::connect(ball, SIGNAL(lose_ball(Ball*)), this, SLOT(lost_Ball(Ball*)));

}

MainWindow::~MainWindow()
{

}

void MainWindow::m_add_Ball(Brick* b)
{
    Ball* ball = new Ball(racket->getx()+25, racket->gety()-20);
    balles->append(ball);
    items.append(ball);
    scene->addItem(ball->getItem());
    QObject::connect(ball, SIGNAL(lose_ball(Ball*)), this, SLOT(lost_Ball(Ball*)));

    m_brick_broken(b);
}

void MainWindow::m_update()
{
    QList<GameObject*>::iterator gameObject;
    for(gameObject = items.begin(); gameObject != items.end(); gameObject++){
        (*gameObject)->update();
    }
    score->setText("Score : " + QString::number(Brick::score));

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
    if(event->nativeScanCode() == 74 )
    {
        speed = speed +1;
        timer->setInterval(speed);
    }
    if(event->nativeScanCode() == 78 )
    {
        speed = speed -1;
        timer->setInterval(speed);
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

void MainWindow::m_brick_broken(Brick* b)
{
    int index = items.indexOf(b);
    items.removeAt(index);
    scene->removeItem(b->getItem());

    delete b;
}

void MainWindow::lost_Ball(Ball* ball)
{
    int index = balles->indexOf(ball);
    scene->removeItem(ball->getItem());
    balles->removeAt(index);

    index = items.indexOf(ball);
    items.removeAt(index);

    delete ball;

    if(balles->size() < 1)
    {

    }
}

