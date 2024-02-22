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
    SET *trav = A; int unique;

    for (trav;(*trav) != NULL && elem > (*trav)->elem; trav = &((*trav)->next)) {}

    unique = (*trav) != NULL && (*trav)->elem == elem ? 1 : 0;

    if (unique == 0){
        SET newNode = (SET)malloc(sizeof(struct node));
        if (newNode != NULL) {
            newNode->elem = elem;
            newNode->next = (*trav);
            (*trav) = newNode;
        }
    }
}

SET Union(SET A, SET B) {
    SET *travA, *travB;
    SET C = NULL;

    for(travA = &A; (*travA) != NULL; travA = &((*travA)->next)) {
        for(travB = &B; (*travB) != NULL; travB = &((*travB)->next)) {
            if ((*travA)->elem == (*travB)->elem) { insertSortedIfUnique(&C, (*travA)->elem); }
        }
    }

    return C;
}

SET Intersection(SET A, SET B) {
    SET C = NULL;

    SET *trav;

    for(trav = &A; (*trav) != NULL; insertSortedIfUnique(&C, (*trav)->elem),trav = &((*trav)->next)) {}
    for(trav = &B; (*trav) != NULL; insertSortedIfUnique(&C, (*trav)->elem),trav = &((*trav)->next)) {}

    return C;
}

SET Difference(SET A, SET B) {
    SET *travA, *travB; SET C = NULL; int notEqual;

    for(travA = &A; (*travA) != NULL; travA = &((*travA)->next)) {
        for(travB = &B, notEqual = 0; (*travB) != NULL, notEqual != 1; travB = &((*travB)->next)) {
            notEqual = (*travA)->elem == (*travB)->elem ? 1 : 0;
        }
        if (notEqual == 0) { insertSortedIfUnique(&C, (*travA)->elem); }
    }

    return C;
}

#endif SETSLL_H