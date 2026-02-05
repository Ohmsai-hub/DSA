#include <stdio.h>

int main() {
    int p, q;
    scanf("%d", &p);
    int arr1[p];
    for (int i = 0; i < p; i++) {
        scanf("%d", &arr1[i]);
    }

    scanf("%d", &q);
    int arr2[q];
    for (int i = 0; i < q; i++) {
        scanf("%d", &arr2[i]);
    }

    int merged[p + q];
    int i = 0, j = 0, k = 0;

    // Merge two sorted arrays
    while (i < p && j < q) {
        if (arr1[i] <= arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }

    // Copy remaining elements
    while (i < p) {
        merged[k++] = arr1[i++];
    }
    while (j < q) {
        merged[k++] = arr2[j++];
    }

    // Print merged array
    for (int x = 0; x < p + q; x++) {
        printf("%d ", merged[x]);
    }

    return 0;
}
