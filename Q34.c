#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Node structure for stack
struct Node {
    int data;
    struct Node* next;
};

// Push operation
void push(struct Node** top, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation error\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
}

// Pop operation
int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack underflow\n");
        exit(1);
    }
    struct Node* temp = *top;
    int value = temp->data;
    *top = temp->next;
    free(temp);
    return value;
}

// Evaluate postfix expression
int evaluatePostfix(char* exp) {
    struct Node* stack = NULL;

    for (int i = 0; exp[i] != '\0'; i++) {
        char c = exp[i];

        // If operand (digit), push to stack
        if (isdigit(c)) {
            push(&stack, c - '0');  // convert char to int
        }
        // If operator, pop two operands and apply
        else {
            int val2 = pop(&stack);
            int val1 = pop(&stack);

            switch (c) {
                case '+': push(&stack, val1 + val2); break;
                case '-': push(&stack, val1 - val2); break;
                case '*': push(&stack, val1 * val2); break;
                case '/': push(&stack, val1 / val2); break;
                default: printf("Invalid operator\n"); exit(1);
            }
        }
    }

    return pop(&stack);  // final result
}

int main() {
    char exp[100];
    scanf("%s", exp);

    int result = evaluatePostfix(exp);
    printf("%d\n", result);

    return 0;
}
