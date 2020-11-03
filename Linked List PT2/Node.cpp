//Creator: Andy Fleischer
//Date: 10/30/20
//Body of Node class
//Note: comments are in Node.h

#include "Node.h"

Node::Node(Student* newStudent) {
  student = newStudent;
  next = NULL;
}

Node::~Node() {
  delete(student);
  next = NULL;
}

Node* Node::getNext() {
  return next;
}

Student* Node::getStudent() {
  return student;
}

void Node::setNext(Node* newNext) {
  next = newNext;
}
