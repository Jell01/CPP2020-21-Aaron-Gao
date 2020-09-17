#include <iostream>

using namespace std;

int main(){
  srand(time(NULL));//generates a random seed

  //initiallization
  int guess = -1;
  int myNum = rand() % 101;
  bool playAgain = true;
  char reply = 'y';
  int count = 0;

  //play the game while the player still wants too
  while(playAgain == true){
    count = 0;
    myNum = rand()%101;//generating a random number
    cout << "guess my number from 0-100" << endl;
    guess = -1;

    //while the number hasn't been guessed, keep track of number of guesses as       well as whether the guess was too high or low 
    do{
      cin >> guess;
      if(guess > myNum){
	cout << "too high" << endl;
	++count;
      }else if (guess < myNum){
	cout << "too low" << endl;
	++count;
      }
    }while(guess != myNum);
    cout << "you found my number in: " <<count+1<<" guesses" <<endl;
    cout <<"would you like to play again? (y/n)" <<endl;
    char reply = 'x';

    //find out whether the player still wants to play
    while(reply != 'y' && reply != 'n'){
      cin >> reply;
      if(reply == 'y'){//yes
	playAgain = true;
      }else if(reply == 'n'){//no
	playAgain =false;
      }else{//if they typed something else
	cout << "please type y to continue or n to quit" << endl;
      }    
    }
  }
  return 0;
}
