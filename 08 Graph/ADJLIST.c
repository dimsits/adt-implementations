#include <stdio.h>
#include <stdlib.h>
#include MAX 10

typedef struct {
    int vertex;
    int weight;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} AdjList[MAX];
