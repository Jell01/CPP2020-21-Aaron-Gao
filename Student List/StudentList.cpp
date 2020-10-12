#include <iostream>
#include <cstring>
#include <vector>
#include <iterator>
#include <iomanip>

using namespace std;

//creating a new struct
struct student{
  char firstName[80];
  char lastName[80];
  int id;
  float gpa;
};

//function initialization
void addFunc(vector<student*> &input);
void printFunc(vector<student*> &input);
void deleteFunc(vector<student*> &input);

int main(){
  
  char command[10];
  vector<student*> students;

  //main body of code, keeps going until user types "END"
  while(strcmp(command, "END") != 0){

    //prompts for command
    cout <<"Type a command (ADD, PRINT, DELETE, or END)" << endl;
    cin >> command;
    
    if(strcmp(command, "ADD") == 0){//if the user types "ADD"
      addFunc(students);
    }else if(strcmp(command, "PRINT") == 0){//if the user types "PRINT"
      printFunc(students);
    }else if(strcmp(command, "DELETE")== 0){//if the user types "DELETE"
      deleteFunc(students);
    }
  }
}

void addFunc(vector<student*> &input){
  student* newStudent = new student();

  //prompts for information for a student pointer
  cout << "what is the student's first name?" <<endl;
  cin >> newStudent->firstName;
  cout << "what is the student's last name?" <<endl;
  cin >> newStudent->lastName;
  cout << "what is the student's student ID?" <<endl;
  cin >> newStudent->id;
  cout << "what is the student's GPA?" <<endl;
  cin >> newStudent->gpa;

  //adds it to the original vector pointer array
  input.push_back(newStudent);
}

void printFunc(vector<student*> &input){

  //loops through the vector with an iterator
  for (vector<student*>::iterator it = input.begin(); it != input.end(); it++){

    //prints out each of its variables
    cout << "Name: " << (*it)->firstName;
    cout << ' ' << (*it)->lastName;
    cout << " Student id: " << (*it)->id;
    cout << " GPA: " << fixed << setprecision(2) << (*it)->gpa << endl;
  }
}
void deleteFunc(vector<student*> &input){
  //prompts for a student ID and deletes the corresponding student
  int remID = -1;
  cout << "Please type the student ID of the student you'd like to delete" <<endl;
  cin >> remID;
  for (vector<student*>::iterator it = input.begin(); it != input.end(); it++){
    if((*it)->id == remID){
      input.erase(it);
      return;
    }
  }
}
