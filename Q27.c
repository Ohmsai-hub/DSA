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

// Function to find intersection point
struct Node* getIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    // Advance longer list by diff
    if (len1 > len2) {
        for (int i = 0; i < diff; i++) head1 = head1->next;
    } else {
        for (int i = 0; i < diff; i++) head2 = head2->next;
    }

    // Traverse both lists together
    while (head1 != NULL && head2 != NULL) {
        if (head1 == head2) return head1; // Intersection found
        head1 = head1->next;
        head2 = head2->next;
    }
    return NULL; // No intersection
}

int main() {
    int n, m;
    scanf("%d", &n);

    struct Node* head1 = NULL;
    struct Node* tail1 = NULL;

    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        struct Node* newNode = createNode(val);

        if (head1 == NULL) {
            head1 = newNode;
            tail1 = newNode;
        } else {
            tail1->next = newNode;
            tail1 = newNode;
        }
    }

    scanf("%d", &m);

    struct Node* head2 = NULL;
    struct Node* tail2 = NULL;

    for (int i = 0; i < m; i++) {
        int val;
        scanf("%d", &val);
        struct Node* newNode = createNode(val);

        if (head2 == NULL) {
            head2 = newNode;
            tail2 = newNode;
        } else {
            tail2->next = newNode;
            tail2 = newNode;
        }
    }

    

    struct Node* intersectNode = getIntersection(head1, head2);

    if (intersectNode != NULL) {
        printf("%d\n", intersectNode->data);
    } else {
        printf("No Intersection\n");
    }

    return 0;
}
