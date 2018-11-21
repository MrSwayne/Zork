#include "Room.h"

#include <iostream>
#include <string>

Door::Door(std::string direction) : Sprite(QString("test"), QString("I wonder what's inside?"), 0, 0 ) {
    int x = 0, y = 0;

    std::cout<< direction << std::endl;
}
