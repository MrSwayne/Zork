#include "sprite.h"

#include <iostream>
#include <QtWidgets>

Sprite::Sprite(QString path, QString desc, int spawnX, int spawnY) {
    this->desc = desc;
    this->x = spawnX;
    this->y = spawnY;
}

void Sprite::spawn() {

}

void Sprite::draw() {

}
