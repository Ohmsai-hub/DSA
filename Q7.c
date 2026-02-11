#include <stdio.h>

// Recursive function to compute Fibonacci
int fib(int n) {
    if (n == 0) return 0;   // Base case
    if (n == 1) return 1;   // Base case
    return fib(n - 1) + fib(n - 2);  // Recursive step
}

int main() {
    int n;
    scanf("%d", &n);

    printf("%d\n", fib(n));

    return 0;
}
