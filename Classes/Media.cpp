#include <iostream>
#include <cstring>
#include "Media.h"

using namespace std;

int Media::getYear(){
  return year;
}

void Media::setYear(int newYear){
  year = newYear;
}

char* Media::getTitle(){
  return title;
}

void Media::setTitle(char* newTitle){
  title = newTitle;
}


virtual int Media::getType(){//game:0, music:1, Movie:2
  cout << "Something went wrong" <<endl;
}
