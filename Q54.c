#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure
struct Node {
    int val;
    struct Node* left;
    struct Node* right;
};

// Queue for building tree
struct Queue {
    struct Node** arr;
    int front, rear, size;
};

// Create new node
struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Queue functions
struct Queue* createQueue(int size) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->arr = (struct Node**)malloc(size * sizeof(struct Node*));
    q->front = q->rear = 0;
    q->size = size;
    return q;
}

void enqueue(struct Queue* q, struct Node* node) {
    q->arr[q->rear++] = node;
}

struct Node* dequeue(struct Queue* q) {
    return q->arr[q->front++];
}

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

// Zigzag (spiral) level order traversal
void zigzagTraversal(struct Node* root) {
    if (!root) return;

    struct Queue* q = createQueue(1000);
    enqueue(q, root);

    bool leftToRight = true;

    while (!isEmpty(q)) {
        int levelSize = q->rear - q->front;
        int* level = (int*)malloc(levelSize * sizeof(int));

        for (int i = 0; i < levelSize; i++) {
            struct Node* node = dequeue(q);
            int index = leftToRight ? i : (levelSize - 1 - i);
            level[index] = node->val;

            if (node->left) enqueue(q, node->left);
            if (node->right) enqueue(q, node->right);
        }

        // Print this level
        for (int i = 0; i < levelSize; i++) {
            printf("%d ", level[i]);
        }
        free(level);

        leftToRight = !leftToRight; // flip direction
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
    zigzagTraversal(root);

    return 0;
}
