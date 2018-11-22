#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"
#include "item.h"
#include <vector>

#define NAME "Chris"



class Player : public Character
{
   friend QDebug &operator<<( QDebug &, Player & );

public:
    Player(QString name = NAME, int health=100, int attack = 5);
    int getAttack() const;
    void operator+(Item* item);
    Item* operator-(int index);
    const std::vector<Item*>& getPlayerItems() const;

private:
    std::vector<Item*> player_items;
    int key_counter;
};

#endif // PLAYER_H
