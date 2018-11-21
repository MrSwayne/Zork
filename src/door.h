#ifndef DOOR_H
#define DOOR_H

#include "sprite.h"
#include <string>

class Door : public Sprite {
public:
    Door(std::string direction);
};

#endif // DOOR_H
