/*
Name: Jayden Huang
Date: 4/3/2022
Project: Max Heap with add, print, and delete functionality
*/
#include <iostream>
#include "Node.h"
#include <cstring>
#include <math.h>
#include <fstream>

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
  //Main loop
  while(running == true){
    cout << "Please enter your input. Enter ADD to add a number to the heap, PRINT to print the heap, FILE to load a heap from the file, DELETE to delete the heap, and QUIT to end the program." << endl;
    cin >> commandinput;
    if(strcmp(commandinput, "ADD") == 0) {
       cout << "Insert number" << endl;
       cin >> input;
       Node* newnode = new Node(input);
       addHeap(newnode, treehead, heaparray, sizecount);
    }
    else if (strcmp(commandinput, "PRINT") == 0) {
        printFormat(heaparray[0], 1);
    }
    else if (strcmp(commandinput, "FILE") == 0) {
      //Opens from file and iterates through using the same add function
      fstream File;
      int fileinput = 0;
      File.open("File.txt");
      for(int i = 0; i < 100; i++) {
	File >> fileinput;
	Node* newnode = new Node(fileinput);
	addHeap(newnode, treehead, heaparray, sizecount);
      }
    }
    else if (strcmp(commandinput, "DELETE") == 0) {
      //Deletes the heap and resets the important variables and pointers
      deleteTree(heaparray, sizecount-2);
      sizecount = 1;
      treehead = NULL;
    }
    else if (strcmp(commandinput, "QUIT") == 0) {
      running = false;
    }
    else {
      cout << "Please enter a valid input" << endl;
    }
  }
  return 0;
}
void addHeap(Node* newnode, Node* & head, Node* array[], int & sizecount) {
  //Each addition needs to be part of the array and the tree
  if(head == NULL) {
    head = newnode;
    //Sizecount always stays one ahead of the array index so that parent and child calculations work
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
    //Loop to ensure that the new heap is in order from smallest to greatest
    while(array[parentindex-1]->getData() < current->getData()) {   
      int replacedata = current->getData();
      current->setData(array[parentindex-1]->getData());
      array[parentindex-1]->setData(replacedata);
      current = array[parentindex-1];
      if(parentindex == 1) {
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
  //Swaps the last node and the first node but only if the last node is bigger
  else {
    if(array[0]->getData() > array[size]->getData()) {
    int replacedata = array[size]->getData();
    array[size]->setData(array[0]->getData());
    array[0]->setData(replacedata);
    }
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
    //After the last node is deletes, a similar form of sorting occurs where the heap is put back into order
    Node* current = array[0];
    while(current->getLeft() != NULL || current->getRight() != NULL) {
      //Special function custom made to compare the value of the data in child nodes, even if they are null
      if(current->getSLeft() > current->getSRight()) {
	int replacedata = current->getData();
	current->setData(current->getLeft()->getData());
	current->getLeft()->setData(replacedata);
	current = current->getLeft();
      }
      else if (current->getSLeft() < current->getSRight()){
        int replacedata = current->getData();
	current->setData(current->getRight()->getData());
	current->getRight()->setData(replacedata);
	current = current->getRight();
      }
      else {
	//Checks for a case where the two child nodes have equal value
	if(current->getSLeft() != -1) {
	int replacedata = current->getData();
	current->setData(current->getSLeft());
	current->getLeft()->setData(replacedata);
	current = current->getLeft();
	}
	else {
	  break;
	}
      }
    }
    //Recurs on an array that is one size smaller
    deleteTree(array, size-1);
  }
}
//Function to print the heap with spacing, code taken from https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/
void printFormat(Node* head, int space) {
  if (head == NULL) {
    return;
  }
    space = space + 10;
    if(head->getRight() != NULL) {
      
    printFormat(head->getRight(), space);
    }
    cout<<endl;
    for (int i = 0; i < space; i++) {
        cout<<" ";
    }
    cout<<head->getData()<<"\n";
 
    if(head->getLeft() != NULL) {
    printFormat(head->getLeft(), space);
    }
}

