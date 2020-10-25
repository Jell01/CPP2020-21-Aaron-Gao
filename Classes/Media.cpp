#include <iostream>
#include <cstring>
#include "Media.h"

using namespace std;

int Media::getYear(){//this function returns the year
  return year;
}

void Media::setYear(int newYear){//this function sets the year of a media
  year = newYear;
}

char* Media::getTitle(){//this function returns the title of a media
  return title;
}

void Media::setTitle(char* newTitle){//this function sets the title of a media
  strcpy(title, newTitle);
}

int Media::getType(){//this function returns an int based on the type, game:0, music:1, Movie:2
  cout << "Something went wrong" <<endl;
  return -1;
}
