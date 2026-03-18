#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int min_sum = __INT_MAX__;  // Initialize with a very large value
    int pair1 = 0, pair2 = 0;

    // Check all pairs
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int sum = arr[i] + arr[j];
            if (abs(sum) < abs(min_sum)) {
                min_sum = sum;
                pair1 = arr[i];
                pair2 = arr[j];
            }
        }
    }

    printf("%d %d\n", pair1, pair2);
    return 0;
}
