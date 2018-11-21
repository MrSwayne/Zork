#include "door.h"
#include <iostream>

Door::Door(std::string direction) : Sprite(QString("Test"), QString("I wonder what's inside?"), 0, 0)
{
    this->direction = direction;
}

void Door::draw() {

}
