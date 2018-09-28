#ifndef PLAYER_H
#define PLAYER_H

#include "sprite.h"
#include "person.h"
#include "inventory.h"
#include <QKeyEvent>

class Player : public Person {
public:
    Player(QString path, QString name, QString desc, int spawnX, int spawnY);
    void addScore(int n);
    void keyRelease(QKeyEvent *event);
    void keyPress(QKeyEvent *event);

private:
    int score;
};

#endif // PLAYER_H
