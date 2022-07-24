#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QString>

class Enemy : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int last_move;
    int image_order;
    QString color_choice;

public:
    Enemy();

public slots:
    void move();
    void update_pixmap();
    int one_in_twenty_choice();
};

#endif // ENEMY_H
