#include <stdio.h>
#include <stdlib.h>
#define MAX 5

//STRUCTURE DEFINITIONS
typedef struct {
    int elem[MAX];
    int count;
}LIST;

//FUNCTION PROTOTYPES
LIST findEven(LIST L);

void main() {
    LIST L = {{1,2,3,4,5}, 5}, evenList = findEven(L);
}

//FUNCTION DEFINITIONS
LIST findEven(LIST L) {
    LIST even; even.count = 0;
    int i;
    for(i = 0; i < L.count; i++) {
        if (L.elem[i] % 2 == 0) {
            even.elem[even.count++] = L.elem[i];
        }
    }
    return even;
}