#include <iostream>
#include <cstring>
#include <vector>
#include <iterator>
#include <iomanip>
#include "Media.h"
#include "Game.h"
#include "Music.h"
#include "Movie.h"

using namespace std;

void add(vector<Media*> &yourMedia);
void search(vector<Media*> &yourMedia);
void DELETE(vector<Media*> &yourMedia);

int main(){
  vector<Media*> allMedia;
  char command[10];
  bool keepGoing = true;
  while(keepGoing){
    cout << "please type in one of the following commands: ADD, SEARCH, DELETE, or QUIT" <<endl;
    cin>>command;
    if(strcmp(command, "ADD") == 0){
      add(allMedia);
    }else if(strcmp(command, "SEARCH") == 0){
      search(allMedia);
    }else if(strcmp(command, "DELETE") == 0){

    }else if(strcmp(command, "QUIT") == 0){
      keepGoing = false;
    }else{
      cout <<"this is not a valid command, make sure everything is uppercase." <<endl;
    }
  }
  return 0;
}

void add(vector<Media*> &yourMedia){
  char mediaType[10];
  cout << "what type of media would you like to add to your list: GAME, MUSIC, or MOVIE" <<endl;
  cin >> mediaType;
  if(strcmp(mediaType, "GAME") == 0){
    Game *ptrGame = new Game();
    char title[81];
    int year;
    char publisher[81];
    float rating;
    cout << "What is the title?" << endl;
    cin >> title;
    ptrGame->setTitle(title);
    cout << "what is the year?" << endl;
    cin >> year;
    ptrGame->setYear(year);
    cout << "what is the publisher?" << endl;
    cin >> publisher;
    ptrGame->setPublisher(publisher);
    cout << "what is the rating?" << endl;
    cin >> rating;
    ptrGame->setRating(rating);
    yourMedia.push_back(ptrGame);
  }else if(strcmp(mediaType, "MUSIC") == 0){
    Music *ptrMusic = new Music();
    char title[81];
    char artist[81];
    int year;
    int duration;
    char publisher[81];
    cout << "what is the title?" << endl;
    cin >> title;
    ptrMusic->setTitle(title);
    cout << "what is the artist?" << endl;
    cin >> artist;
    ptrMusic->setArtist(artist);
    cout << "what is the year?" << endl;
    cin >> year;
    ptrMusic->setYear(year);
    cout << "what is the duration (in minutes)?" << endl;
    cin >> duration;
    ptrMusic->setDuration(duration);
    cout << "what is the publisher?" << endl;
    cin >> publisher;
    ptrMusic->setPublisher(publisher);
    yourMedia.push_back(ptrMusic);
  }else if(strcmp(mediaType, "MOVIE") == 0){
    Movie *ptrMovie = new Movie();
    char title[81];
    char director[81];
    int year;
    int duration;
    float rating;
    cout << "what is the title?" << endl;
    cin >> title;
    ptrMovie->setTitle(title);
    cout << "what is the director?" << endl;
    cin >> director;
    ptrMovie->setDirector(director);
    cout << "what is the year?" << endl;
    cin >> year;
    ptrMovie->setYear(year);
    cout << "what is the duration (in minutes)?" << endl;
    cin >> duration;
    ptrMovie->setDuration(duration);
    cout << "what is the rating?" << endl;
    cin >> rating;
    ptrMovie->setRating(rating);
    yourMedia.push_back(ptrMovie);
  }
}
void search(vector<Media*> &yourMedia){
  char searchMethod[10];
  cout << "would you like to search by TITLE or YEAR?" << endl;
  cin >> searchMethod;
  vector<Media*>::iterator it;
  if(strcmp(searchMethod, "TITLE") == 0){
    char title[81];
    char searchTitle[81];
    cout << "what title would you like to search for?" << endl;
    cin >> title;
    for(it = yourMedia.begin();it < yourMedia.end();it++){
      //searchTitle = ((*it)->getTitle());
      if(strcmp((*it)->getTitle(), title) == 0){//game
	if((*it)->getType() == 0){
	  cout << "Game, " << title << ": " << ((*it)->getYear()) << ", " << ((Game*)(*it))->getPublisher() << ", " << ((Game*)(*it))->getRating() << endl;
	}else if((*it)->getType() == 1){//music
	  cout << "Music, " << title << ": " << ((*it)->getYear()) << ", " << ((Music*)(*it))->getArtist() << ", " << ((Music*)(*it))->getDuration() << ", " << ((Music*)(*it))->getPublisher() << endl;
	}else if((*it)->getType() == 2){//movie
	  cout << "Movie, " << title << ": " << ((*it)->getYear()) << ", " << ((Movie*)(*it))->getDirector() << ", " << ((Movie*)(*it))->getDuration() << ", " << ((Movie*)(*it))->getRating() << endl;
	}

      }

    }
  }else if(strcmp(searchMethod, "YEAR") == 0){
    int year;
    cout << "what year would you like to search for?" << endl;
    cin >> year;
    for(it = yourMedia.begin();it < yourMedia.end();it++){
      //searchTitle = ((*it)->getTitle());
      if(year == (*it)->getYear()){//game
	if((*it)->getType() == 0){
	  cout << "Game, " << ((*it)->getTitle()) << ": " << ((*it)->getYear()) << ", " << ((Game*)(*it))->getPublisher() << ", " << ((Game*)(*it))->getRating() << endl;
	}else if((*it)->getType() == 1){//music
	  cout << "Music, " << ((*it)->getTitle()) << ": " << ((*it)->getYear()) << ", ";
	  cout << ((Music*)(*it))->getArtist() << ", " << ((Music*)(*it))->getDuration() << ", " << ((Music*)(*it))->getPublisher() << endl;
	}else if((*it)->getType() == 2){//movie
	  cout << "Movie, " << ((*it)->getTitle()) << ": " << ((*it)->getYear()) << ", " << ((Movie*)(*it))->getDirector();
	  cout << ", " << ((Movie*)(*it))->getDuration() << ", " << ((Movie*)(*it))->getRating() << endl;
	}

      }

    }
  }else{
    cout << "that is not a valid search method, make sure you type in uppercase" << endl;
  }
}
