#include <iostream>
#include <cstring>
#include "Media.h"

#ifndef MUSIC_H
#define MUSIC_H

using namespace std;

class Music : public Media{
  //function prototype
 public:
  char* getArtist();
  void setArtist(char* newArtist);
  int getDuration();
  void setDuration(int newDuration);
  char* getPublisher();
  void setPublisher(char* newPublisher);
  int getType();
 
  //initialization
 private:
  char artist[81];
  int duration;
  char publisher[81];

};
#endif
