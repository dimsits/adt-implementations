#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 6
#define INF 3E7

typedef int graph[MAX][MAX];

void dfs(graph A, int v);
void dijkstra(graph A, int v);


void main() {
    graph g = {{INF, 4, 4, INF, INF, INF},
               {4, INF, 2, INF, INF, INF},
               {4, 2, INF, 3, 1, 6},
               {INF, INF, 3, INF, INF, 2},
               {INF, INF, 1, INF, INF, 3},
               {INF, INF, 6, 2, 3, INF}};

    dijkstra(g, 0);
}

void dfs(graph A, int v) {
    int visited[MAX];
    for (int i = 0; i < MAX; i++) {
        visited[i] = 0;
    }

    int stack[MAX];
    int top = -1;

    stack[++top] = v;

    while (top != -1) {
        int current = stack[top--];
        if (!visited[current]) {
            printf("%d ", current);
            visited[current] = 1;
        }

        for (int i = 0; i < MAX; i++) {
            if (A[current][i] != INF && !visited[i]) {
                stack[++top] = i;
            }
        }
    }
}

void dijkstra(graph A, int v) {
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

        for (int i = 0; i < MAX; i++) {
            if (!visited[i] && A[minIndex][i] && dist[minIndex] != INF && dist[minIndex] + A[minIndex][i] < dist[i]) {
                dist[i] = dist[minIndex] + A[minIndex][i];
            }
        }
    }

    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < MAX; i++) {
        printf("%d\t%d\n", i, dist[i]);
    }
}

void floyd-warshall(graph A) {
    int dist[MAX][MAX];

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            dist[i][j] = A[i][j];
        }
    }

    for (int k = 0; k < MAX; k++) {
        for (int i = 0; i < MAX; i++) {
            for (int j = 0; j < MAX; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printf("Shortest distance between every pair of vertices\n");
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            printf("%d\t", dist[i][j]);
        }
        printf("\n");
    }
}

void prim(graph A) {
    int parent[MAX];
    int key[MAX];
    int visited[MAX];

    for (int i = 0; i < MAX; i++) {
        key[i] = INF;
        visited[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < MAX - 1; count++) {
        int minKey = INF;
        int minIndex = -1;

        for (int i = 0; i < MAX; i++) {
            if (!visited[i] && key[i] < minKey) {
                minKey = key[i];
                minIndex = i;
            }
        }

        visited[minIndex] = 1;

        for (int i = 0; i < MAX; i++) {
            if (!visited[i] && A[minIndex][i] && A[minIndex][i] < key[i]) {
                parent[i] = minIndex;
                key[i] = A[minIndex][i];
            }
        }
    }

    printf("Edge\tWeight\n");
    for (int i = 1; i < MAX; i++) {
        printf("%d - %d\t%d\n", parent[i], i, A[i][parent[i]]);
    }
}

void kruskal(graph A) {
    int parent[MAX];
    int rank[MAX];

    for (int i = 0; i < MAX; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    int edgeCount = 0;
    int edgeIndex = 0;
    int edges[MAX][3];

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (A[i][j] != INF) {
                edges[edgeIndex][0] = i;
                edges[edgeIndex][1] = j;
                edges[edgeIndex][2] = A[i][j];
                edgeIndex++;
            }
        }
    }

    while (edgeCount < MAX - 1) {
        int minEdge = INF;
        int minIndex = -1;

        for (int i = 0; i < edgeIndex; i++) {
            if (edges[i][2] < minEdge) {
                minEdge = edges[i][2];
                minIndex = i;
            }
        }

        int x = edges[minIndex][0];
        int y = edges[minIndex][1];

        int xRoot = x;
        int yRoot = y;

        while (parent[xRoot] != xRoot) {
            xRoot = parent[xRoot];
        }

        while (parent[yRoot] != yRoot) {
            yRoot = parent[yRoot];
        }

        if (xRoot != yRoot) {
            edgeCount++;
            printf("%d - %d\t%d\n", x, y, minEdge);
            if (rank[xRoot] < rank[yRoot]) {
                parent[xRoot] = yRoot;
            } else if (rank[xRoot] > rank[yRoot]) {
                parent[yRoot] = xRoot;
            } else {
                parent[yRoot] = xRoot;
                rank[xRoot]++;
            }
        }

        edges[minIndex][2] = INF;
    }
}


