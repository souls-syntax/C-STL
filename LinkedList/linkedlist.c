#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>


Node* createNode(int value) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  if(newNode == NULL) {
    printf("Error: Memory allocation failed");
    exit(1);
  }
  newNode->value = value;
  newNode->next = NULL;
  return newNode;
}

void insertAtBeginning(Node** headRef, int value) {
  Node* newNode = createNode(value);
  newNode->next = *headRef;
  *headRef = newNode;
}

void append(Node** headRef, int value) {
  Node* newNode = createNode(value);
  if(*headRef == NULL) {
    *headRef = newNode;
    return;
  }
  Node* last = *headRef;
  while(last->next != NULL) {
    last = last->next;
  }
  last->next = newNode;
}

void insertAtPosition(Node** headRef, int value, int pos) {
  if (pos == 0) {
    insertAtBeginning(headRef, value);
    return;
  }
  Node* current = *headRef;
  for(int i = 0; current != NULL && i < pos - 1; i++) {
    current = current->next;
  }
  if (current == NULL) {
    printf("Position %d is out of bounds.\n", pos);
    return;
  }
  Node* newNode = createNode(value);
  newNode->next = current->next;
  current->next = newNode;
}

void deleteNodeByValue(Node** headRef, int value) {
  Node* temp = *headRef;
  Node* prev = NULL;

  if (temp != NULL && temp->value == value) {
    *headRef = temp->next;
    free(temp);
    return;
  }
  while (temp != NULL && temp->value != value) {
    prev = temp;
    temp = temp->next;
  }
  if (temp == NULL) {
    printf("Value %d not found in the list\n", value);
    return;
  }
  prev->next = temp->next;
  free(temp);
}

void freeList(Node* head) {
  Node* current = head;
  Node* temp;
  while(current != NULL) {
    temp = current;
    current = current->next;
    free(temp);
  }
}

void printList(Node* head) {
  Node* current = head;
  while (current != NULL) {
    printf("%d-> ", current->value);
    current = current->next;
  }
  printf("NULL\n");
}
