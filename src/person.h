#ifndef PERSON_H
#define PERSON_H

#include "sprite.h"
#include <unordered_map>
#include "inventory.h"


class Person : public Sprite {
public:
    Person(QString path, QString name,QString desc,int spawnX, int spawnY);
    void setDirection(std::string dir);
    void move(QPoint p);
private:
    enum eDirection {STOP = 0, NORTH, EAST, SOUTH, WEST};
    eDirection dir;
    int xVel;
    int yVel;
    QString name;
    QImage *spriteSheet;
    std::unordered_map<std::string, QPixmap> pixmaps;
    Inventory *inventory = nullptr;
    int health;

};

#endif // PERSON_H
