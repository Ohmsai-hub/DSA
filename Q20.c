#include <stdio.h>
#include <stdlib.h>

// Comparator for qsort
int cmp(const void *a, const void *b) {
    long long x = *(long long*)a;
    long long y = *(long long*)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    long long prefix[n+1];
    prefix[0] = 0;

    // Build prefix sums
    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i-1] + arr[i-1];
    }

    // Sort prefix sums
    qsort(prefix, n+1, sizeof(long long), cmp);

    long long count = 0;
    long long freq = 1;

    // Count frequencies of equal prefix sums
    for (int i = 1; i <= n; i++) {
        if (prefix[i] == prefix[i-1]) {
            freq++;
        } else {
            count += (freq * (freq - 1)) / 2;
            freq = 1;
        }
    }
    count += (freq * (freq - 1)) / 2;

    printf("%lld\n", count);
    return 0;
}
}
