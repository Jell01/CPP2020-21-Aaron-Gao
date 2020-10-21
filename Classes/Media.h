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
  virtual int getType();
 private:
  int year;
  char title[80];
  
};

#endif
