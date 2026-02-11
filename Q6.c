#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Print the first element (always unique in sorted array)
    if (n > 0) {
        printf("%d", arr[0]);
    }

    // Traverse and print only unique elements
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1]) {
            printf(" %d", arr[i]);
        }
    }

    return 0;
}
