#ifndef NODEHEADER
#define NODEHEADER
#include <iostream>
using namespace std;

class Node{
 public:
  Node(int newdata);
  int getData();
  void setLeft(Node*);
  void setRight(Node*);
 private:
  int data;
  Node* left;
  Node* right;
};
#endif
