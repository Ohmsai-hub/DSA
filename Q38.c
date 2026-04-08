#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Deque {
    struct Node* front;
    struct Node* rear;
    int size;
};

// Initialize deque
void initDeque(struct Deque* dq) {
    dq->front = dq->rear = NULL;
    dq->size = 0;
}

// Push front
void push_front(struct Deque* dq, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = dq->front;

    if (dq->front == NULL) {
        dq->rear = newNode;
    } else {
        dq->front->prev = newNode;
    }
    dq->front = newNode;
    dq->size++;
}

// Push back
void push_back(struct Deque* dq, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = dq->rear;

    if (dq->rear == NULL) {
        dq->front = newNode;
    } else {
        dq->rear->next = newNode;
    }
    dq->rear = newNode;
    dq->size++;
}

// Pop front
int pop_front(struct Deque* dq) {
    if (dq->front == NULL) return -1;
    struct Node* temp = dq->front;
    int val = temp->data;
    dq->front = dq->front->next;
    if (dq->front) dq->front->prev = NULL;
    else dq->rear = NULL;
    free(temp);
    dq->size--;
    return val;
}

// Pop back
int pop_back(struct Deque* dq) {
    if (dq->rear == NULL) return -1;
    struct Node* temp = dq->rear;
    int val = temp->data;
    dq->rear = dq->rear->prev;
    if (dq->rear) dq->rear->next = NULL;
    else dq->front = NULL;
    free(temp);
    dq->size--;
    return val;
}

// Front element
int front(struct Deque* dq) {
    return dq->front ? dq->front->data : -1;
}

// Back element
int back(struct Deque* dq) {
    return dq->rear ? dq->rear->data : -1;
}

// Empty check
int empty(struct Deque* dq) {
    return dq->size == 0;
}

// Size
int size(struct Deque* dq) {
    return dq->size;
}

// Clear
void clear(struct Deque* dq) {
    while (!empty(dq)) {
        pop_front(dq);
    }
}

// Print deque
void printDeque(struct Deque* dq) {
    struct Node* temp = dq->front;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Deque dq;
    initDeque(&dq);

    // Example operations
    push_back(&dq, 10);
    push_front(&dq, 5);
    push_back(&dq, 20);

    printf("Front: %d\n", front(&dq));
    printf("Back: %d\n", back(&dq));
    printf("Size: %d\n", size(&dq));

    printDeque(&dq);

    printf("Pop front: %d\n", pop_front(&dq));
    printf("Pop back: %d\n", pop_back(&dq));

    printDeque(&dq);

    clear(&dq);
    printf("Empty after clear: %d\n", empty(&dq));

    return 0;
}
