#include <iostream>
#include <cstring>
#include "Media.h"
#include "Music.h"

using namespace std;

char* Music::getArtist(){//this function returns the artist of a Music
  return artist;
}

void Music::setArtist(char* newArtist){//this function sets the artist of a Music
  strcpy(artist, newArtist);
}

int Music::getDuration(){//this function returns the duration of a Music
  return duration;
}

void Music::setDuration(int newDuration){//this function sets the duration of a Music
  duration = newDuration;
}

char* Music::getPublisher(){//this function returns the publisher of a Music
  return publisher;
}

void Music::setPublisher(char* newPublisher){//this function sets the publisher of a Music
  strcpy(publisher, newPublisher);
}

int Music::getType(){//this function is used to find the Media type, in this case Music
  return 1;
}
