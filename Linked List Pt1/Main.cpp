#include <iostream>
#include <cstring>
#include "Student.h"
#include "Node.h"

using namespace std;

//function prototype
void add(Student* newStudent);
void print(Node* next);

//creating head node
Node* head = NULL;

int main(){
  //making new students
  Student* aaron = new Student();
  aaron->setFirstName("Aaron");
  aaron->setLastName("Gao");
  aaron->setID(393653);
  aaron->setGPA(5.0);
  add(aaron);//adding to link list
  print(head);//printing
  Student* bob = new Student();
  bob->setFirstName("Bob");
  bob->setLastName("Builder");
  bob->setID(123456);
  bob->setGPA(3.7);
  add(bob);//adding to link list
  print(head);//printing
  return 0;
}

void add(Student* newStudent){// this function adds to the linked list
  Node* current = head;
  if(current == NULL) {
    head = new Node(newStudent);
  }else{
    while(current->getNext() != NULL){
      current = current->getNext();
    }
    current->setNext(new Node(newStudent));
  }
}

void print(Node* next){// this function prints a linked list
  if(next == head){
    cout << "list: " << endl;
  }
  if(next != NULL){
    cout << next->getStudent()->getFirstName() << " " << next->getStudent()->getLastName() << " " << next->getStudent()->getID() << " " << next->getStudent()->getGPA() << endl;
    print(next->getNext());
  }
}
