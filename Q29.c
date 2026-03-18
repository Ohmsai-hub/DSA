#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to count length of linked list
int getLength(struct Node* head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

// Function to rotate linked list right by k places
struct Node* rotateRight(struct Node* head, int k) {
    if (head == NULL || head->next == NULL || k == 0) return head;

    int len = getLength(head);
    k = k % len;  // Handle cases where k >= len
    if (k == 0) return head;

    // Find new tail: (len - k - 1)th node
    struct Node* newTail = head;
    for (int i = 1; i < len - k; i++) {
        newTail = newTail->next;
    }

    // New head is next of newTail
    struct Node* newHead = newTail->next;

    // Find old tail
    struct Node* oldTail = newHead;
    while (oldTail->next != NULL) {
        oldTail = oldTail->next;
    }

    // Connect old tail to old head
    oldTail->next = head;

    // Break link at newTail
    newTail->next = NULL;

    return newHead;
}

// Function to traverse and print linked list
void traverse(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n, k;
    scanf("%d", &n);

    struct Node* head = NULL;
    struct Node* tail = NULL;

    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        struct Node* newNode = createNode(val);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    scanf("%d", &k);

    // Rotate linked list
    head = rotateRight(head, k);

    // Print rotated list
    traverse(head);

    return 0;
}
