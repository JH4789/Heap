#include "Node.h"
//Standard node construction, copied from previous projects
Node::Node(int newdata) {
  data = newdata;
  left = NULL;
  right = NULL;
}
Node::~Node() {
  left = NULL;
  right = NULL;
}
void Node::setData(int newdata) {
  data = newdata;
}
int Node::getData() {
  return data;
}
//Special function for node comparisons, a NULL node will always return the lowest value
int Node::getSLeft() {
  if(left != NULL) {
    return left->getData();
  }
  else {
    return -1;
  }
}
int Node::getSRight() {
  if(right != NULL) {
    return right->getData();
  }
  else {
    return -1;
  }
}
void Node::setLeft(Node* newleft) {
  left = newleft;
}
void Node::setRight(Node* newright) {
  right = newright;
}
Node* Node::getLeft() {
  return left;
}
Node* Node::getRight() {
  return right;
}
