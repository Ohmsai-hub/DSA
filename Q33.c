#include <stdio.h>
#include <ctype.h>   // for isalnum
#include <string.h>  // for strlen

#define MAX 100

char stack[MAX];
int top = -1;

// Push to stack
void push(char c) {
    if (top == MAX - 1) return;
    stack[++top] = c;
}

// Pop from stack
char pop() {
    if (top == -1) return -1;
    return stack[top--];
}

// Peek top of stack
char peek() {
    if (top == -1) return -1;
    return stack[top];
}

// Operator precedence
int precedence(char op) {
    switch (op) {
        case '^': return 3;
        case '*': case '/': return 2;
        case '+': case '-': return 1;
        default: return 0;
    }
}

// Convert infix to postfix
void infixToPostfix(char* infix) {
    char postfix[MAX];
    int k = 0;

    for (int i = 0; i < strlen(infix); i++) {
        char c = infix[i];

        // If operand, add to output
        if (isalnum(c)) {
            postfix[k++] = c;
        }
        // If '(', push
        else if (c == '(') {
            push(c);
        }
        // If ')', pop until '('
        else if (c == ')') {
            while (top != -1 && peek() != '(') {
                postfix[k++] = pop();
            }
            pop(); // remove '('
        }
        // If operator
        else {
            while (top != -1 && precedence(peek()) >= precedence(c)) {
                postfix[k++] = pop();
            }
            push(c);
        }
    }

    // Pop remaining operators
    while (top != -1) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';
    printf("%s\n", postfix);
}

int main() {
    char infix[MAX];
    scanf("%s", infix);
    infixToPostfix(infix);
    return 0;
}
