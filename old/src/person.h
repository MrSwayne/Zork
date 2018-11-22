#ifndef PERSON_H
#define PERSON_H

#include "sprite.h"
#include <unordered_map>
#include "inventory.h"


class Person : public Sprite {
public:
    Person(QString path, QString name,QString desc,int spawnX, int spawnY);
    void setDirection(std::string dir);
    void move(QPointF p);
    bool isDead();
    void hit(int n);
private:
    QImage *spriteSheet;
    std::unordered_map<std::string, QPixmap> pixmaps;
protected:
    QString name;
    enum eDirection {STOP = 0, NORTH, EAST, SOUTH, WEST};
    eDirection dir;
    int xVel;
    int yVel;
    int health;
    Inventory *inventory = nullptr;
};

#endif // PERSON_H
