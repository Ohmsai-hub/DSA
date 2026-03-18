#include <stdio.h>

int main() {
    int n, k;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &k);
    k = k % n;  // Normalize k

    // Print rotated array
    for (int i = 0; i < n; i++) {
        int new_index = (i + k) % n;
        printf("%d ", arr[(n - k + i) % n]);
    }
    printf("\n");

    return 0;
}
