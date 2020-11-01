#include <iostream>
#include <map>
#include <iterator>
#include <cstring>
#include <vector>
#include "Room.h"

using namespace std;

char* Room::getName(){
  return name;
}

void Room::setName(char* newName){
  strcpy(name, newName);
}

vector<char*>* Room::getItems(){
  return &items;
}

void Room::addItem(char* itemName){
  items.push_back(itemName);
}

char* Room::getDescription(){
  return description;
}

void Room::setDescription(char* newDesc){
  strcpy(description, newDesc);
}

map<const char*, Room*>* Room::getMap(){
  return &exits;
}

void Room::addExit(const char* direction, Room* newRoom){
  exits.insert(pair<const char*, Room*>(direction, newRoom));
}
