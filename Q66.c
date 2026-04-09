#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

// utility DFS function
bool isCyclicUtil(struct Graph* graph, int v, bool visited[], bool recStack[]) {
    visited[v] = true;
    recStack[v] = true;

    struct Node* temp = graph->adj[v];
    while (temp != NULL) {
        int neighbour = temp->vertex;
        if (!visited[neighbour] && isCyclicUtil(graph, neighbour, visited, recStack))
            return true;
        else if (recStack[neighbour])
            return true;
        temp = temp->next;
    }

    recStack[v] = false;
    return false;
}

// main cycle detection
bool isCyclic(struct Graph* graph) {
    bool* visited = (bool*)calloc(graph->V, sizeof(bool));
    bool* recStack = (bool*)calloc(graph->V, sizeof(bool));

    for (int i = 0; i < graph->V; i++) {
        if (!visited[i]) {
            if (isCyclicUtil(graph, i, visited, recStack))
                return true;
        }
    }
    return false;
}

int main() {
    int V = 5;
    struct Graph* graph = createGraph(V);

    // Example edges
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0); // cycle here
    addEdge(graph, 3, 4);

    if (isCyclic(graph))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
