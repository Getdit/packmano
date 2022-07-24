#ifndef BOMB_H
#define BOMB_H

#include <QObject>
#include <QGraphicsItem>

class Bomb : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int step;

public:
    Bomb(int rx, int ry);

public slots:
    void  evolute_step();
};

#endif // BOMB_H
