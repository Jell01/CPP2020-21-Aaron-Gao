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


char* Media::getPublisher(){
  return "this doesn't have a publisher";
}

void Media::setPublisher(char* newPublisher){
  cout << "something went wrong" << endl;
}

float Media::getRating(){
  return "this does not have a rating";
}

void Media::setRating(int newRating){
  cout << "something went wrong" << endl;
}

char* Media::getArtist(){
  return "this does not have an artist";
}

void Media::setArtist(char* newArtist){
  cout << "something went wrong" <<endl;
}

int Media::getDuration(){
  return "this does not have a duration";
}

void Media::setDuration(int newDuration){
  cout <<"something is wrong" <<endl;
}

char* Media::getDirectior(){
  return "this does not have a director";
}

void Media::setDirector(char* newDirector){
  cout <<"you just messed up" <<endl;
}
