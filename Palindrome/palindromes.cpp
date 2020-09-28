#include <iostream>
#include <cstring>

using namespace std;

int main(){
  //initialization
  char input[80];
  char noPunct[80];
  int count = 0;

  //prompt for input
  cout << "input a string" <<endl;
  cin.get(input, 81);
  cin.get();

  //sorting out letters and numbers
  for(int i = 0; i<strlen(input);i++){
    if(input[i] >= 65 && input[i] <= 90){
      noPunct[count] =input[i];
      count++;
    }else if(input[i] >=97 && input[i] <=122){
      noPunct[count] = input[i] - 32;
      count++;
    }else if(input[i] >='0' && input[i]<='9'){
      noPunct[count] = input[i];
      count++;
    }
  }

  //checking if it is a palindrome
  bool isPal = true;
  int k = strlen(noPunct)-1;
  for(int i = 0; i<strlen(noPunct)/2; i++){
    if (noPunct[i] !=noPunct[k]){
      isPal=false;
      break;
    }
    k--;
  }

  //output
  if(isPal == true){
    cout << "Palindrome" <<endl;
  }else{
    cout << "Not a palindrome" << endl;
  }
}
