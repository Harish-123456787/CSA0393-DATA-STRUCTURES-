#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Graph data structure
struct Graph {
    int vertices;
    int** adjMatrix;
};

// Create a graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;

    graph->adjMatrix = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        graph->adjMatrix[i] = (int*)malloc(vertices * sizeof(int));
        for (int j = 0; j < vertices; j++)
            graph->adjMatrix[i][j] = 0;
    }

    return graph;
}

// Add edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1;
}

// Depth First Search traversal
void DFS(struct Graph* graph, int vertex, int visited[]) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < graph->vertices; i++) {
        if (graph->adjMatrix[vertex][i] == 1 && !visited[i]) {
            DFS(graph, i, visited);
        }
    }
}

int main() {
    int vertices, edges;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    struct Graph* graph = createGraph(vertices);

    for (int i = 0; i < edges; i++) {
        int src, dest;
        printf("Enter edge %d source and destination: ", i + 1);
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    int startVertex;
    printf("Enter the start vertex for DFS traversal: ");
    scanf("%d", &startVertex);

    int visited[MAX_VERTICES] = {0};
    printf("DFS traversal starting from vertex %d:\n", startVertex);
    DFS(graph, startVertex, visited);

    return 0;
}
