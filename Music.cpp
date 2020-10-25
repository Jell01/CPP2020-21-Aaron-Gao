#include <iostream>
#include <cstring>
#include "Media.h"
#include "Music.h"

using namespace std;

char* Music::getArtist(){
  return artist;
}
void Music::setArtist(char* newArtist){
  strcpy(artist, newArtist);
}
int Music::getDuration(){
  return duration;
}

void Music::setDuration(int newDuration){
  duration = newDuration;
}
char* Music::getPublisher(){
  return publisher;
}

void Music::setPublisher(char* newPublisher){
  strcpy(publisher, newPublisher);
}

int Music::getType(){
  return 1;
}
