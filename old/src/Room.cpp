#include "Room.h"
#include "Command.h"
#include "player.h"
#include <random>
#include <iostream>
//#include "enemy.h"
#include "item.h"
#include <string>
#include "door.h"
#include "config.h"

Room::Room(Player *player, QGraphicsScene *scene, string description, int width, int height) {
    this->player = player;
    this->scene = scene;
	this->description = description;
    this->WIDTH = width;
    this->HEIGHT = height;
    createRoom();
}

//Courtesy of https://stackoverflow.com/questions/7560114/random-number-c-in-some-range

void Room::createRoom() {
    std::random_device rd; //Obtain random num from hardware
    std::mt19937 eng(rd()); //Seeds the generator
    std::uniform_int_distribution<> widthDistr(0, WIDTH);   //range
    std::uniform_int_distribution<> heightDistr(0, HEIGHT);

    std::uniform_int_distribution<> enemiesDistr(0, 5);
    int numEnemies = enemiesDistr(eng);

    std::uniform_int_distribution<> itemsDistr(0, 3);
    int numItems = itemsDistr(eng);

    Config cfg = Config::getInstance();

    for(int i = 0;i < numItems;i++) {
       QString path = QString::fromStdString(cfg.get("path") + "/res/images/sprites/item.jpg");
       Item *item = new Item(path, QString("Item"), QString("an item"), 10, 10, 10);
       itemsInRoom.push_back(item);
      // QString path, QString name, QString desc, int weight,int spawnX, int spawnY
    }
}

void Room::setExits(Room *north, Room *east, Room *south, Room *west) {
	if (north != NULL)
		exits["north"] = north;
	if (east != NULL)
		exits["east"] = east;
	if (south != NULL)
		exits["south"] = south;
	if (west != NULL)
		exits["west"] = west;
}

void Room::destroy() {
    vector <Item*> itemsInRoom;

    for(Person *enemy: this->enemiesInRoom) {
        this->scene->removeItem(enemy);
        delete enemy;
    }

    for(Item *item: this->itemsInRoom) {
        this->scene->removeItem(item);
        delete item;
    }

    for(Door *door: this->doorsInRoom) {
        this->scene->removeItem(door);
        delete door;
    }

    this->scene->removeItem(player);

    this->enemiesInRoom.clear();
    this->itemsInRoom.clear();
    this->doorsInRoom.clear();
}

#include "config.h"

void Room::draw() {
    Config cfg = Config::getInstance();

    scene->setBackgroundBrush(QBrush(QImage(QString::fromStdString(cfg.get("path") + "/res/images/room.jpg"))));


    std::string rooms[4] = {"north", "south", "east", "west"};
    for(int i = 0;i < 4;i++) {
        if(exits[rooms[i]] != NULL ) {
            Door* door = new Door(rooms[i]);
            scene->addItem(door);
            door->draw();
        }
    }

    for(Person *enemy: this->enemiesInRoom) {
        scene->addItem(enemy);
        enemy->draw();
    }

    for(Item *item: this->itemsInRoom) {
        scene->addItem(item);
        item->draw();
    }

    scene->addItem(player);
}

/*
string Room::shortDescription() {
	return description;
}

string Room::longDescription() {
	return "room = " + description + ".\n" + displayItem() + exitString();
}

string Room::exitString() {
	string returnString = "\nexits =";
	for (map<string, Room*>::iterator i = exits.begin(); i != exits.end(); i++)
		// Loop through map
		returnString += "  " + i->first;	// access the "first" element of the pair (direction as a string)
	return returnString;
}

Room* Room::nextRoom(string direction) {
	map<string, Room*>::iterator next = exits.find(direction); //returns an iterator for the "pair"
	if (next == exits.end())
		return NULL; // if exits.end() was returned, there's no room in that direction.
	return next->second; // If there is a room, remove the "second" (Room*)
				// part of the "pair" (<string, Room*>) and return it.
}

void Room::addItem(Item *inItem) {
    //cout <<endl;
    //cout << "Just added" + inItem->getLongDescription();
    itemsInRoom.push_back(*inItem);
}

string Room::displayItem() {
    string tempString = "items in room = ";
    int sizeItems = (itemsInRoom.size());
    if (itemsInRoom.size() < 1) {
        tempString = "no items in room";
        }
    else if (itemsInRoom.size() > 0) {
       int x = (0);
        for (int n = sizeItems; n > 0; n--) {
            tempString = tempString + (itemsInRoom[x].getDescription().toStdString());
            x++;
            }
        }
    return tempString;
    }

int Room::numberOfItems() {
    return itemsInRoom.size();
}

int Room::isItemInRoom(string inString)
{
    int sizeItems = (itemsInRoom.size());
    if (itemsInRoom.size() < 1) {
        return false;
        }
    else if (itemsInRoom.size() > 0) {
       int x = (0);
        for (int n = sizeItems; n > 0; n--) {
            // compare inString with short description
            int tempFlag = inString.compare( itemsInRoom[x].getDescription().toStdString());
            if (tempFlag == 0) {
                itemsInRoom.erase(itemsInRoom.begin()+x);
                return x;
            }
            x++;
            }
        }
    return -1;
}
*/
