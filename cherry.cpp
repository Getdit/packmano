#include <QGraphicsScene>
#include <QObject>
#include <QLabel>
#include <QGraphicsItem>
#include <QDebug>
#include <QKeyEvent>
#include <QVector>
#include <QTimer>
#include <random>

#include "cherry.h"
#include "game.h"

extern Game* game;

Cherry::Cherry(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    bool not_positioned = true;
    QVector<QVector<int>> mapa = game->get_mapa();

    while (not_positioned){
        for (int ry=1; ry < 15; ry++){
            for (int rx=1; rx < 20; rx++){
                if (mapa.at(ry).at(rx)==1 && not_positioned){
                    std::random_device random_d;
                    std::mt19937 generator(random_d());
                    std::uniform_int_distribution<> distributor(0, 24);

                    if (distributor(generator) == 11){
                        setPos(rx*40, ry*40);
                        not_positioned = false;
                    }
                }
            }
        }
    }

    setPixmap(QPixmap(":/images/cherry.png"));

    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(70);

    move_step = 0;
}

void Cherry::move()
{

    if (move_step == 0)
    {
        setPos(x(), y()-4);
        move_step = 1;
    }

    else if (move_step == 1)
    {
        setPos(x(), y()-3);
        move_step = 2;
    }

    else if (move_step == 2)
    {
        setPos(x(), y()-2);
        move_step = 3;
    }

    else if (move_step == 3)
    {
        setPos(x(), y()-1);
        move_step = 4;
    }

    else if (move_step == 4)
    {
        setPos(x(), y()+1);
        move_step = 5;
    }

    else if (move_step == 5)
    {
        setPos(x(), y()+2);
        move_step = 6;
    }

    else if (move_step == 6)
    {
        setPos(x(), y()+3);
        move_step = 7;
    }

    else if (move_step == 7)
    {
        setPos(x(), y()+4);
        move_step = 8;
    }

    else if (move_step == 8)
    {
        setPos(x(), y()-4);
        move_step = 9;
    }

    else if (move_step == 9)
    {
        setPos(x(), y()-3);
        move_step = 10;
    }

    else if (move_step == 10)
    {
        setPos(x(), y()-2);
        move_step = 11;
    }

    else if (move_step == 11)
    {
        setPos(x(), y()+2);
        move_step = 12;
    }

    else if (move_step == 12)
    {
        setPos(x(), y()+3);
        move_step = 13;
    }

    else if (move_step == 13)
    {
        setPos(x(), y()+4);
        move_step = 14;
    }

    else if (move_step == 14)
    {
        setPos(x(), y()-4);
        move_step = 15;
    }

    else if (move_step == 15)
    {
        setPos(x(), y()-3);
        move_step = 16;
    }

    else if (move_step == 16)
    {
        setPos(x(), y()+3);
        move_step = 17;
    }

    else if (move_step == 17)
    {
        setPos(x(), y()+4);
        move_step = 18;
    }

    else if (move_step == 18)
    {
        setPos(x(), y()-4);
        move_step = 19;
    }

    else if (move_step == 19)
    {
        setPos(x(), y()+4);
        move_step = 20;
    }

    else if (move_step == 20)
    {
        setPos(x(), y()-3);
        move_step = 21;
    }

    else if (move_step == 21)
    {
        setPos(x(), y()-2);
        move_step = 22;
    }

    else if (move_step == 22)
    {
        setPos(x(), y()-1);
        move_step = 23;
    }

    else if (move_step == 23)
    {
        setPos(x(), y()+1);
        move_step = 24;
    }

    else if (move_step == 24)
    {
        setPos(x(), y()+2);
        move_step = 25;
    }

    else if (move_step == 25)
    {
        setPos(x(), y()+3);
        move_step = 26;
    }

    else if (move_step == 26)
    {
        setPos(x(), y()-2);
        move_step = 27;
    }

    else if (move_step == 27)
    {
        setPos(x(), y()-1);
        move_step = 28;
    }

    else if (move_step == 28)
    {
        setPos(x(), y()+1);
        move_step = 29;
    }

    else if (move_step == 29)
    {
        setPos(x(), y()+2);
        move_step = 30;
    }

    else if (move_step == 30)
    {
        setPos(x(), y()-1);
        move_step = 31;
    }

    else if (move_step == 31)
    {
        setPos(x(), y()+1);
        move_step = 32;
    }

    else if (move_step == 32)
    {
        setPos(x(), y()-1);
        move_step = 33;
    }

    else if (move_step == 33)
    {
        setPos(x(), y()+1);
        move_step = 34;
    }

    else if (move_step == 34)
    {
        setPos(x(), y()-1);
        move_step = 35;
    }

    else if (move_step == 35)
    {
        setPos(x(), y()+1);
        move_step = 36;
    }

    else if (move_step >= 36 && move_step < 100)
    {
        move_step++;
    }

    else if (move_step == 100)
    {
        move_step = 0;
    }


}
