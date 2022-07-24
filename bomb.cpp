#include <QTimer>
#include <QDebug>
#include "bomb.h"
#include "game.h"
#include "block.h"
#include "player.h"

extern Game * game;

Bomb::Bomb(int rx, int ry)
{
    step = 0;

    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(evolute_step()));

    timer->start(100);

    setPos(rx, ry);

    setPixmap(QPixmap(":/images/bomb.png"));
}

void Bomb::evolute_step()
{
    if (step >= 0 && step <35){
        setPixmap(QPixmap(":/images/bomb.png"));
    } else if (step == 35){
        setPos(pos().x()-40, pos().y()-40);
        setPixmap(QPixmap(":/images/explosion_0.png"));
        QList<QGraphicsItem *> colliding_item = collidingItems();

        for (int i = 0, n = colliding_item.size(); i < n; i++)
        {
            if (typeid(*(colliding_item[i])) == typeid(Player))
            {
                game->gameover();
                return;
            } else if (typeid(*(colliding_item[i])) == typeid(Block)){
                delete colliding_item[i];

            }
        }

        game->player->has_bomb = false;

    } else if (step == 36){
        setPos(pos().x()+40, pos().y()+40);
        setPixmap(QPixmap(":/images/explosion_1.png"));
    } else if (step == 37){
        setPixmap(QPixmap(":/images/explosion_2.png"));
    } else if (step == 38){
        setPixmap(QPixmap(":/images/explosion_3.png"));
    } else if (step == 39){
        setPixmap(QPixmap(":/images/explosion_4.png"));
    } else if (step == 40){
        setPixmap(QPixmap(":/images/explosion_5.png"));
    } else {
        scene()->removeItem(this);
        delete this;
    }
    step++;
}
