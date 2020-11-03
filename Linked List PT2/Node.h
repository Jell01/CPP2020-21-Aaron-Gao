//Creator: Andy Fleischer
//Date: 10/30/20
//Header for Node class

#include "Student.h"
#include <cstddef>

class Node {
 public:
  Node* getNext(); //returns the stored Node pointer 
  Student* getStudent(); //returns the stored Student pointer
  void setNext(Node* newNext); //sets pointer to next Node

  Node(Student* newStudent); //constructor, takes in the Student to be stored
  ~Node(); //destructor

 private:
  Student* student; //student pointer (value of node)
  Node* next; //pointer to the next node  
};
