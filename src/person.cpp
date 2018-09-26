#include "person.h"


//Hashmap implementation : https://stackoverflow.com/questions/2179946/i-would-like-to-see-a-hash-map-example-in-c


Person::Person(QString path, QString name, QString desc, int spawnX, int spawnY) : Sprite(path, desc, spawnX, spawnY) {
    setDirection("STOP");

    spriteSheet = new QImage(path);
    QPixmap map = QPixmap::fromImage(spriteSheet->copy(88,56,88,56));

    this->pixmaps["STOP"] = map;
    this->setPixmap(map);

    this->name = name;
}


void Person::move(QPoint p) {
    this->setPos(p);
}

void Person::setDirection(std::string str) {
    if     (str == "NORTH")  dir = NORTH;
    else if(str == "EAST")   dir = EAST;
    else if(str == "SOUTH")  dir = SOUTH;
    else if(str == "WEST")   dir = WEST;
    else                     dir = STOP;
}