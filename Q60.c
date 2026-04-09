#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *left, *right;
} Node;

// Create new node
Node* newNode(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Build tree from level-order array
Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    Node** nodes = (Node**)malloc(n * sizeof(Node*));
    for (int i = 0; i < n; i++) {
        if (arr[i] == -1) nodes[i] = NULL;
        else nodes[i] = newNode(arr[i]);
    }

    for (int i = 0, j = 1; j < n; i++) {
        if (nodes[i] != NULL) {
            if (j < n) nodes[i]->left = nodes[j++];
            if (j < n) nodes[i]->right = nodes[j++];
        }
    }
    Node* root = nodes[0];
    free(nodes);
    return root;
}

// Check Min-Heap property recursively
int isMinHeap(Node* root) {
    if (root == NULL) return 1;

    if (root->left) {
        if (root->val > root->left->val) return 0;
    }
    if (root->right) {
        if (root->val > root->right->val) return 0;
    }

    return isMinHeap(root->left) && isMinHeap(root->right);
}

// Check completeness using level-order
int isComplete(int arr[], int n) {
    int foundNull = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == -1) foundNull = 1;
        else if (foundNull) return 0; // Non-null after null → not complete
    }
    return 1;
}

int main() {
    int N;
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++) scanf("%d", &arr[i]);

    Node* root = buildTree(arr, N);

    if (isComplete(arr, N) && isMinHeap(root))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
