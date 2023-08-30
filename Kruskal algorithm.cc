#include <stdio.h>
#include <stdlib.h>

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Structure to represent a graph
struct Graph {
    int V, E;
    struct Edge* edges;
};

// Create a graph with V vertices and E edges
struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edges = (struct Edge*)malloc(E * sizeof(struct Edge));
    return graph;
}

// Compare function for sorting edges based on weight
int compareEdges(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

// Find parent of a vertex in the disjoint set
int findParent(int parent[], int vertex) {
    if (parent[vertex] == -1)
        return vertex;
    return findParent(parent, parent[vertex]);
}

// Perform union of two sets of vertices
void unionSets(int parent[], int x, int y) {
    int xRoot = findParent(parent, x);
    int yRoot = findParent(parent, y);
    parent[xRoot] = yRoot;
}

// Kruskal's algorithm to find Minimum Spanning Tree
void kruskal(struct Graph* graph) {
    int V = graph->V;
    struct Edge result[V];  // To store the resultant MST
    int e = 0;  // Index variable for result[]
    int i = 0;  // Index variable for sorted edges
    
    // Sort all the edges in ascending order of their weight
    qsort(graph->edges, graph->E, sizeof(struct Edge), compareEdges);
    
    int parent[V];
    for (int v = 0; v < V; v++)
        parent[v] = -1;

    while (e < V - 1 && i < graph->E) {
        struct Edge nextEdge = graph->edges[i++];
        int x = findParent(parent, nextEdge.src);
        int y = findParent(parent, nextEdge.dest);

        if (x != y) {
            result[e++] = nextEdge;
            unionSets(parent, x, y);
        }
    }
    
    printf("Edges in the Minimum Spanning Tree:\n");
    for (i = 0; i < e; ++i)
        printf("%d -- %d\n", result[i].src, result[i].dest);
}

int main() {
    int V = 4; // Number of vertices
    int E = 5; // Number of edges
    struct Graph* graph = createGraph(V, E);

    // Adding edges with their weights
    graph->edges[0].src = 0;
    graph->edges[0].dest = 1;
    graph->edges[0].weight = 10;

    graph->edges[1].src = 0;
    graph->edges[1].dest = 2;
    graph->edges[1].weight = 6;

    graph->edges[2].src = 0;
    graph->edges[2].dest = 3;
    graph->edges[2].weight = 5;

    graph->edges[3].src = 1;
    graph->edges[3].dest = 3;
    graph->edges[3].weight = 15;

    graph->edges[4].src = 2;
    graph->edges[4].dest = 3;
    graph->edges[4].weight = 4;

    kruskal(graph);

    return 0;
}
