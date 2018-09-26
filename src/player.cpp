#include "player.h"
#include <iostream>


Player::Player(QString path, QString name, QString desc, int spawnX, int spawnY) : Person(path, name, desc, spawnX, spawnY) {
    score = 0;
}

void Player::addScore(int n) {
    score += n;
}
