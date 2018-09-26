#include "inventory.h"
#include "item.h"

#define MAX_ITEMS 10

Inventory::Inventory(int carryCapacity) {
    this->weight = 0;
    this->carryCapacity = carryCapacity;
}

void Inventory::drop(Item *i) {

}

bool Inventory::pickUp(Item *i) {

    if((this->weight + i->getWeight() <= this->carryCapacity) && (this->inventory.size() < MAX_ITEMS)) {
        this->weight += i->getWeight();
        inventory.push_back(i);
        return true;
    }
    return false;
}

void Inventory::empty() {
    this->inventory.clear();
}

int Inventory::getWeight() {
    return this->weight;
}

int Inventory::getCapacity() {
    return this->carryCapacity;
}
