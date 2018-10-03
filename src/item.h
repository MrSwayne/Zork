#ifndef ITEM_H
#define ITEM_H

#include "sprite.h"

class Item : public Sprite {
public:
    Item(QString path, QString name, QString desc, int weight, int spawnX, int spawnY);
    int getWeight();
    QString getDescription();
private:
    int weight;
    QString name;
};

#endif // ITEM_H
