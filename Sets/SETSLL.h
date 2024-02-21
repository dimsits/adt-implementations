#ifndef SETSLL_H
#define SETSLL_H
#include <stdlib.h>

typedef struct node{
    int elem;
    struct node *next;
}*SET;

//LIST OPERATIONS
void insertSortedIfUnique(SET *A, int elem);

//SET OPERATIONS
SET Union(SET A, SET B);
SET Intersection(SET A, SET B);
SET Difference(SET A, SET B);

void insertSortedIfUnique(SET *A, int elem) {
    SET *trav = A;

    for (trav;(*trav) != NULL && elem > (*trav)->elem; trav = &((*trav)->next)) {}

    if ((*trav) != NULL && (*trav)->elem != elem) {
        SET newNode = (SET)malloc(sizeof(struct node));
        if (newNode != NULL) {
            newNode->elem = elem;
            newNode->next = (*trav);
            (*trav) = newNode;
        }
    } else if ((*trav) == NULL){
        SET newNode = (SET)malloc(sizeof(struct node));
        if (newNode != NULL) {
            newNode->elem = elem;
            newNode->next = (*trav);
            (*trav) = newNode;
        }
    }
}

SET Union(SET A, SET B) {
    SET C = NULL;

    SET *trav;

    for(trav = &A; (*trav) != NULL; insertSortedIfUnique(&C, (*trav)->elem),trav = &((*trav)->next)) 
}

#endif SETSLL_H