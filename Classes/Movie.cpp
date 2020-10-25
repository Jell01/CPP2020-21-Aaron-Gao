#include <iostream>
#include <cstring>
#include "Media.h"
#include "Movie.h"

using namespace std;

char* Movie::getDirector(){//this function returns the director of a Movie
  return director;
}

void Movie::setDirector(char* newDirector){//this function sets the director of a movie
  strcpy(director, newDirector);
}

int Movie::getDuration(){//this function returns the duration of a movie
  return duration;
}

void Movie::setDuration(int newDuration){//this function sets the duration of a movie
  duration = newDuration;
}

int Movie::getRating(){//this fucntion returns the rating of a movie
  return rating;
}

void Movie::setRating(int newRating){//this function sets the rating of the movie
  rating = newRating;
}

int Movie::getType(){//this function is used to identify the type within the code
  return 2;
}
