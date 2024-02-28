#ifndef QUEUECB_H
#define QUEUECB_H
#include <stdlib.h>
#define MAX 10

typedef struct {
    char elem;
    int link;
}*node, nodeType;

typedef struct {
    node nodes;
    int avail;
}*VHeap, VHType;

typedef int List;

typedef struct {
    VHeap heap;
    List front;
    List rear;
}*Queue, queueType;

typedef enum { TRUE, FALSE }Bool;

//VHEAP MANAGEMENT
void initVH(VHeap *V); //LINK ALL CELLS STORES 1ST AVAILABLE NODE TO AVAIL
int allocspace(VHeap *V); //IF THERE'S SPACE, REMOVE AVAIL NODE AND RETURN ITS INDEX. RETURN -1 IF FULL
void deallocspace(VHeap *V, int ndx); //GIVEN INDEX, FUNCTION WILL PUT NODE IN AVAIL

//QUEUE OPERATIONS
void initQueue(Queue *Q);
void enqueue(Queue *Q, char c);
void dequeue(Queue *Q);
Bool isEmpty(Queue Q);


void initVH(VHeap *V) {
    (*V) = (VHeap)malloc(sizeof(VHType));
    if ((*V) != NULL) {
        (*V)->nodes = (node)malloc(MAX * sizeof(nodeType));
        if ((*V)->nodes != NULL) {
            (*V)->avail = 0;
            int i;
            for (i = 0; i < MAX - 1; i++) {
                (*V)->nodes[i]->link = i + 1;
            }
            (*V)->nodes[i].link = -1;
        }
    }
}

int allocspace(VHeap *V) {
    int temp = -1;
    if ((*V)->avail != -1) {
        temp = (*V)->avail;
        (*V)->avail = (*V)->nodes[(*V)->avail].link;
    }
    return temp;
}

void deallocspace(VHeap *V, int ndx) {
    if (ndx < MAX) {
        (*V)->nodes[ndx].link = (*V)->avail;
        (*V)->avail = ndx;
    }
}

void initQueue(Queue *Q) {
    (*Q) = (Queue)malloc(sizeof(queueType));
    if ((*Q) != NULL) {
        initVH(&((*Q)->heap));
        (*Q)->front = -1;
        (*Q)->rear = -1;
    }
}

Bool isEmpty(Queue Q) {
    return Q->front == -1 && Q->rear == -1 ? TRUE : FALSE;
}

void enqueue(Queue *Q, char c) {
    int ndx = allocspace(&((*Q)->heap));
    if (ndx != -1) {
        (*Q)->heap->nodes[ndx].elem = c;
        (*Q)->heap->nodes[(*Q)->rear].link = ndx;
        (*Q)->rear = ndx;
        if (isEmpty(*Q) == TRUE) {
            (*Q)->front = ndx;
        }
    }
}

void dequeue(Queue *Q) {
    if (isEmpty(*Q) == FALSE) {
        int temp = (*Q)->front;
        (*Q)->front = (*Q)->
    }
}

#endif


