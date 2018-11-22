#include "item.h"
  #include <QDebug>

Item::Item(QString description) : description(description)
{

}

QString Item::getDescription() const
{
    return description;
}

