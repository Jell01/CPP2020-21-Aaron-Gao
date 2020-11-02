#include <iostream>
#include <map>
#include <iterator>
#include <cstring>
#include <vector>
#include "Room.h"

using namespace std;

//initializing all the room functions 
char* Room::getName(){//returns the name of a room
  return name;
}

void Room::setName(char* newName){//sets the name of the room
  strcpy(name, newName);
}

vector<char*>* Room::getItems(){//returns a vector of items for a room
  return &items;
}

void Room::addItem(char* itemName){//adds items to a room
  items.push_back(itemName);
}

char* Room::getDescription(){//returns the description
  return description;
}

void Room::setDescription(char* newDesc){//sets the description of a room
  strcpy(description, newDesc);
}

map<const char*, Room*>* Room::getMap(){//returns the exits of a room
  return &exits;
}

void Room::addExit(const char* direction, Room* newRoom){//adds an exit to a room
  exits.insert(pair<const char*, Room*>(direction, newRoom));
}
