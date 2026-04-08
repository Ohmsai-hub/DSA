#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Queue
int queue[MAX];
int front = -1, rear = -1;

void enqueue(int x) {
    if (rear == MAX - 1) return; // overflow
    if (front == -1) front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1 || front > rear) return -1; // empty
    return queue[front++];
}

// Stack
int stack[MAX];
int top = -1;

void push(int x) {
    if (top == MAX - 1) return; // overflow
    stack[++top] = x;
}

int pop() {
    if (top == -1) return -1; // empty
    return stack[top--];
}

int main() {
    int N;
    scanf("%d", &N);

    // Input queue elements
    for (int i = 0; i < N; i++) {
        int val;
        scanf("%d", &val);
        enqueue(val);
    }

    // Move queue elements to stack
    while (front != -1 && front <= rear) {
        push(dequeue());
    }

    // Move stack elements back to queue
    front = 0; rear = -1; // reset queue
    while (top != -1) {
        enqueue(pop());
    }

    // Print reversed queue
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}
