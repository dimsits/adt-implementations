#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H
#include <stdlib.h>
#define MAX 5

typedef struct {
    char *elem;
    int top;
}*Stack, StackType; //V4

typedef enum {TRUE, FALSE}boolean;

//UTILITY
void initStack(Stack *S);//Initialize to be empty
boolean isEmpty(Stack S); S, char c);
void pop(Stack S);
char top(Stack S);

void initStack(Stack *S) {
    (*S) = (Stack)malloc(sizeof(StackType));
    if ((*S) != NULL) {
        (*S)->elem = (char*)malloc(MAX * sizeof(char));
        if ((*S)->elem != NULL) {
            (*S)->top = -1;
        }
    }
}
boolean isEmpty(Stack S) {
    return S->top == -1 ? TRUE : FALSE; 
}
boolean isFull(Stack S) {
    return S->top == MAX - 1 ? TRUE : FALSE;
}

void push(Stack S, char c) {
    if (isFull(S) == FALSE) {
        S->elem[++S->top] = c;
    }
}
void pop(Stack S) {
    if (isEmpty(S) == FALSE) {
        S->top--;
    }
}
char top(Stack S) {
    return isEmpty(S) == FALSE ? S->elem[S->top]: NULL;
}

#endif ARRAYSTACK_H
