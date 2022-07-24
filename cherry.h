#ifndef CHERRY_H
#define CHERRY_H


#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QString>

class Cherry: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

private:
    int move_step;

public:
    Cherry(QGraphicsItem * parent=0);

public slots:
    void move();

};

#endif // CHERRY_H
