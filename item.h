#ifndef ITEM_H
#define ITEM_H

#include <QString>

class Item
{
  friend QDebug &operator<<( QDebug &, Item & );
public:
    Item (QString description);
    QString getDescription() const;
    int getAttack();

private:
    QString description;
    int attack;
};

#endif // ITEM_H
