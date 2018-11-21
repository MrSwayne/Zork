

#ifndef ROOM_H_
#define ROOM_H_

#include <map>
#include <string>
#include <vector>
#include "item.h"
#include "QGraphicsScene"
#include "person.h"
#include "player.h"
#include "door.h"

using namespace std;
using std::vector;

class Room : public QGraphicsScene {

private:
	string description;
	map<string, Room*> exits;
	string exitString();
    vector <Item*> itemsInRoom;
    vector <Person*> enemiesInRoom;
    vector <Door*> doorsInRoom;

    Player *player;
    QGraphicsScene *scene;
    void Room::createRoom();


public:
    int numberOfItems();
    Room(Player *player, QGraphicsScene *scene, string description, int WIDTH, int HEIGHT);
	void setExits(Room *north, Room *east, Room *south, Room *west);
	string shortDescription();
	string longDescription();
	Room* nextRoom(string direction);
    void addItem(Item *inItem);
    string displayItem();
    void draw();
    int WIDTH;
    int HEIGHT;
    int isItemInRoom(string inString);
    void removeItemFromRoom(int location);
    void destroy();
};

#endif

