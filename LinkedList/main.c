#include <stdio.h>
#include "linkedlist.h" 

int main() {
    Node* head = NULL;


    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    printf("After appending 10, 20, 30:\n");
    printList(head); 


    insertAtBeginning(&head, 5);
    printf("\nAfter inserting 5 at beginning:\n");
    printList(head); 


    insertAtPosition(&head, 99, 2);
    printf("\nAfter inserting 99 at position 2:\n");
    printList(head); 


    deleteNodeByValue(&head, 10);
    printf("\nAfter deleting 10:\n");
    printList(head); 


    deleteNodeByValue(&head, 5);
    printf("\nAfter deleting the head (5):\n");
    printList(head); 


    freeList(head);
    printf("\nList freed.\n");
    
    return 0;
}




