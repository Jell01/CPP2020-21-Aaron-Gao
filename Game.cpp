#include <iostream>
#include <cstring>
#include "Media.h"
#include "Game.h"

using namespace std;

char* Game::getPublisher(){
  return publisher;
}

void Game::setPublisher(char* newPublisher){
  strcpy(publisher, newPublisher);
}

int Game::getRating(){
  return rating;
}

void Game::setRating(int newRating){
  rating = newRating;
}

int Game::getType(){
  return 0;
}
