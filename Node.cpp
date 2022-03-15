#include "Node.h"

Node::Node(int newdata) {
  data = newdata;
  left = NULL;
  right = NULL;
}
int Node::getData() {
  return data;
}
void Node::setLeft(Node* newleft) {
  left = newleft;
}
void Node::setRight(Node* newright) {
  right = newright;
}
