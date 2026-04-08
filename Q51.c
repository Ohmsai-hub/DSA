#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Insert into BST
struct Node* insert(struct Node* root, int val) {
    if (root == NULL) return newNode(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);

    return root;
}

// Find LCA in BST
struct Node* findLCA(struct Node* root, int n1, int n2) {
    if (root == NULL) return NULL;

    if (n1 < root->data && n2 < root->data)
        return findLCA(root->left, n1, n2);

    if (n1 > root->data && n2 > root->data)
        return findLCA(root->right, n1, n2);

    return root; // split point → LCA
}

int main() {
    int N;
    scanf("%d", &N);

    struct Node* root = NULL;
    for (int i = 0; i < N; i++) {
        int val;
        scanf("%d", &val);
        root = insert(root, val);
    }

    int n1, n2;
    scanf("%d %d", &n1, &n2);

    struct Node* lca = findLCA(root, n1, n2);
    if (lca)
        printf("%d\n", lca->data);
    else
        printf("-1\n"); // if nodes not found
    return 0;
}
