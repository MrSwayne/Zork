#include "item.h"

Item::Item(QString path, QString name, QString desc, int weight,int spawnX, int spawnY) : Sprite(path, desc, spawnX, spawnY) {
    this->name = name;
    this->desc = desc;
    this->weight = weight;
}

int Item::getWeight() {
    return this->weight;
}

QString Item::getDescription() {
    return this->desc;
}
