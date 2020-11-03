#include <iostream>
#include <cstring>
#include <iomanip>
#include "Node.h"
#include "Student.h"

using namespace std;

//function prototypes
void print(Node* head, Node* next);
void add(Node* &head, Node* &current, Student* newStudent);
void DELETE(Node* head, Node* &current, int id);
void average(Node* head);

int main(){

  //initialization
  Node* head = NULL;
  char command[80];

  
  while(true){
    cout << "would you like to ADD a student, PRINT the students, DELETE a student, AVERAGE the gpas, or QUIT the program" << endl;
    cout << "just type the capital part of the command" << endl;
    cin >> command;
    if(strcmp(command, "PRINT") == 0){//if they want to print student list
      print(head, head);
    }else if(strcmp(command, "ADD") == 0){//if they want to add a new student

      //creating a new student
      Student* newStudent = new Student();
      cout << "what is the first name?" << endl;
      cin >> newStudent->getFirstName();
      cout << "what is the last name?" << endl;
      cin >> newStudent->getLastName();
      cout << "what is the student ID?" << endl;
      cin >> *newStudent->getID();
      cout << "what is the GPA?" << endl;
      cin >> *newStudent->getGPA();

      add(head, head, newStudent);
    }else if(strcmp(command, "DELETE") == 0){//if they want to delete a student
      cout << "what ID would you like to delete?" << endl;
      int id;
      cin >> id;
      DELETE(head, head, id);
    }else if(strcmp(command, "AVERAGE") == 0){//averaging GPA
      average(head);
    }else if(strcmp(command, "QUIT") == 0){//quitting
      break;
    }else{//not a valid command
      cout <<"that is not a valid command, make sure you typed in all caps" << endl;
    }
  }
  return 0;
}

void print(Node* head,Node* next){// this function prints a linked list
  if(next == head){//print the word list before printing actual contents
    cout << "list: " << endl;
  }
  if(next != NULL){//print out all student info
    cout << next->getStudent()->getFirstName() << " " << next->getStudent()->getLastName() << " " << *(next->getStudent()->getID()) << " " <<fixed << setprecision(2) << *(next->getStudent()->getGPA()) << endl;
    print(head,next->getNext());
  }
}


void add(Node* &head, Node* &current, Student* newStudent){//this function adds a student to the linked list

  if(current == NULL){//if there is nothing in the student list
    current = new Node(newStudent);
  }else if(current == head && *(current->getStudent()->getID()) > *(newStudent->getID())){//if there is only one thing in the list
    Node* temp = head;
    head = new Node(newStudent);
    head->setNext(temp);

  }else if(current->getNext() == NULL){//if you're at the end of the list
    Node* endNode = new Node(newStudent);
    current->setNext(endNode);
  }else if(*(current->getNext()->getStudent()->getID()) > *(newStudent->getID())){//if the ID is smaller than one in the list, insert it in that spot
    Node* temp = new Node(newStudent);
    temp->setNext(current->getNext());
    current->setNext(temp);
  }else{//keep recursing
    Node* temp = current->getNext();
    add(head, temp, newStudent);
  }
}

void DELETE(Node* head,Node* &current, int id){//this function deletes a node from a linked list
  if(head == NULL){//if the list is empty
    cout<< "you have no students"<<endl;
  }else if(head == current && id == *(current->getStudent()->getID())){//if it is your first student
    cout << "deleting your first student" << endl;
    Node* newHead = current->getNext();
    current->~Node();
    current = newHead;
  }else if(current->getNext() == NULL){//if you're at the end of the list
    cout << "no matching IDs" << endl;
  }else if(*(current->getNext()->getStudent()->getID()) == id){//if the ids match
    cout << "deleting student: " << *(current->getNext()->getStudent()->getID()) << endl;
    Node* newNext = current->getNext()->getNext();
    current->getNext()->~Node();
    current->setNext(newNext);
  }else{//keep recursing
    Node* next = current->getNext();
    DELETE(head, next, id);
  }
}

void average(Node* head){//this function outputs the average of all gpas
  float count = 0;
  float total = 0;
  Node* current = head;
  if(head == NULL){//if there are no students
    cout <<"you have no students" << endl;
  }else{
    while(current->getNext() != NULL){//while you haven't reached the end of the linked list
      total+=*(current->getStudent()->getGPA());
      count++;
      current=current->getNext();
    }

    //adding the last person
    total+=*(current->getStudent()->getGPA());
    count++;

    //calculating and displaying
    float avg = total/count;
    cout <<"Average GPA: " << fixed << setprecision(2) << avg << endl;
  }
}

