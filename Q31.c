#include <stdio.h>
#define MAX 100   // maximum size of stack

int stack[MAX];
int top = -1;

// Push operation
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = value;
    }
}

// Pop operation
void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
    } else {
        printf("%d\n", stack[top--]);
    }
}

// Display operation
void display() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);  // number of operations

    for (int i = 0; i < n; i++) {
        int op, value;
        scanf("%d", &op);

        if (op == 1) {          // push
            scanf("%d", &value);
            push(value);
        } else if (op == 2) {   // pop
            pop();
        } else if (op == 3) {   // display
            display();
        }
    }

    return 0;
}
