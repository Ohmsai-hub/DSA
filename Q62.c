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
    Node** adjLists; // array of linked lists
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

    for (int i = 0; i < n; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

// Add edge (u, v)
void addEdge(Graph* graph, int u, int v, int isDirected) {
    // Add v to u's list
    Node* newNode = createNode(v);
    newNode->next = graph->adjLists[u];
    graph->adjLists[u] = newNode;

    // If undirected, add u to v's list
    if (!isDirected) {
        newNode = createNode(u);
        newNode->next = graph->adjLists[v];
        graph->adjLists[v] = newNode;
    }
}

// Print adjacency list
void printGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        printf("%d: ", i);
        Node* temp = graph->adjLists[i];
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    Graph* graph = createGraph(n);

    // Change isDirected = 1 for directed graph, 0 for undirected
    int isDirected = 0;

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v, isDirected);
    }

    printGraph(graph);

    return 0;
}
