#include <iostream>
#include <map>
#include <iterator>
#include <cstring>
#include <vector>

#ifndef ROOM_H
#define ROOM_H

using namespace std;

class Room{
 public:
  //function prototypes
  char* getName();
  void setName(char* newName);
  vector<char*>* getItems();
  void addItem(char* itemName);
  char* getDescription();
  void setDescription(char* newDesc);
  map<const char*, Room*>* getMap();
  void addExit(const char* direction, Room* newRoom);
 private:
  //room variables
  map<const char*, Room*> exits;
  char name[80];
  vector<char*> items;
  char description[1000];
};
#endif
