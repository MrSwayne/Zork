#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include "item.h"

class Inventory {
public:
    Inventory(int carryCapacity);
    void drop(Item *i);
    bool pickUp(Item *i);
    int getWeight();
    int getCapacity();
    void empty();
private:
    std::vector<Item*> inventory;
    int weight;
    int carryCapacity;
};

#endif // INVENTORY_H
