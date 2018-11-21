#ifndef DOOR_H
#define DOOR_H

#include "sprite.h"

class Door : public Sprite
{
public:
    Door(std::string direction);
    void draw();
private:
    std::string direction;
};

#endif // DOOR_H
