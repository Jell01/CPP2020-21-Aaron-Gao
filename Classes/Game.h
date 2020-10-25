#include <iostream>
#include <cstring>
#include "Media.h"

#ifndef GAME_H
#define GAME_H

using namespace std;

class Game : public Media{

  //function prototypes are public
 public:
  char* getPublisher();
  void setPublisher(char* newPublisher);
  int getRating();
  void setRating(int newRating);
  int getType();

  //variables are private
 private:
  int rating;
  char publisher[80];

};
#endif
