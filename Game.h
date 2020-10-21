#include <iostream>
#include <cstring>
#include "Media.h"

#ifndef GAME_H
#define GAME_H

using namespace std;

class Game : public Media{
 public:
  char* getPublisher();
  void setPublisher(char* newPublisher);
  int getRating();
  void setRating(int newRating);
  int getType();
 private:
  int rating;
  char publisher[80];

};
#endif
