#include "goldapple.h"

GoldApple::GoldApple(int rx, int ry)
{
    setPos(rx*40, ry*40);

    setPixmap(QPixmap(":/images/gold_apple.png"));
    show();

}
