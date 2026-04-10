#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

// Structure for adjacency list node
typedef struct Node {
    int vertex;
    int weight;
    struct Node* next;
} Node;

// Structure for adjacency list
typedef struct {
    Node* head;
} AdjList;

// Structure for graph
typedef struct {
    int V;
    AdjList* array;
} Graph;

// Create a new adjacency list node
Node* newNode(int vertex, int weight) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->vertex = vertex;
    node->weight = weight;
    node->next = NULL;
    return node;
}

// Create a graph with V vertices
Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->array = (AdjList*)malloc(V * sizeof(AdjList));
    for (int i = 0; i < V; i++)
        graph->array[i].head = NULL;
    return graph;
}

// Add edge (u -> v with weight w)
void addEdge(Graph* graph, int u, int v, int w) {
    Node* node = newNode(v, w);
    node->next = graph->array[u].head;
    graph->array[u].head = node;
}

// Min-Heap structure
typedef struct {
    int vertex;
    int dist;
} HeapNode;

typedef struct {
    int size;
    int capacity;
    int* pos;
    HeapNode** array;
} MinHeap;

// Create heap node
HeapNode* newHeapNode(int v, int dist) {
    HeapNode* node = (HeapNode*)malloc(sizeof(HeapNode));
    node->vertex = v;
    node->dist = dist;
    return node;
}

// Create min heap
MinHeap* createMinHeap(int capacity) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->pos = (int*)malloc(capacity * sizeof(int));
    heap->size = 0;
    heap->capacity = capacity;
    heap->array = (HeapNode**)malloc(capacity * sizeof(HeapNode*));
    return heap;
}

// Swap two heap nodes
void swapHeapNode(HeapNode** a, HeapNode** b) {
    HeapNode* t = *a;
    *a = *b;
    *b = t;
}

// Heapify at index
void minHeapify(MinHeap* heap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < heap->size &&
        heap->array[left]->dist < heap->array[smallest]->dist)
        smallest = left;

    if (right < heap->size &&
        heap->array[right]->dist < heap->array[smallest]->dist)
        smallest = right;

    if (smallest != idx) {
        HeapNode* smallestNode = heap->array[smallest];
        HeapNode* idxNode = heap->array[idx];

        heap->pos[smallestNode->vertex] = idx;
        heap->pos[idxNode->vertex] = smallest;

        swapHeapNode(&heap->array[smallest], &heap->array[idx]);
        minHeapify(heap, smallest);
    }
}

// Extract min node
HeapNode* extractMin(MinHeap* heap) {
    if (heap->size == 0)
        return NULL;

    HeapNode* root = heap->array[0];
    HeapNode* lastNode = heap->array[heap->size - 1];
    heap->array[0] = lastNode;

    heap->pos[root->vertex] = heap->size - 1;
    heap->pos[lastNode->vertex] = 0;

    heap->size--;
    minHeapify(heap, 0);

    return root;
}

// Decrease key
void decreaseKey(MinHeap* heap, int v, int dist) {
    int i = heap->pos[v];
    heap->array[i]->dist = dist;

    while (i && heap->array[i]->dist < heap->array[(i - 1) / 2]->dist) {
        heap->pos[heap->array[i]->vertex] = (i - 1) / 2;
        heap->pos[heap->array[(i - 1) / 2]->vertex] = i;
        swapHeapNode(&heap->array[i], &heap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Check if heap is empty
int isEmpty(MinHeap* heap) {
    return heap->size == 0;
}

// Dijkstra’s Algorithm
void dijkstra(Graph* graph, int src) {
    int V = graph->V;
    int dist[V];

    MinHeap* heap = createMinHeap(V);

    for (int v = 0; v < V; v++) {
        dist[v] = INF;
        heap->array[v] = newHeapNode(v, dist[v]);
        heap->pos[v] = v;
    }

    dist[src] = 0;
    decreaseKey(heap, src, dist[src]);
    heap->size = V;

    while (!isEmpty(heap)) {
        HeapNode* minNode = extractMin(heap);
        int u = minNode->vertex;

        Node* pCrawl = graph->array[u].head;
        while (pCrawl != NULL) {
            int v = pCrawl->vertex;

            if (heap->pos[v] < heap->size && dist[u] != INF &&
                pCrawl->weight + dist[u] < dist[v]) {
                dist[v] = dist[u] + pCrawl->weight;
                decreaseKey(heap, v, dist[v]);
            }
            pCrawl = pCrawl->next;
        }
    }

    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

// Example usage
int main() {
    int V = 9;
    Graph* graph = createGraph(V);
    addEdge(graph, 0, 1, 4);
    addEdge(graph, 0, 7, 8);
    addEdge(graph, 1, 2, 8);
    addEdge(graph, 1, 7, 11);
    addEdge(graph, 2, 3, 7);
    addEdge(graph, 2, 8, 2);
    addEdge(graph, 2, 5, 4);
    addEdge(graph, 3, 4, 9);
    addEdge(graph, 3, 5, 14);
    addEdge(graph, 4, 5, 10);
    addEdge(graph, 5, 6, 2);
    addEdge(graph, 6, 7, 1);
    addEdge(graph, 6, 8, 6);
    addEdge(graph, 7, 8, 7);

    dijkstra(graph, 0);

    return 0;
}
