#include <iostream>
#include <cstring>
#include "Media.h"
#include "Music.h"

using namespace std;

int Music::getDuration(){
  return duration;
}

void Music::setDuration(int newDuration){
  duration = newDuration;
}
char* Music::getPubliser(){
  return publisher;
}

void Music::setPublisher(char* newPublisher){
  publisher = newPublisher;
}

int Music::getType(){
  return 1;
}
