#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdlib.h>

typedef struct Node {
  int value;
  struct Node* next;
} Node;

Node* createNode(int value);

// Insertion
void insertAtBeginning(Node** headRef, int value);
void append(Node** headRef, int data);
void insertAtPosition(Node** headRef, int value, int pos);

//Deletion
void deleteNodeByValue(Node** headRef, int value);
void freeList(Node* head);

//Utility
void printList(Node* head);

#endif // !LINKEDLIST_H
