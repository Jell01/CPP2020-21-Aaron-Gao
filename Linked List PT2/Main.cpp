#include <iostream>
#include <cstring>
#include "Node.h"
#include "Student.h"

using namespace std;

void print(Node* head);
void add(Node* head);
void DELETE();

Node* head = NULL;

int main(){
  char command[80];
  while(true){
    cout << "would you like to ADD a student, PRINT the students, DELETE a student, AVERAGE the gpas, or QUIT the program" << endl;
    cout << "just type the capital part of the command" << endl;
    cin >> command;
    if(strcmp(command, "PRINT") == 0){
      print(head);
    }else if(strcmp(command, "ADD") == 0){
      add(head);

    }else if(strcmp(command, "DELETE") == 0){
      DELETE();
    }
  }
  return 0;
}

void print(Node* head){
  cout << "deleted" << endl;
}

void add(Node* head){
  Student* newStudent = new Student();
  cout << "what is the first name" << endl;
  char firstName[80];
  cin >> firstName;
  newStudent->setFirstName(firstName);
}

void DELETE(){

}

void Average(){

}
