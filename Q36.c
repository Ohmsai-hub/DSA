#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Queue structure
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Initialize queue
void initQueue(struct Queue* q) {
    q->front = q->rear = NULL;
}

// Enqueue operation
void enqueue(struct Queue* q, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (q->front == NULL) {
        q->front = q->rear = newNode;
        q->rear->next = q->front;  // circular link
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
        q->rear->next = q->front;  // maintain circular link
    }
}

// Dequeue operation
void dequeue(struct Queue* q) {
    if (q->front == NULL) {
        return; // empty queue
    }

    if (q->front == q->rear) {
        free(q->front);
        q->front = q->rear = NULL;
    } else {
        struct Node* temp = q->front;
        q->front = q->front->next;
        q->rear->next = q->front;  // maintain circular link
        free(temp);
    }
}

// Print queue elements from front to rear
void printQueue(struct Queue* q) {
    if (q->front == NULL) return;

    struct Node* temp = q->front;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != q->front);
}

int main() {
    int n, m, val;
    scanf("%d", &n);

    struct Queue q;
    initQueue(&q);

    // Enqueue n elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        enqueue(&q, val);
    }

    // Perform m dequeues
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        dequeue(&q);
    }

    // Print remaining queue
    printQueue(&q);

    return 0;
}
