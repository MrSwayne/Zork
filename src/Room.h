

#ifndef ROOM_H_
#define ROOM_H_

#include <map>
#include <string>
#include <vector>
#include "item.h"
#include "QGraphicsScene"

using namespace std;
using std::vector;

class Room : public QGraphicsScene {

private:
	string description;
	map<string, Room*> exits;
	string exitString();
    vector <Item> itemsInRoom;


public:
    int numberOfItems();
    Room(string description, int WIDTH, int HEIGHT);
	void setExits(Room *north, Room *east, Room *south, Room *west);
	string shortDescription();
	string longDescription();
	Room* nextRoom(string direction);
    void addItem(Item *inItem);
    string displayItem();
    int WIDTH;
    int HEIGHT;
    int isItemInRoom(string inString);
    void removeItemFromRoom(int location);
};

#endif

