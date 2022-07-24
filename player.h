#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <string>

class Player: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

private:
    int image_order;
    int move_order;
    int counter = 0;
    std::string direction;

public:
    Player(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    bool has_bomb = false;

public slots:
    void update_pixmap();
    void spawn_cherry();
    void move();
    void put_bomb();
};

#endif // PLAYER_H
