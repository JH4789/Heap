#include <iostream>
#include "Node.h"


using namespace std;
void addHeap(Node* newnode, Node* & head, Node* array[]);
int main() {
  Node* heaparray[100];
  Node* treehead = NULL;
  Node* testnode = new Node(4);
  addHeap(testnode, treehead, heaparray);
  cout << heaparray[0]->getData();
  

  return 0;
}

void addHeap(Node* newnode, Node* & head, Node* array[]) {
  if(head == NULL) {
    head = newnode;
    array[0] = head;
  }
}
