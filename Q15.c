#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int matrix[m][n];
    int diagonal_sum = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
            if (i == j) {
                diagonal_sum += matrix[i][j];
            }
        }
    }

    printf("%d\n", diagonal_sum);
    return 0;
}
