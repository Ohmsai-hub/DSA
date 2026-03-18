#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct Node {
    int coeff;   // coefficient
    int exp;     // exponent
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// Insert node at the end
struct Node* insertEnd(struct Node* head, int coeff, int exp) {
    struct Node* newNode = createNode(coeff, exp);

    if (head == NULL) {
        return newNode;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Function to print polynomial
void printPolynomial(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->coeff);
        if (temp->exp > 0) {
            printf("x");
            if (temp->exp > 1) {
                printf("^%d", temp->exp);
            }
        }
        if (temp->next != NULL) {
            printf(" + ");
        }
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    struct Node* head = NULL;

    for (int i = 0; i < n; i++) {
        int coeff, exp;
        scanf("%d %d", &coeff, &exp);
        head = insertEnd(head, coeff, exp);
    }

    // Print polynomial
    printPolynomial(head);

    return 0;
}
