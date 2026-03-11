#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>


Node* createFirstNode(int value) {
  Header* header = (Header*)malloc(sizeof(Node) + sizeof(Header));
  if(header == NULL) {
    printf("Error: Memory allocation failed");
    exit(1);
  }

  header->count = 1;
  Node* newNode = (Node *)(header + 1);
  newNode->value = value;
  newNode->next = NULL;
  header->LastElement = (Node *)(header + 1);
  return newNode;
}

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
  Node* real = (*headRef)->next;
  Node* newNode = createNode(value);
  newNode->next = real;
  (*headRef)->next = newNode;
}

void append(Node** headRef, int value) {
  Node* newNode = createNode(value);
  if(*headRef == NULL) {
    printf("Error: List have not been created yet\n");
    return;
  }
  Header* header = ((Header *)*headRef - 1);
  Node* last = header->LastElement;
  header->count++;
  header->LastElement = newNode;
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
  Node* real = (*headRef)->next;
  Node* temp = real;
  Node* prev = NULL;

 if (temp != NULL && temp->value == value) {
    (*headRef)->next = temp->next;
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
  Node* current = head->next;
  Node* temp;
  while(current != NULL) {
    temp = current;
    current = current->next;
    free(temp);
  }
}

void freeHead(Node* head) {
    Header* header = ((Header *)head - 1);
    free(header);
}

void printList(Node* head) {
  Node* current = head->next;
  while (current != NULL) {
    printf("%d-> ", current->value);
    current = current->next;
  }
  printf("NULL\n");
}
