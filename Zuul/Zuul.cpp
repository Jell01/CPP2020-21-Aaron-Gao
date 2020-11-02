#include <iostream>
#include <map>
#include <iterator>
#include <cstring>
#include <vector>
#include "Room.h"

using namespace std;

int main(){
  //room initialization
  Room* bedroom = new Room();
  bedroom->setName((char*)"a bedroom");
  bedroom->addItem((char*)"apple");
  bedroom->setDescription((char*)"It's just a normal bedroom");
  Room* ramenStall = new Room();
  ramenStall->setName((char*)"a ramen stall");
  ramenStall->addItem((char*)"bowl");
  ramenStall->setDescription((char*)"The ramen here is supposed to be good");
  Room* gym = new Room();
  gym->setName((char*)"the gym");
  gym->setDescription((char*)"You should come here if you want to work out");
  Room* zoo = new Room();
  zoo->setName((char*)"a zoo");
  zoo->setDescription((char*)"The animals here are pretty cool");
  Room* lab = new Room();
  lab->setName((char*)"a lab");
  lab->addItem((char*)"vial");
  lab->setDescription((char*)"You should stay away from the chemicals");
  Room* er = new Room();
  er->setName((char*)"the emergency room");
  er->setDescription((char*)"someone might get saved here");
  Room* inglenook = new Room();
  inglenook->setName((char*)"a inglenook");
  inglenook->setDescription((char*)"the fireplace here is really warm");
  Room* disco = new Room();
  disco->setName((char*)"a disco room");
  disco->setDescription((char*)"people don't come here much");
  Room* compLab = new Room();
  compLab->setName((char*)"a computer lab");
  compLab->setDescription((char*)"people program here a lot");
  Room* livingRoom = new Room();
  livingRoom->setName((char*)"a living room");
  livingRoom->setDescription((char*)"it looks comfortable");
  Room* inBeach = new Room();
  inBeach->setName((char*)"an indoor beach");
  inBeach->addItem((char*)"umbrella");
  inBeach->setDescription((char*)"its pretty warm here");
  Room* medRoom = new Room();
  medRoom->setName((char*)"a media room");
  medRoom->setDescription((char*)"the TV in the front is pretty big");
  Room* courtRoom = new Room();
  courtRoom->setName((char*)"a court room");
  courtRoom->setDescription((char*)"luckily it isn't in session right now");
  Room* attic = new Room();
  attic->setName((char*)"an attic");
  attic->addItem((char*)"gavel");
  attic->setDescription((char*)"It's pretty dusty up here");
  Room* pool = new Room();
  pool->setName((char*)"a pool");
  pool->setDescription((char*)"you got yourself wet! Luckily you can dry off");

  //exit initialization
  bedroom->addExit("NORTH", ramenStall);
  bedroom->addExit("SOUTH", gym);
  bedroom->addExit("EAST", disco);
  lab->addExit("SOUTH", ramenStall);
  ramenStall->addExit("NORTH", lab);
  ramenStall->addExit("SOUTH", bedroom);
  ramenStall->addExit("WEST", inBeach);
  gym->addExit("NORTH", bedroom);
  gym->addExit("WEST", pool);
  gym->addExit("SOUTH", zoo);
  zoo->addExit("NORTH", gym);
  zoo->addExit("SOUTH", er);
  inglenook->addExit("WEST", er);
  er->addExit("NORTH", zoo);
  er->addExit("EAST", inglenook);
  disco->addExit("WEST", bedroom);
  disco->addExit("EAST", compLab);
  compLab->addExit("WEST", disco);
  compLab->addExit("NORTH", livingRoom);
  livingRoom->addExit("SOUTH", compLab);
  inBeach->addExit("EAST", ramenStall);
  inBeach->addExit("WEST", medRoom);
  medRoom->addExit("EAST", inBeach);
  medRoom->addExit("SOUTH", courtRoom);
  courtRoom->addExit("NORTH", medRoom);
  courtRoom->addExit("SOUTH", attic);
  attic->addExit("NORTH", courtRoom);
  attic->addExit("EAST", pool);
  pool->addExit("WEST", attic);
  pool->addExit("EAST", gym);

  //other initialization
  Room* currRoom = bedroom;
  bool keepGoing = true;
  vector<char*> inventory;
  char nextDir[80];
  while(keepGoing){//keep going while the user hasn't quit or won the game

    //print the room and items in the room
    cout << "you are in " << currRoom->getName() << endl;
    cout << "Items in the room: ";
    for(vector<char*>::iterator it = currRoom->getItems()->begin();it < currRoom->getItems()->end();it++){//loop through the items in the current room and print them
      cout << (*it) << " ";
    }
    cout << endl;
    cout << currRoom->getDescription() << endl;//print the description
    int curPos = -1;
    
    for(vector<char*>::iterator it = currRoom->getItems()->begin();it < currRoom->getItems()->end();it++){//loop through the items in the room and ask if they would like to pick it up
      curPos++;
      char answer[80];
      cout << "would you like to pick up: " << (*it) << "(Y/N)" << endl;
      cin >> answer;
      if(strcmp(answer, "Y") == 0){//put it in the inventory and remove it from the room
	inventory.push_back((*it));
        currRoom->getItems()->erase(it);
	break;
      }else if(strcmp(answer, "N") == 0){
	continue;
      }else{
	cout << "that is not a valid command, make sure you typed 'Y' or 'N'" << endl;
	cout << "leave the room and come back to attempt to pick it up again" << endl;
      }
    }
    if(inventory.size() == 5){//win condition
      cout << "congratulations you have won by picking up all 5 items" << endl;
      break;
    }
    if(inventory.size() > 0){//checking if the user would like to drop their items
      char drop[80];
      curPos = -1;
      for(vector<char*>::iterator it = inventory.begin(); it != inventory.end(); it++){
	curPos++;
	cout << "would you like to drop your " << *it << "? (Y/N)" << endl;
	cin>> drop;
	if(strcmp(drop, "Y") == 0){
	  currRoom->getItems()->push_back(*it);
	  inventory.erase(it);
	  break;
	}else if(strcmp(drop, "N") == 0){
	  continue;
	}else{
	  cout << "make sure you type 'Y' or 'N'" << endl;
	}
      }
    }

    //printing out the exits of the room
    cout << "Exits are: " << endl;
    for(map<const char*, Room*>::iterator it  = currRoom->getMap()->begin(); it != currRoom->getMap()->end(); it++){
      cout <<it->first << ", " << it->second->getName() << endl;
    }
    cout << "you can type QUIT to quit as well" << endl;
    cout << "where would you like to go?" << endl;
    cin >> nextDir;
    //prompt the user for what direction they'd like to go in or if they'd like to quit
    for(map<const char*, Room*>::iterator it = currRoom->getMap()->begin(); it != currRoom->getMap()->end(); it++){
      if(strcmp(it->first, nextDir) == 0){
	currRoom = it->second;
	break;
      }
    }
    if(strcmp(nextDir, "QUIT") == 0){
      keepGoing = false;
    }
  }
  return 0;
}
