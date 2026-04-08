#include <stdio.h>

#define MAX 1000  // maximum stack size

int stack[MAX];
int top = -1;

// Push operation
void push(int x) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = x;
}

// Pop operation
void pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return;
    }
    top--;
}

int main() {
    int n, m, i, val;

    // Input number of pushes
    scanf("%d", &n);

    // Push n elements
    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        push(val);
    }

    // Input number of pops
    scanf("%d", &m);

    // Perform m pops
    for (i = 0; i < m; i++) {
        pop();
    }

    // Print remaining stack from top to bottom
    for (i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    return 0;
}
