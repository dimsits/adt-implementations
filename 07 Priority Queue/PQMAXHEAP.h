#include "includes.h"
#define MAX 0xFF

typedef struct {
    int arr[MAX];
    int lastndx;
}heap;

int member(heap h);
void insert(heap *h, int val);
void heapsort(heap *h);
void heapify(heap *h);

