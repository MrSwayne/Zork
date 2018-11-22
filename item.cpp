#include "item.h"
  #include <QDebug>

Item::Item(QString description) : description(description)
{
    if(description == QString::fromStdString("Sword"))
        this->attack = 10;
}

int Item::getAttack() {
    return attack;
}

QString Item::getDescription() const
{
    return description;
}

