#include <QDebug>
#include "block.h"
#include "game.h"

extern Game *game;

Block::Block(int rx, int ry)
{
    setPos(rx*40, ry*40);
    setPixmap(QPixmap(":/images/block.png"));
}


Block::~Block()
{
    game->enable_sector(pos().x()/40, pos().y()/40);
    scene()->removeItem(this);
}
