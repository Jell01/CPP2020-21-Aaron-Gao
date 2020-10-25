#include <iostream>
#include <cstring>
#include "Media.h"
#include "Game.h"

using namespace std;

char* Game::getPublisher(){//this function returns the publisher of Game
  return publisher;
}

void Game::setPublisher(char* newPublisher){//this function sets the publisher of a game
  strcpy(publisher, newPublisher);
}

int Game::getRating(){//this function returns the rating of a game
  return rating;
}

void Game::setRating(int newRating){//this function sets the rating of a game
  rating = newRating;
}

int Game::getType(){//this function returns 0, meaning that the type is Game
  return 0;
}
