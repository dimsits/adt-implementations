#include "../includes.h"
#include "LISTARR.h"

void main() {
    ListPTR L;
    initList(&L);
    insertSorted(L, 4);
    insertSorted(L, 3);
    insertSorted(L, 6);
    displayList(L);
}