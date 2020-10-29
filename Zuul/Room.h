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
  Room* getNorth(Room* newRoom);
  Room* getSouth(Room* newRoom);
  Room* getEast(Room* newRoom);
  Room* getWest(Room* newRoom);
  char* getName(Room* newRoom);
  char* getItems(vector<char*> newItems);
  char* getDescription(Room* newRoom);
 private:
  map<char*, Room*> exits;
  char name[80];
  vector<char*> items;
  char description[1000];
};
#endif
