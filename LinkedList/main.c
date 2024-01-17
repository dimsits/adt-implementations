#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//STRUCTURE DEFINITIONS & FUNCTION HEADERS
typedef struct node {
    int val;
    struct node *next;
}list;

void insert(list **head, int val);//https://dev-notes.eu/2018/07/double-pointers-and-linked-list-in-c/
void delete(list *head);
void print(list *head);



void main() {
    list *head = NULL;

    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 2);

    print(head);
}

//FUNCTION DEFINITIONS
void insert(list **head, int val) {
    list *newNode = malloc(sizeof(list));
    newNode->val = val;
    newNode->next = *head;
    *head = newNode;
}

void print(list *head) {
    list *trav;

    for (trav = head; trav != NULL; trav = trav->next) {
        printf("%d ", trav->val);
    }
}

