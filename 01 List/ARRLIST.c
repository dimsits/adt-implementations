#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
    char *elem;
    int ctr;
}*list, listType;

void initList(list *A);
void insertElem(list *A, int val);
void deleteElem(list *A, int val);

void main() {
    list L;

    initList(&L);
    insertElem(&L)
}

void initList(list *A) {
    *A = (list*)malloc(sizeof(listType));
    if (*A != NULL) {
        (*A)->elem = (char*)malloc(MAX * sizeof(char));
        (*A)->ctr = 0;
    }

}