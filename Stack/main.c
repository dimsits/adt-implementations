#include <stdio.h>
#include "STACKARRAY.h"

void main() {
    Stack S;
    initStack(&S);
    push(S, 'a');
    push(S, 'b');
    push(S, 'c');
    pop(S);
    char top = top(S);

}