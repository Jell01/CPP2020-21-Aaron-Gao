#include <iostream>
#include <cstring>

using namespace std;

//initializtion
int checkFull(char currBoard[3][3]);
int checkWin(char currBoard[3][3]);
int main(){
  int xWins = 0;
  int oWins = 0;
  while(true){//this code is of the game
    char board[3][3]= {{'-','-','-'},{'-','-','-'},{'-','-','-'}};
    bool isFull = false;
    int turn = 0;
    cout <<endl;
    cout <<"new game"<<endl;
    cout <<endl;
    while(checkFull(board)<9 && checkWin(board)==0){//while the board isn't full or theres a tictactoe, let the players keep playing
      //printing the board
      cout << "  0 1 2" <<endl;
      for(int i = 0;i<3;i++){
	cout <<i;
	for(int j = 0;j<3;j++){
	  cout <<" "<< board[i][j] <<" ";
	}
	cout <<endl;
      }

      //user input for the location of their marker
      char location[3];
      cout<< "Where would you like to mark? Write it in the order of row by column (e.g. 02 is the top right)"<< endl;
      cin>>location;
      location[2] = '\0';

      //checking if the move is legal
      if(board[int(location[0])-48][int(location[1])-48] == '-'){
	if(turn == 0){
	  board[int(location[0])-48][int(location[1])-48] = 'X';
	  turn = 1;
	  cout <<board[int(location[0])-48][int(location[1])-48]<< endl;
	}else if(turn == 1){
	  board[int(location[0])-48][int(location[1])-48] = 'O';
	  turn = 0;
	}
      }else{
	cout << "that space is occupied or is not on the board" << endl;
      }
    }
    //print out the finished board
    for(int i = 0;i<3;i++){
      cout <<i;
      for(int j = 0;j<3;j++){
	cout <<" "<< board[i][j] <<" ";
      }
      cout <<endl;
    }
    //check who won and output wins
    if(checkWin(board) == 'X'){
      cout << "X Wins this round" << endl;
      xWins+=1;
    }else if(checkWin(board) == 'O'){
      cout << "O Wins this round" << endl;
      oWins+=1;
    }else if(checkFull(board)==9){
      cout <<"its a tie" <<endl;
    }
    cout << "Total X wins: " << xWins <<endl;
    cout << "Total O wins: " << oWins <<endl;
  }
  return 0;
}

//check who won
int checkWin(char currBoard[3][3]){
  for(int i = 0;i<3;i++){
    if(currBoard[0][i]==currBoard[1][i] && currBoard[1][i]==currBoard[2][i] && currBoard[0][i] != '-'){
      return currBoard[0][i];
    }else if(currBoard[i][0]==currBoard[i][1] && currBoard[i][1] == currBoard[i][2] && currBoard[i][0] != '-'){
      return currBoard[i][0];
    }
  }
  if(currBoard[0][0]==currBoard[1][1] && currBoard[1][1] == currBoard[2][2] && currBoard[0][0] !='-'){
    return currBoard[0][0];
  }else if(currBoard[0][2]==currBoard[1][1] && currBoard[1][1]==currBoard[2][0] && currBoard[0][2] !='-'){
    return currBoard[0][2];
  }
  return 0;
}

//check if the board is full
int checkFull(char currBoard[3][3]){
  int count=0;
  for(int i = 0;i<3;i++){
    for(int j = 0;j<3;j++){
      if(currBoard[i][j] != '-'){
        count++;
      }
    }
  }
  return count;
}
