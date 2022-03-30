#ifndef NODEHEADER
#define NODEHEADER
#include <iostream>
using namespace std;

class Node{
 public:
  Node(int newdata);
  void setData(int newdata);
  int getData();
  ~Node();
  void setLeft(Node*);
  void setRight(Node*);
  Node* getLeft();
  Node* getRight();
 private:
  int data;
  Node* left;
  Node* right;
};
#endif
