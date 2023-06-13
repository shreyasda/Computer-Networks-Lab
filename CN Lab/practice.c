#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INF 1000
void bellmanford(int numVertices, int numEdges, int edges[][3], int source){
    int distance[numVertices];
    for(int i=0;i<numVertices;i++){
        distance[i] = INF;
    }
    distance[source] = 0;
    for(int i=1;i<numVertices;i++){
        for(int j=0;j<numEdges;j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int weight = edges[j][2];
            if(distance[u]!=INF && distance[u] + weight < distance[v]){
                distance[v] = distance[u] + weight;
            }
        }
    }

    for(int i=0;i<numEdges;i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];
        if(distance[u]!=INF && distance[u] + weight < distance[v]){
            printf("Negative Edge Cycle is present\n");
        }
    }

    printf("Vertices\tDistance from Source\n");
    for(int i=0;i<numVertices;i++){
        printf("%d\t%d\n",i,distance[i]);
    }
}

int main()
{
    int numEdges, numVertices, source, i;
    
    printf("Enter the number of vertices:\n");
    scanf("%d",&numVertices);

    printf("Enter the number of Edges:\n");
    scanf("%d",&numEdges);

    int edges[numEdges][3];
    printf("Enter the Source, Destination and Distance from the source:\n");
    for(i=0;i<numEdges;i++){
        scanf("%d %d %d",&edges[i][0],&edges[i][1],&edges[i][2]);
    }

    printf("Enter the source vertex:\n");
    scanf("%d",&source);
    bellmanford(numVertices,numEdges,edges,source);
    return 0;
}