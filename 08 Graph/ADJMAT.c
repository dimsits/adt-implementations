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
}

void dfs(graph A, int v) {
    
}

void di


