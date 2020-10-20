#include <iostream>
#include <cstring>

#ifndef MEDIA_H
#define MEDIA_H

using namespace std;

class Media {

 public:
  int getYear();
  void setYear(int newYear);
  char* getTitle();
  void setTitle(char* newTitle);
  virtual char* getPublisher();
  virtual void setPublisher(char* newPublisher);
  virtual float getRating();
  virtual void setRating(int newRating);
  virtual char* getArtist();
  virtual void setArtist(char* newArtist);
  virtual int getDuration();
  virtual void setDuration(int newDuration);
  virtual char* getDirector();
  virtual void setDirector(char* newDirector);

 private:
  int year;
  char title[80];
  
};

#endif
