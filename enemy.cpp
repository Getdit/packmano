#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>
#include <QDebug>
#include <random>
#include "enemy.h"
#include "game.h"

extern Game * game;

Enemy::Enemy()
{
    QVector<QVector<int>> mapa = game->get_mapa();
    bool not_positioned = true;

    while (not_positioned){
        for (int ry=1; ry < 15; ry++){
            for (int rx=1; rx < 20; rx++){
                if (not_positioned && mapa.at(ry).at(rx)==1 && !(ry == 7 && (rx == 7 || rx == 8 || rx == 9 || rx == 10 || rx == 11 || rx == 12)) && !(ry == 6 && (rx == 9 || rx == 10)) && !(ry == 8 && (rx == 9 || rx == 10)) ){
                    std::random_device random_d;
                    std::mt19937 generator(random_d());
                    std::uniform_int_distribution<> distributor(0, 24);

                    if (distributor(generator) == 11){
                        setPos(rx*40+10, ry*40+10);
                        not_positioned = false;
                    }
                }
            }
        }
    }

    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(110);

    QTimer * timer1 = new QTimer();
    connect(timer1, SIGNAL(timeout()), this, SLOT(update_pixmap()));

    timer1->start(420);

    last_move = 1;
    image_order = 1;

    std::random_device random_d1;
    std::mt19937 generator1(random_d1());
    std::uniform_int_distribution<> distributor1(1, 3);

    int color = distributor1(generator1) ;

    if (color == 1) {
        color_choice = "green";
    } else if (color == 2) {
        color_choice = "purple";
    } else if (color == 3) {
        color_choice = "red";
    }

    setPixmap(QPixmap(":/images/"+color_choice+"_ghost_1.png"));
}


