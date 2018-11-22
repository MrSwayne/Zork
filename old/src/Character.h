#ifndef CHARACTER_H_
#define CHARACTER_H_
#include "ZorkUL.h"

#include <string>
using namespace std;
#include <vector>
using std::vector;


class Character {
private:
	string description;
    vector < string > itemsInCharacter;
    string name;
public:
	void addItems(string Item);
public:
    Character(string name, string description, );
	string shortDescription();
	string longDescription();

};

#endif /*CHARACTER_H_*/
