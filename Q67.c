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

// stack for storing topological order
struct Stack {
    int* arr;
    int top;
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

// stack functions
struct Stack* createStack(int V) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->arr = (int*)malloc(V * sizeof(int));
    stack->top = -1;
    return stack;
}

void push(struct Stack* stack, int v) {
    stack->arr[++stack->top] = v;
}

int pop(struct Stack* stack) {
    return stack->arr[stack->top--];
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// DFS utility
void topologicalUtil(struct Graph* graph, int v, int visited[], struct Stack* stack) {
    visited[v] = 1;

    struct Node* temp = graph->adj[v];
    while (temp != NULL) {
        if (!visited[temp->vertex])
            topologicalUtil(graph, temp->vertex, visited, stack);
        temp = temp->next;
    }

    // push current vertex to stack after visiting all neighbours
    push(stack, v);
}

// main topological sort
void topologicalSort(struct Graph* graph) {
    int* visited = (int*)calloc(graph->V, sizeof(int));
    struct Stack* stack = createStack(graph->V);

    for (int i = 0; i < graph->V; i++) {
        if (!visited[i])
            topologicalUtil(graph, i, visited, stack);
    }

    // print contents of stack
    while (!isEmpty(stack)) {
        printf("%d ", pop(stack));
    }
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

    printf("Topological Ordering: ");
    topologicalSort(graph);

    return 0;
}
