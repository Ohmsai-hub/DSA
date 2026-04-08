#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

// Node structure
struct Node {
    int val;
    struct Node* left;
    struct Node* right;
};

// Queue structure for building tree
struct Queue {
    struct Node** arr;
    int front, rear, size;
};

// Create a new node
struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Initialize queue
struct Queue* createQueue(int size) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->arr = (struct Node**)malloc(size * sizeof(struct Node*));
    q->front = q->rear = 0;
    q->size = size;
    return q;
}

// Enqueue
void enqueue(struct Queue* q, struct Node* node) {
    q->arr[q->rear++] = node;
}

// Dequeue
struct Node* dequeue(struct Queue* q) {
    return q->arr[q->front++];
}

// Check if queue is empty
int isEmpty(struct Queue* q) {
    return q->front == q->rear;
}

// Build tree from level order input
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = newNode(arr[0]);
    struct Queue* q = createQueue(n);
    enqueue(q, root);

    int i = 1;
    while (!isEmpty(q) && i < n) {
        struct Node* curr = dequeue(q);

        // Left child
        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            enqueue(q, curr->left);
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            enqueue(q, curr->right);
        }
        i++;
    }
    return root;
}

// Structure to store node with horizontal distance
struct Pair {
    struct Node* node;
    int hd;
};

// Vertical Order Traversal
void verticalOrder(struct Node* root) {
    if (!root) return;

    // Map HD to nodes (using array offset)
    int offset = 1000; // to handle negative HD
    int maxSize = 2000;
    int* colCount = (int*)calloc(maxSize, sizeof(int));
    int** colNodes = (int**)malloc(maxSize * sizeof(int*));
    for (int i = 0; i < maxSize; i++) {
        colNodes[i] = (int*)malloc(100 * sizeof(int)); // assume max 100 nodes per column
    }

    // BFS traversal
    struct Pair queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = (struct Pair){root, 0};

    while (front < rear) {
        struct Pair p = queue[front++];
        struct Node* node = p.node;
        int hd = p.hd + offset;

        colNodes[hd][colCount[hd]++] = node->val;

        if (node->left) queue[rear++] = (struct Pair){node->left, p.hd - 1};
        if (node->right) queue[rear++] = (struct Pair){node->right, p.hd + 1};
    }

    // Print columns
    for (int i = 0; i < maxSize; i++) {
        if (colCount[i] > 0) {
            for (int j = 0; j < colCount[i]; j++) {
                printf("%d ", colNodes[i][j]);
            }
            printf("\n");
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);

    int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, N);
    verticalOrder(root);

    return 0;
}
