#include <stdio.h>
#include <stdlib.h>
#include<limits.h>

#define INF 1000

void bellmanFord(int numVertices, int numEdges, int edges[][3], int source) {
    int distance[numVertices];
    // Step 1: Initialize distance to all vertices as INFINITY
    for (int i = 0; i < numVertices; i++) {
        distance[i] = INF;
    }
    distance[source] = 0;
    // Step 2: Relax all edges V-1 times
    for (int i = 1; i < numVertices; i++) {
        for (int j = 0; j < numEdges; j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            int weight = edges[j][2];
            if (distance[u] != INF && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
            }
        }
    }
    // Step 3: Check for negative-weight cycles
    for (int i = 0; i < numEdges; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];
        if (distance[u] != INF && distance[u] + weight < distance[v]) {
            printf("Negative-weight cycle detected!\n");
            return;
        }
    }
    // Print the shortest distances from the source
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < numVertices; i++) {
        printf("%d\t%d\n", i, distance[i]);
    }
}

int main() {
    int numVertices, numEdges, source;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    int edges[numEdges][3];

    printf("Enter the source, destination, and weight of each edge:\n");
    for (int i = 0; i < numEdges; i++) {
        scanf("%d %d %d", &edges[i][0], &edges[i][1], &edges[i][2]);
    }

    printf("Enter the source vertex: ");
    scanf("%d", &source);

    bellmanFord(numVertices, numEdges, edges, source);

    return 0;
}
