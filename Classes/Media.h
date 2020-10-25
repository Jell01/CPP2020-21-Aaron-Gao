#include <iostream>
#include <cstring>

#ifndef MEDIA_H
#define MEDIA_H

using namespace std;

class Media {
  
  //function prototypes
 public:
  int getYear();
  void setYear(int newYear);
  char* getTitle();
  void setTitle(char* newTitle);
  virtual int getType();
  
  //initialization
 private:
  int year;
  char title[80];
  
};

#endif
