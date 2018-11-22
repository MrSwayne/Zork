#include "player.h"
#include <QDebug>

Player::Player(QString name, int health, int attack): Character(name, health, attack), key_counter(0)
{

}

int Player::getAttack() const
{
    return attack;
}

void Player::operator+(Item* item)
{
    //adds item to player Inv
    player_items.push_back(item);

    if(item->getDescription().contains("key"))
        //adds to key check which would eventually lead to a game win.
        key_counter++;
}

Item* Player::operator-(int index)
{
    Item* temp = player_items[index];
    player_items.erase(player_items.begin() + index);

    if(temp->getDescription().contains("key"))
        key_counter--;

    return temp;
}

const std::vector<Item*>& Player::getPlayerItems() const
{
    return player_items;
}

//QDebug prints to the QT console.
QDebug &operator<<( QDebug &out, Player &P )
{
  out << "Name -- " << P.getName() << "\nHealth -- " << P.getHealth();
  return out;
}
