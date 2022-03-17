#include <iostream>
#include "Node.h"


using namespace std;
void addHeap(Node* newnode, Node* & head, Node* array[], int & sizecount);
void postfixprint(Node* current);
int main() {
  Node* heaparray[100];
  int sizecount = 1;
  Node* treehead = NULL;
  int input;
  bool running = true;
  while(running == true){
    cout << "Insert number" << endl;
    cin >> input;
    if(input == 0) {
      break;
    }
    Node* newnode = new Node(input);
    addHeap(newnode, treehead, heaparray, sizecount);
  }
  postfixprint(treehead);
  return 0;
}
void addHeap(Node* newnode, Node* & head, Node* array[], int & sizecount) {
  if(head == NULL) {
    head = newnode;
    array[sizecount-1] = head;
    sizecount++;
  }
  else {
    int parentindex = (int)sizecount / 2;
    Node* parent = array[parentindex-1];
    Node* current = newnode;
    if(parent->getLeft() == NULL) {
      parent->setLeft(newnode);
      array[sizecount-1] = newnode;
      sizecount++;
    }
    else {
      parent->setRight(newnode);
      array[sizecount-1] = newnode;
      sizecount++;
    }
    
    while(array[parentindex-1]->getData() < current->getData()) {
      
      int replacedata = current->getData();
      current->setData(array[parentindex-1]->getData());
      array[parentindex-1]->setData(replacedata);
      if(parentindex == 1) {
        break;
      }
      else {
      parentindex = (int)parentindex / 2;
      }
    }
  }
  /*
  else if() {

  }
  */

}
void postfixprint(Node* current) {
  if(current == NULL) {
    return;
  }
  cout << current->getData() << endl;
  postfixprint(current->getLeft());
  postfixprint(current->getRight());
  
}
