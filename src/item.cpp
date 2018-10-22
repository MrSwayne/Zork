#include "item.h"

Item::Item(QString path, QString name, QString desc, int weight,int spawnX, int spawnY) : Sprite(path, desc, spawnX, spawnY) {
    this->name = name;
    this->desc = desc;
    this->weight = weight;
}

bool Item::operator==(const std::string& name){
    if(this->getName().compare(name)==0)
        return 1;

    else
        return 0;

}

std::string Item::getName() {
    return this->name.toStdString();
}

int Item::getWeight() {
    return this->weight;
}

QString Item::getDescription() {
    return this->desc;
}
