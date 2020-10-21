#include <iostream>
#include <cstring>
#include "Media.h"

#ifndef MUSIC_H
#define MUSIC_H

using namespace std;

class Music : public Media{
 public:
  int getDuration();
  void setDuration(int newDuration);
  char* getPublisher();
  void setPublisher(char* newPublisher);
  int getType();
 private:
  int duration;
  char* publisher;

};
#endif
