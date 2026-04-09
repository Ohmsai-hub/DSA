#include <stdio.h>
#include <stdlib.h>

// Node structure for adjacency list
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Graph structure
typedef struct Graph {
    int numVertices;
    Node** adjLists;
    int* visited;
} Graph;

// Create a new node
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Create a graph with n vertices
Graph* createGraph(int n) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = n;
    graph->adjLists = (Node**)malloc(n * sizeof(Node*));
    graph->visited = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

// Add edge (u, v) - undirected
void addEdge(Graph* graph, int u, int v) {
    Node* newNode = createNode(v);
    newNode->next = graph->adjLists[u];
    graph->adjLists[u] = newNode;

    newNode = createNode(u);
    newNode->next = graph->adjLists[v];
    graph->adjLists[v] = newNode;
}

// DFS with parent tracking
int dfsCycle(Graph* graph, int v, int parent) {
    graph->visited[v] = 1;

    Node* temp = graph->adjLists[v];
    while (temp) {
        int adj = temp->vertex;

        if (!graph->visited[adj]) {
            if (dfsCycle(graph, adj, v)) return 1;
        } else if (adj != parent) {
            return 1; // cycle detected
        }

        temp = temp->next;
    }
    return 0;
}

// Cycle detection
int hasCycle(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        if (!graph->visited[i]) {
            if (dfsCycle(graph, i, -1)) return 1;
        }
    }
    return 0;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    Graph* graph = createGraph(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    if (hasCycle(graph)) printf("YES\n");
    else printf("NO\n");

    return 0;
}
