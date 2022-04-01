#include <iostream>
#include "Node.h"
#include <cstring>
#include <math.h>
/*
FOR DELETE FUNCTION:
Swap the root node and the bottom right node
Add the root node to the output
Recursively check if the swapped bottom right node is the smalest thing
Iterate to the bottom of the tree
Rinse and Repeat
*/
using namespace std;
void addHeap(Node* newnode, Node* & head, Node* array[], int & sizecount);
void printFormat(Node* head, int space);
void postfixprint(Node* current);
void deleteTree(Node* array[], int size);
int main() {
  Node* heaparray[100];
  int sizecount = 1;
  Node* treehead = NULL;
  int input = 0;
  bool running = true;
  char commandinput[7];
  while(running == true){
    cout << "Please enter your input" << endl;
    cin >> commandinput;
    if(strcmp(commandinput, "ADD") == 0) {
       cout << "Insert number" << endl;
       cin >> input;
       Node* newnode = new Node(input);
       addHeap(newnode, treehead, heaparray, sizecount);
    }
    else if (strcmp(commandinput, "PRINT") == 0) {
        printFormat(heaparray[0], 0);
    }
    else if (strcmp(commandinput, "DELETE") == 0) {
      deleteTree(heaparray, sizecount-2);
    }
    else if (strcmp(commandinput, "QUIT") == 0) {
      running = false;
    }
    else {
      cout << "Please enter a valid input";
    }
  }
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
      current = array[parentindex-1];
      if(parentindex == 1) {
        //cout << "uhoh";
	break;
      }
      else {
        parentindex = (int)parentindex / 2;
      }
    }
  }

}
void deleteTree(Node* array[], int size) {
  if(array[0] == NULL) {
    cout << "NULL!";
    return;
  }
  else if (size == 0) {
    cout << array[0]->getData() << endl;
    delete array[0];
    array[0] = NULL;
  }
  else {
    int replacedata = array[size]->getData();
    array[size]->setData(array[0]->getData());
    array[0]->setData(replacedata);
    int test = size +1;
    int parent = floor (test/2);
    if(array[parent-1]->getLeft() == array[size]) {
      array[parent-1]->setLeft(NULL);
      cout << array[size]->getData() << endl;
      delete array[size];
    }
    else if (array[parent-1]->getRight() == array[size]) {
      array[parent-1]->setRight(NULL);
      cout << array[size]->getData() << endl;
      delete array[size];
    }
    deleteTree(array, size-1);
  }
}
void printFormat(Node* head, int space) {
  if (head == NULL) {
    return;
  }
    // Increase distance between levels
    space = space + 3;
 
    // Process right child first
    if(head->getRight() != NULL) {
      
    printFormat(head->getRight(), space);
    }
    // Print current node after space
    // count
    cout<<endl;
    for (int i = 0; i < space; i++) {
        cout<<" ";
    }
    cout<<head->getData()<<"\n";
 
    // Process left child
    if(head->getLeft() != NULL) {
    printFormat(head->getLeft(), space);
    }
}

void postfixprint(Node* current) {
  if(current == NULL) {
    return;
  }
  cout << current->getData() << endl;
  postfixprint(current->getLeft());
  postfixprint(current->getRight());
  
}
