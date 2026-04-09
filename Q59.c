#include <stdio.h>
#include <stdlib.h>

// Define Node structure
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

// Search for index of value in inorder[]
int search(int inorder[], int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == val) return i;
    }
    return -1;
}

// Recursive function to build tree
Node* buildTree(int inorder[], int postorder[], int start, int end, int* postIndex) {
    if (start > end) return NULL;

    Node* root = newNode(postorder[*postIndex]);
    (*postIndex)--;

    if (start == end) return root;

    int inIndex = search(inorder, start, end, root->val);

    // Build right subtree first (since postorder is Left-Right-Root)
    root->right = buildTree(inorder, postorder, inIndex + 1, end, postIndex);
    root->left = buildTree(inorder, postorder, start, inIndex - 1, postIndex);

    return root;
}

// Preorder traversal
void preorder(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int N;
    scanf("%d", &N);

    int inorder[N], postorder[N];
    for (int i = 0; i < N; i++) scanf("%d", &inorder[i]);
    for (int i = 0; i < N; i++) scanf("%d", &postorder[i]);

    int postIndex = N - 1;
    Node* root = buildTree(inorder, postorder, 0, N - 1, &postIndex);

    preorder(root);
    printf("\n");

    return 0;
}
