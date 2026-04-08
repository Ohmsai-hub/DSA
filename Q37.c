#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int pq[MAX];
int size = 0;

// Insert operation
void insert(int x) {
    if (size == MAX) {
        printf("Queue overflow\n");
        return;
    }
    pq[size++] = x;
}

// Find index of highest priority (smallest value)
int getHighestPriorityIndex() {
    if (size == 0) return -1;
    int minIndex = 0;
    for (int i = 1; i < size; i++) {
        if (pq[i] < pq[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

// Delete operation
int delete() {
    if (size == 0) return -1;
    int minIndex = getHighestPriorityIndex();
    int val = pq[minIndex];
    // Shift elements left
    for (int i = minIndex; i < size - 1; i++) {
        pq[i] = pq[i + 1];
    }
    size--;
    return val;
}

// Peek operation
int peek() {
    if (size == 0) return -1;
    int minIndex = getHighestPriorityIndex();
    return pq[minIndex];
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        char op[10];
        int x;
        scanf("%s", op);

        if (op[0] == 'i') { // insert
            scanf("%d", &x);
            insert(x);
        } else if (op[0] == 'd') { // delete
            printf("%d\n", delete());
        } else if (op[0] == 'p') { // peek
            printf("%d\n", peek());
        }
    }

    return 0;
}
