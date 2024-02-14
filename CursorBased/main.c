#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

//STRUCTURE DEFINITIONS
typedef struct {
    char elem;
    int link;
}node;

typedef struct {
    node *Nodes;
    int avail;
}VHeap;

typedef int List;

//FUNCTION PROTOTYPES

//HEAP MANAGEMENT
void initVH(VHeap **V); //LINK ALL CELLS STORES 1ST AVAILABLE NODE TO AVAIL
int allocspace(VHeap **V); //IF THERE'S SPACE, REMOVE AVAIL NODE AND RETURN ITS INDEX. RETURN -1 IF FULL
void deallocspace(VHeap **V, int ndx); //GIVEN INDEX, FUNCTION WILL PUT NODE IN AVAIL

//LIST OPERATIONS
void insertPos(VHeap **V, List *L, char val, int pos);
void deletePos(VHeap **V, List *L, int pos);



void main() {
     VHeap *CBList;
     initVH(&CBList);
     List L;

     insertPos(&CBList, &L, 'a', 0);
     insertPos(&CBList, &L, 'b', 0);
     insertPos(&CBList, &L, 'c', 0);
}

//FUNCTION DEFINITIONS

//HEAP MANAGEMENT
void initVH(VHeap **V) {
    (*V) = (VHeap*)malloc(sizeof(VHeap));
    if (V != NULL) {
        (*V)->avail = 0;
        (*V)->Nodes = (node*)malloc(MAX * sizeof(node));
        if ((*V)->Nodes != NULL) {
            int i;
            for (i = 0; i < MAX - 1; i++) {
                (*V)->Nodes[i].link = i + 1;
            }
            (*V)->Nodes[i].link = -1;
        }
    }
}

int allocspace(VHeap **V) {
    int capacity = -1;

    if ((*V)->avail != -1) {
        capacity = (*V)->avail;
        (*V)->avail = (*V)->Nodes[(*V)->avail].link;
    }
    return capacity;

}

void deallocspace(VHeap **V, int ndx) {
    if (ndx != -1) {
        (*V)->Nodes[ndx].link = (*V)->avail;
        (*V)->avail = ndx;
    }
}

//LIST OPERATIONS
void insertPos(VHeap **V, List *L, char val, int pos) {
    if ((*V)->avail != -1) {
        int *trav; int i;
        for (trav = &((*V)->avail), i = 0; (*trav) != -1 && i <= pos; trav = &((*V)->Nodes[(*trav)].link), i++) {}
        if (i <= pos) {
            int temp = allocspace(V);
            (*V)->Nodes[temp].elem = val;
            (*V)->Nodes[temp].link = (*trav);
            *trav = temp;
            if (pos == 0) {
                (*L) = (*V)->avail;
            }
        }
    }
}