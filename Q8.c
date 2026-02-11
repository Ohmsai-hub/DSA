#include <stdio.h>

// Recursive function to compute a^b
long long power(int a, int b) {
    if (b == 0) return 1;          // Base case: anything^0 = 1
    return a * power(a, b - 1);    // Recursive step
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    printf("%lld\n", power(a, b));

    return 0;
}
