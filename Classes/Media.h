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

 private:
  int year;
  char title[80];
  
};

#endif
