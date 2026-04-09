#include <stdio.h>
#include <stdlib.h>

// adjacency list node
struct Node {
    int vertex;
    struct Node* next;
};

// graph structure
struct Graph {
    int V;
    struct Node** adj;
};

// create a new node
struct Node* newNode(int v) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->vertex = v;
    node->next = NULL;
    return node;
}

// create a graph with V vertices
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->adj = (struct Node**)malloc(V * sizeof(struct Node*));
    for (int i = 0; i < V; i++)
        graph->adj[i] = NULL;
    return graph;
}

// add edge u -> v
void addEdge(struct Graph* graph, int u, int v) {
    struct Node* node = newNode(v);
    node->next = graph->adj[u];
    graph->adj[u] = node;
}

// queue implementation
struct Queue {
    int* arr;
    int front, rear, size, capacity;
};

struct Queue* createQueue(int capacity) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->capacity = capacity;
    q->arr = (int*)malloc(capacity * sizeof(int));
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    return q;
}

int isEmpty(struct Queue* q) {
    return q->size == 0;
}

void enqueue(struct Queue* q, int item) {
    q->rear++;
    q->arr[q->rear] = item;
    q->size++;
}

int dequeue(struct Queue* q) {
    int item = q->arr[q->front];
    q->front++;
    q->size--;
    return item;
}

// Kahn's Algorithm
void topologicalSort(struct Graph* graph) {
    int V = graph->V;
    int* indegree = (int*)calloc(V, sizeof(int));

    // compute in-degree of each vertex
    for (int u = 0; u < V; u++) {
        struct Node* temp = graph->adj[u];
        while (temp != NULL) {
            indegree[temp->vertex]++;
            temp = temp->next;
        }
    }

    struct Queue* q = createQueue(V);

    // enqueue all vertices with in-degree 0
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0)
            enqueue(q, i);
    }

    int count = 0;
    int* topoOrder = (int*)malloc(V * sizeof(int));

    while (!isEmpty(q)) {
        int u = dequeue(q);
        topoOrder[count++] = u;

        // decrease in-degree of neighbours
        struct Node* temp = graph->adj[u];
        while (temp != NULL) {
            indegree[temp->vertex]--;
            if (indegree[temp->vertex] == 0)
                enqueue(q, temp->vertex);
            temp = temp->next;
        }
    }

    // if count != V, graph has a cycle
    if (count != V) {
        printf("Graph is not a DAG (contains cycle)\n");
        return;
    }

    // print topological order
    printf("Topological Ordering: ");
    for (int i = 0; i < V; i++)
        printf("%d ", topoOrder[i]);
    printf("\n");
}

int main() {
    int V = 6;
    struct Graph* graph = createGraph(V);

    // Example DAG
    addEdge(graph, 5, 2);
    addEdge(graph, 5, 0);
    addEdge(graph, 4, 0);
    addEdge(graph, 4, 1);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 1);

    topologicalSort(graph);

    return 0;
}
