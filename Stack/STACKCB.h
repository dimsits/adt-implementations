#ifndef STACKCB_H
#define STACKCB_H
#include <stdlib.h>
#define MAX 5

typedef struct {
    char elem;
    int link;
}Node;

typedef struct {
    Node *elem;
    int avail;
}*VHeap, VHType;

typedef int LIST;

typedef struct {
    VHeap heap;
    LIST top;
}*Stack, StackType;

typedef enum {TRUE, FALSE}boolean;

void initStack(Stack *S);//Initialize to be empty
boolean isEmpty(Stack S); S, char c);
void pop(Stack S);
char top(Stack S);

void initStack(Stack *S) {
    (*S) = (Stack)malloc(sizeof(StackType));
    if ()
}

#endif STACKCB_H