void Enemy::move()
{
    QVector<QVector<int>> mapa = game->get_mapa();

    int choice = last_move;
    int random_move = one_in_twenty_choice();
    bool collided = false;

    if (random_move == 3 || random_move == 12){
        choice -= 2;
        if (choice == 0)
        {
            choice = 4;
        } else if (choice == -1)
        {
            choice = 3;
        }
    } else if (random_move == 5 || random_move == 14){
        choice += 1;
        if (choice == 5)
            choice = 1;
    }

    if (choice == 1)
    {
        int sec_x1 = (int) ((pos().x()-10)/40);
        int sec_y1 = (int) ((pos().y())/40);
        int sec_x2 = (int) ((pos().x()+12)/40);
        int sec_y2 = (int) ((pos().y()+22)/40);

        if(mapa.at(sec_y1).at(sec_x1) == 1 && mapa.at(sec_y1).at(sec_x2) == 1 && mapa.at(sec_y2).at(sec_x1) == 1 && mapa.at(sec_y2).at(sec_x2) == 1)
        {
            setPos(x()-10, y());
        } else
        {
            collided = true;
        }
    }
    else if(choice == 3)
    {
        int sec_x1 = (int) ((pos().x()+10)/40);
        int sec_y1 = (int) ((pos().y())/40);
        int sec_x2 = (int) ((pos().x()+32)/40);
        int sec_y2 = (int) ((pos().y()+22)/40);

        if(mapa.at(sec_y1).at(sec_x1) == 1 && mapa.at(sec_y1).at(sec_x2) == 1 && mapa.at(sec_y2).at(sec_x1) == 1 && mapa.at(sec_y2).at(sec_x2) == 1)
        {
            setPos(x()+10, y());
        } else
        {
            collided = true;
        }
    }
    else if (choice == 4)
    {
        int sec_x1 = (int) ((pos().x())/40);
        int sec_y1 = (int) ((pos().y()-10)/40);
        int sec_x2 = (int) ((pos().x()+22)/40);
        int sec_y2 = (int) ((pos().y()+12)/40);

        if(mapa.at(sec_y1).at(sec_x1) == 1 && mapa.at(sec_y1).at(sec_x2) == 1 && mapa.at(sec_y2).at(sec_x1) == 1 && mapa.at(sec_y2).at(sec_x2) == 1)
        {
            setPos(x(), y()-10);
        } else
        {
            collided = true;
        }
    }
    else if (choice == 2)
    {
        int sec_x1 = (int) ((pos().x())/40);
        int sec_y1 = (int) ((pos().y()+10)/40);
        int sec_x2 = (int) ((pos().x()+22)/40);
        int sec_y2 = (int) ((pos().y()+32)/40);

        if(mapa.at(sec_y1).at(sec_x1) == 1 && mapa.at(sec_y1).at(sec_x2) == 1 && mapa.at(sec_y2).at(sec_x1) == 1 && mapa.at(sec_y2).at(sec_x2) == 1)
        {
            setPos(x(), y()+10);
        } else
        {
            collided = true;
        }
    }
    if (collided) {
        collided = false;
        choice += 1;
        if (choice == 5)
            choice = 1;

        if (choice == 1)
        {
            int sec_x1 = (int) ((pos().x()-10)/40);
            int sec_y1 = (int) ((pos().y())/40);
            int sec_x2 = (int) ((pos().x()+12)/40);
            int sec_y2 = (int) ((pos().y()+22)/40);

            if(mapa.at(sec_y1).at(sec_x1) == 1 && mapa.at(sec_y1).at(sec_x2) == 1 && mapa.at(sec_y2).at(sec_x1) == 1 && mapa.at(sec_y2).at(sec_x2) == 1)
            {
                setPos(x()-10, y());
            } else
            {
                collided = true;
            }
        }
        else if(choice == 3)
        {
            int sec_x1 = (int) ((pos().x()+10)/40);
            int sec_y1 = (int) ((pos().y())/40);
            int sec_x2 = (int) ((pos().x()+32)/40);
            int sec_y2 = (int) ((pos().y()+22)/40);

            if(mapa.at(sec_y1).at(sec_x1) == 1 && mapa.at(sec_y1).at(sec_x2) == 1 && mapa.at(sec_y2).at(sec_x1) == 1 && mapa.at(sec_y2).at(sec_x2) == 1)
            {
                setPos(x()+10, y());
            } else
            {
                collided = true;
            }
        }
        else if (choice == 4)
        {
            int sec_x1 = (int) ((pos().x())/40);
            int sec_y1 = (int) ((pos().y()-10)/40);
            int sec_x2 = (int) ((pos().x()+22)/40);
            int sec_y2 = (int) ((pos().y()+12)/40);

            if(mapa.at(sec_y1).at(sec_x1) == 1 && mapa.at(sec_y1).at(sec_x2) == 1 && mapa.at(sec_y2).at(sec_x1) == 1 && mapa.at(sec_y2).at(sec_x2) == 1)
            {
                setPos(x(), y()-10);
            } else
            {
                collided = true;
            }
        }
        else if (choice == 2)
        {
            int sec_x1 = (int) ((pos().x())/40);
            int sec_y1 = (int) ((pos().y()+10)/40);
            int sec_x2 = (int) ((pos().x()+22)/40);
            int sec_y2 = (int) ((pos().y()+32)/40);

            if(mapa.at(sec_y1).at(sec_x1) == 1 && mapa.at(sec_y1).at(sec_x2) == 1 && mapa.at(sec_y2).at(sec_x1) == 1 && mapa.at(sec_y2).at(sec_x2) == 1)
            {
                setPos(x(), y()+10);
            } else
            {
                collided = true;
            }
        }

        if (collided) {
            collided = false;
            choice -= 2;
            if (choice == 0)
            {
                choice = 4;
            } else if (choice == -1)
            {
                choice = 3;
            }

            if (choice == 1)
            {
                int sec_x1 = (int) ((pos().x()-10)/40);
                int sec_y1 = (int) ((pos().y())/40);
                int sec_x2 = (int) ((pos().x()+12)/40);
                int sec_y2 = (int) ((pos().y()+22)/40);

                if(mapa.at(sec_y1).at(sec_x1) == 1 && mapa.at(sec_y1).at(sec_x2) == 1 && mapa.at(sec_y2).at(sec_x1) == 1 && mapa.at(sec_y2).at(sec_x2) == 1)
                {
                    setPos(x()-10, y());
                } else
                {
                    collided = true;
                }
            }
            else if(choice == 3)
            {
                int sec_x1 = (int) ((pos().x()+10)/40);
                int sec_y1 = (int) ((pos().y())/40);
                int sec_x2 = (int) ((pos().x()+32)/40);
                int sec_y2 = (int) ((pos().y()+22)/40);

                if(mapa.at(sec_y1).at(sec_x1) == 1 && mapa.at(sec_y1).at(sec_x2) == 1 && mapa.at(sec_y2).at(sec_x1) == 1 && mapa.at(sec_y2).at(sec_x2) == 1)
                {
                    setPos(x()+10, y());
                } else
                {
                    collided = true;
                }
            }
            else if (choice == 4)
            {
                int sec_x1 = (int) ((pos().x())/40);
                int sec_y1 = (int) ((pos().y()-10)/40);
                int sec_x2 = (int) ((pos().x()+22)/40);
                int sec_y2 = (int) ((pos().y()+12)/40);

                if(mapa.at(sec_y1).at(sec_x1) == 1 && mapa.at(sec_y1).at(sec_x2) == 1 && mapa.at(sec_y2).at(sec_x1) == 1 && mapa.at(sec_y2).at(sec_x2) == 1)
                {
                    setPos(x(), y()-10);
                } else
                {
                    collided = true;
                }
            }
            else if (choice == 2)
            {
                int sec_x1 = (int) ((pos().x())/40);
                int sec_y1 = (int) ((pos().y()+10)/40);
                int sec_x2 = (int) ((pos().x()+22)/40);
                int sec_y2 = (int) ((pos().y()+32)/40);

                if(mapa.at(sec_y1).at(sec_x1) == 1 && mapa.at(sec_y1).at(sec_x2) == 1 && mapa.at(sec_y2).at(sec_x1) == 1 && mapa.at(sec_y2).at(sec_x2) == 1)
                {
                    setPos(x(), y()+10);
                } else
                {
                    collided = true;
                }
            }

            if (collided) {
                choice -= 1;
                if (choice == 0)
                {
                    choice = 4;
                }

                if (choice == 1)
                {
                    int sec_x1 = (int) ((pos().x()-10)/40);
                    int sec_y1 = (int) ((pos().y())/40);
                    int sec_x2 = (int) ((pos().x()+12)/40);
                    int sec_y2 = (int) ((pos().y()+22)/40);

                    if(mapa.at(sec_y1).at(sec_x1) == 1 && mapa.at(sec_y1).at(sec_x2) == 1 && mapa.at(sec_y2).at(sec_x1) == 1 && mapa.at(sec_y2).at(sec_x2) == 1)
                    {
                        setPos(x()-10, y());
                    }
                }
                else if(choice == 3)
                {
                    int sec_x1 = (int) ((pos().x()+10)/40);
                    int sec_y1 = (int) ((pos().y())/40);
                    int sec_x2 = (int) ((pos().x()+32)/40);
                    int sec_y2 = (int) ((pos().y()+22)/40);

                    if(mapa.at(sec_y1).at(sec_x1) == 1 && mapa.at(sec_y1).at(sec_x2) == 1 && mapa.at(sec_y2).at(sec_x1) == 1 && mapa.at(sec_y2).at(sec_x2) == 1)
                    {
                        setPos(x()+10, y());
                    }
                }
                else if (choice == 4)
                {
                    int sec_x1 = (int) ((pos().x())/40);
                    int sec_y1 = (int) ((pos().y()-10)/40);
                    int sec_x2 = (int) ((pos().x()+22)/40);
                    int sec_y2 = (int) ((pos().y()+12)/40);

                    if(mapa.at(sec_y1).at(sec_x1) == 1 && mapa.at(sec_y1).at(sec_x2) == 1 && mapa.at(sec_y2).at(sec_x1) == 1 && mapa.at(sec_y2).at(sec_x2) == 1)
                    {
                        setPos(x(), y()-10);
                    }
                }
                else if (choice == 2)
                {
                    int sec_x1 = (int) ((pos().x())/40);
                    int sec_y1 = (int) ((pos().y()+10)/40);
                    int sec_x2 = (int) ((pos().x()+22)/40);
                    int sec_y2 = (int) ((pos().y()+32)/40);

                    if(mapa.at(sec_y1).at(sec_x1) == 1 && mapa.at(sec_y1).at(sec_x2) == 1 && mapa.at(sec_y2).at(sec_x1) == 1 && mapa.at(sec_y2).at(sec_x2) == 1)
                    {
                        setPos(x(), y()+10);
                    }
                }

            }
        }
    }

    last_move = choice;

}

int Enemy::one_in_twenty_choice()
{
    return rand() % 20;
}

void Enemy::update_pixmap()
{
    if (game->get_power_up_mode()){
        if (color_choice == "green"){
            color_choice = "purple";
        } else if (color_choice == "purple"){
            color_choice = "red";
        } else {
            color_choice = "green";
        }
    }
    if (image_order == 1)
    {
        image_order = 2;
        setPixmap(QPixmap(":/images/"+color_choice+"_ghost_2.png"));
    }
    else if (image_order == 2)
    {
        image_order = 3;
        setPixmap(QPixmap(":/images/"+color_choice+"_ghost_3.png"));
    }
    else if (image_order == 3)
    {
        image_order = 4;
        setPixmap(QPixmap(":/images/"+color_choice+"_ghost_2.png"));
    }
    else
    {
        image_order = 1;
        setPixmap(QPixmap(":/images/"+color_choice+"_ghost_1.png"));
    }

}


