#include "player.h"
#include <iostream>


Player::Player(QString path, QString name, QString desc, int spawnX, int spawnY) : Person(path, name, desc, spawnX, spawnY) {
    score = 0;
}

void Player::addScore(int n) {
    score += n;
}

void Player::keyRelease(QKeyEvent *event) {
    event->key();

    //std::cout << "release " << event->key() << std::endl;

    if (event->key() == Qt::Key_W) {
        xVel = 1;
    }
    if (event->key() == Qt::Key_A){
    }
    if (event->key() == Qt::Key_D) {
    }
    if (event->key() == Qt::Key_S) {
    }
}

void Player::keyPress(QKeyEvent *event) {
    event->key();

    //std::cout << "press" << event->key() << std::endl;

         //Rough Movement, to be updated...

    if (event->key() == Qt::Key_A) {
        setPos(pos().x()-10,pos().y());
    }
    if (event->key() == Qt::Key_D){
        setPos(pos().x()+10,pos().y());
    }
    if (event->key() == Qt::Key_W) {
        setPos(pos().x(),pos().y()-10);
    }
    if (event->key() == Qt::Key_S){
        setPos(pos().x(),pos().y()+10);

    }
}
