#include <stdio.h>
#include <stdlib.h>

#define MAX 10
#define INF 9999

typedef struct Node {
    int vertex;
    int weight;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} AdjList[MAX];

void createAdjList(AdjList adjList, int g[MAX][MAX]) {
    // Initialize adjacency list
    for (int i = 0; i < MAX; i++) {
        adjList[i].head = NULL;
    }

    // Convert matrix to adjacency list
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (g[i][j] != INF) {
                // Create a new node
                Node* newNode = (Node*)malloc(sizeof(Node));
                newNode->vertex = j;
                newNode->weight = g[i][j];
                newNode->next = NULL;

                // Insert the new node at the beginning of the list
                if (adjList[i].head == NULL) {
                    adjList[i].head = newNode;
                } else {
                    newNode->next = adjList[i].head;
                    adjList[i].head = newNode;
                }
            }
        }
    }
}

int main() {
    AdjList adjList;
    int g[MAX][MAX] = {{INF, 4, 4, INF, INF, INF},
                       {4, INF, 2, INF, INF, INF},
                       {4, 2, INF, 3, 1, 6},
                       {INF, INF, 3, INF, INF, 2},
                       {INF, INF, 1, INF, INF, 3},
                       {INF, INF, 6, 2, 3, INF}};

    // Create adjacency list
    createAdjList(adjList, g);

    // Print the adjacency list
    for (int i = 0; i < MAX; i++) {
        printf("Adjacency list for vertex %d:\n", i);
        Node* currentNode = adjList[i].head;
        while (currentNode != NULL) {
            printf("(%d, %d) ", currentNode->vertex, currentNode->weight);
            currentNode = currentNode->next;
        }
        printf("\n");
    }

    return 0;
}


void dijkstra(AdjList a, int v) {
    int dist[MAX];
    int visited[MAX];

    for (int i = 0; i < MAX; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[v] = 0;

    for (int count = 0; count < MAX - 1; count++) {
        int minDist = INF;
        int minIndex = -1;

        for (int i = 0; i < MAX; i++) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                minIndex = i;
            }
        }

        visited[minIndex] = 1;

        Node* currentNode = a[minIndex].head;
        while (currentNode != NULL) {
            if (!visited[currentNode->vertex] && dist[minIndex] + currentNode->weight < dist[currentNode->vertex]) {
                dist[currentNode->vertex] = dist[minIndex] + currentNode->weight;
            }
            currentNode = currentNode->next;
        }
    }

    for (int i = 0; i < MAX; i++) {
        printf("Distance from vertex %d to vertex %d: %d\n", v, i, dist[i]);
    }
}