#ifndef BLOCK_H
#define BLOCK_H

#include <QObject>
#include <QGraphicsItem>

class Block : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Block(int rx, int ry);
    ~Block();
};

#endif // BLOCK_H
