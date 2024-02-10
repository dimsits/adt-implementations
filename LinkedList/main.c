#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int elem;
    struct node *link;
}*LIST;

typedef int position;

void insert(LIST *L, int val);
void insertPos(LIST *L, int val, position x);
void print(LIST L);
void testTrav(LIST *L);

void main() {
    LIST list = NULL;
    insert(&list, 1);
    insert(&list, 2);
    insert(&list, 3);

    insertPos(&list, 4, 0);
    insertPos(&list, 5, 23);

    print(list);
}

//FUNCTION DEFINITIONS
void insert(LIST *L, int val) {
    LIST newNode = (LIST)malloc(sizeof(struct node));
    newNode->elem = val;
    newNode->link = *L;
    *L = newNode;
}

void testTrav(LIST *L) {
    LIST *trav = L;

    while ((*trav) != NULL) {
        trav = &(*trav)->link;
    }
}

void insertPos(LIST *L, int val, position x) {
    LIST *trav = L; int i = 0;
    LIST newNode = (LIST)malloc(sizeof(struct node));
    newNode->elem = val;

    for (trav, i; (*trav) != NULL && i < x; trav = &((*trav)->link), i++) {}

    if (x <= i) {
        newNode->link = (*trav);
        (*trav) = newNode;
    } 
}

void print(LIST L) {
    LIST trav = L;

    while (trav != NULL) {
        printf("%d  ", trav->elem);
        trav = trav->link;
    }

    printf("\n");
}