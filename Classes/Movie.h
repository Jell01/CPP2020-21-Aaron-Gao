#include <iostream>
#include <cstring>
#include "Media.h"

#ifndef MOVIE_H
#define MOVIE_H

using namespace std;

class Movie : public Media {

 public:
  char* getDirector();
  void setDirector(char* newDirector);
  int getDuration();
  void setDuration(int newDuration);
  int getRating();
  void setRating(int newRating);
  int getType();
  
 private:
  char director[80];
  int duration;
  int rating;
};
#endif
