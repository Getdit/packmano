#include <QGraphicsScene>
#include <QObject>
#include <QLabel>
#include <QGraphicsItem>
#include <QDebug>
#include <QKeyEvent>
#include <QVector>
#include <QTimer>

#include "player.h"
#include "game.h"
#include "cherry.h"
#include "enemy.h"
#include "bomb.h"
#include "goldapple.h"

extern Game * game;

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/packman_right_1.png"));
    image_order = 1;
    direction = "right";
    move_order = 0;

    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(update_pixmap()));

    timer->start(90);

    QTimer * timer1 = new QTimer();
    connect(timer1, SIGNAL(timeout()), this, SLOT(move()));

    timer1->start(40);
}


void Player::keyPressEvent(QKeyEvent *event)
{
    switch(event->key()) {

    case Qt::Key_Left:
        move_order = 1;
        break;
    case Qt::Key_Right:
        move_order = 2;
        break;
    case Qt::Key_Up:
        move_order = 3;
        break;
    case Qt::Key_Down:
        move_order = 4;
        break;
    case Qt::Key_Space:
        put_bomb();
        break;
    }

}

void Player::keyReleaseEvent(QKeyEvent *event)
{
    move_order = 0;
}


void Player::move()
{
    QVector<QVector<int>> mapa = game->get_mapa();

    if (move_order == 1)
    {
        direction = "left";
        int sec_x1 = (int) ((pos().x()-10)/40);
        int sec_y1 = (int) ((pos().y())/40);
        int sec_x2 = (int) ((pos().x()+12)/40);
        int sec_y2 = (int) ((pos().y()+22)/40);

        if(mapa.at(sec_y1).at(sec_x1) == 1 && mapa.at(sec_y1).at(sec_x2) == 1 && mapa.at(sec_y2).at(sec_x1) == 1 && mapa.at(sec_y2).at(sec_x2) == 1)
            setPos(x()-10, y());
    }
    else if(move_order == 2)
    {
        direction = "right";
        int sec_x1 = (int) ((pos().x()+10)/40);
        int sec_y1 = (int) ((pos().y())/40);
        int sec_x2 = (int) ((pos().x()+32)/40);
        int sec_y2 = (int) ((pos().y()+22)/40);

        if(mapa.at(sec_y1).at(sec_x1) == 1 && mapa.at(sec_y1).at(sec_x2) == 1 && mapa.at(sec_y2).at(sec_x1) == 1 && mapa.at(sec_y2).at(sec_x2) == 1)
            setPos(x()+10, y());
    }
    else if (move_order == 3)
    {
        int sec_x1 = (int) ((pos().x())/40);
        int sec_y1 = (int) ((pos().y()-10)/40);
        int sec_x2 = (int) ((pos().x()+22)/40);
        int sec_y2 = (int) ((pos().y()+12)/40);

        if(mapa.at(sec_y1).at(sec_x1) == 1 && mapa.at(sec_y1).at(sec_x2) == 1 && mapa.at(sec_y2).at(sec_x1) == 1 && mapa.at(sec_y2).at(sec_x2) == 1)
            setPos(x(), y()-10);
    }
    else if (move_order == 4)
    {
        int sec_x1 = (int) ((pos().x())/40);
        int sec_y1 = (int) ((pos().y()+10)/40);
        int sec_x2 = (int) ((pos().x()+22)/40);
        int sec_y2 = (int) ((pos().y()+32)/40);

        if(mapa.at(sec_y1).at(sec_x1) == 1 && mapa.at(sec_y1).at(sec_x2) == 1 && mapa.at(sec_y2).at(sec_x1) == 1 && mapa.at(sec_y2).at(sec_x2) == 1)
            setPos(x(), y()+10);
    }


    QList<QGraphicsItem *> colliding_item = collidingItems();

    for (int i = 0, n = colliding_item.size(); i < n; i++)
    {
        if (typeid(*(colliding_item[i])) == typeid(Enemy))
        {
            if (game->get_power_up_mode()){

            } else {
                game->gameover();
            }
            return;
        } else if (typeid(*(colliding_item[i])) == typeid(Cherry)){
            game->score->increase();
            game->score->increase();
            game->score->increase();
            delete colliding_item[i];

            spawn_cherry();
        } else if (typeid(*(colliding_item[i])) == typeid(GoldApple)){
            game->enable_power_up_mode();
            delete colliding_item[i];
        }
    }
}

void Player::update_pixmap()
{
    if (game->get_power_up_mode()){
        counter++;
        if(counter==200){
            game->disable_power_up_mode();
            counter = 0;
        }
    }
    if (image_order == 1)
    {
        image_order = 2;
        if (direction == "right")
        {
            setPixmap(QPixmap(":/images/packman_right_2.png"));
        } else {
            setPixmap(QPixmap(":/images/packman_left_2.png"));
        }


    }
    else if (image_order == 2)
    {
        image_order = 3;
        if (direction == "right")
        {
            setPixmap(QPixmap(":/images/packman_right_3.png"));
        } else {
            setPixmap(QPixmap(":/images/packman_left_3.png"));
        }
    }
    else if (image_order == 3)
    {
        image_order = 4;
        if (direction == "right")
        {
            setPixmap(QPixmap(":/images/packman_right_2.png"));
        } else {
            setPixmap(QPixmap(":/images/packman_left_2.png"));
        }
    }
    else
    {
        image_order = 1;
        if (direction == "right")
        {
            setPixmap(QPixmap(":/images/packman_right_1.png"));
        } else {
            setPixmap(QPixmap(":/images/packman_left_1.png"));
        }
    }
}

void Player::spawn_cherry()
{
    Cherry * ch = new Cherry();
    game->scene -> addItem(ch);
}

void Player::put_bomb()
{
    if (!has_bomb){
        has_bomb = true;
        scene()->addItem(new Bomb(pos().x(), pos().y()));
    }
}
