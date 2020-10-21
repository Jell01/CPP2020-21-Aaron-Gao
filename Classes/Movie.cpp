#include <iostream>
#include <cstring>
#include "Media.h"
#include "Movie.h"

using namespace std;

char* Movie::getDirector(){
  return director;
}

void Movie::setDirector(char* newDirector){
  director = newDirector;
}

int Movie::getDuration(){
  return duration;
}

void Movie::setDuration(int newDuration){
  duration = newDuration;
}

int Movie::getRating(){
  return rating;
}

void Movie::setRating(int newRating){
  rating = newRating;
}

int Movie::getType(){
  return 2;
}
