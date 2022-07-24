#ifndef GOLDAPPLE_H
#define GOLDAPPLE_H

#include <QObject>
#include <QGraphicsItem>

class GoldApple: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    GoldApple(int rx, int ry);
};

#endif // GOLDAPPLE_H
