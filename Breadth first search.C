#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Queue data structure for BFS
struct Queue {
    int items[MAX_VERTICES];
    int front;
    int rear;
};

// Graph data structure
struct Graph {
    int vertices;
    int** adjMatrix;
};

// Create a queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// Enqueue an item
void enqueue(struct Queue* queue, int value) {
    if (queue->rear == MAX_VERTICES - 1)
        printf("Queue is full");
    else {
        if (queue->front == -1)
            queue->front = 0;
        queue->rear++;
        queue->items[queue->rear] = value;
    }
}

// Dequeue an item
int dequeue(struct Queue* queue) {
    int item;
    if (queue->front == -1)
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Queue data structure for BFS
struct Queue {
    int items[MAX_VERTICES];
    int front;
    int rear;
};

// Graph data structure
struct Graph {
    int vertices;
    int** adjMatrix;
};

// Create a queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// Enqueue an item
void enqueue(struct Queue* queue, int value) {
    if (queue->rear == MAX_VERTICES - 1)
        printf("Queue is full");
    else {
        if (queue->front == -1)
            queue->front = 0;
        queue->rear++;
        queue->items[queue->rear] = value;
    }
}

// Dequeue an item
int dequeue(struct Queue* queue) {
    int item;
    if (queue->front == -1)
        printf("Queue is empty");
    else {
        item = queue->items[queue->front];
        queue->front++;
        if (queue->front > queue->rear) {
            queue->front = queue->rear = -1;
        }
        return item;
    }
}

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

// Breadth First Search traversal
void BFS(struct Graph* graph, int startVertex) {
    struct Queue* queue = createQueue();
    int visited[MAX_VERTICES] = {0};

    visited[startVertex] = 1;
    enqueue(queue, startVertex);

    while (queue->front != -1) {
        int currentVertex = dequeue(queue);
        printf("%d ", currentVertex);

        for (int i = 0; i < graph->vertices; i++) {
            if (graph->adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                enqueue(queue, i);
                visited[i] = 1;
            }
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
    printf("Enter the start vertex for BFS traversal: ");
    scanf("%d", &startVertex);

    printf("BFS traversal starting from vertex %d:\n", startVertex);
    BFS(graph, startVertex);

    return 0;
}
￼Enter        printf("Queue is empty");
    else {
        item = queue->items[queue->front];
        queue->front++;
        if (queue->front > queue->rear) {
            queue->front = queue->rear = -1;
        }
        return item;
    }
}

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

 edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1;
}

// Breadth First Search traversal
void BFS(struct Graph* graph, int startVertex) {
    struct Queue* queue = createQueue();
    int visited[MAX_VERTICES] = {0};

    visited[startVertex] = 1;
    enqueue(queue, startVertex);

    while (queue->front != -1) {
        int currentVertex = dequeue(queue);
        printf("%d ", currentVertex);

        for (int i = 0; i < graph->vertices; i++) {
            if (graph->adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                enqueue(queue, i);
                visited[i] = 1;
            }
        }
    }
}
