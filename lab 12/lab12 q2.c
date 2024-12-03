#include <stdio.h>
#include <stdlib.h>

void matrixMultiplication(int **a, int **b, int **result, int m, int n, int p) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            result[i][j] = 0;
            for (int k = 0; k < n; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    int m, n, p;
    printf("Enter dimensions m, n, p (m x n and n x p): ");
    scanf("%d %d %d", &m, &n, &p);

    int **a = (int **)malloc(m * sizeof(int *));
    int **b = (int **)malloc(n * sizeof(int *));
    int **result = (int **)malloc(m * sizeof(int *));

    for (int i = 0; i < m; i++) a[i] = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) b[i] = (int *)malloc(p * sizeof(int));
    for (int i = 0; i < m; i++) result[i] = (int *)malloc(p * sizeof(int));

    printf("Enter elements of matrix A (%d x %d):\n", m, n);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    printf("Enter elements of matrix B (%d x %d):\n", n, p);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < p; j++)
            scanf("%d", &b[i][j]);

    matrixMultiplication(a, b, result, m, n, p);

    printf("Resultant matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < m; i++) free(a[i]);
    for (int i = 0; i < n; i++) free(b[i]);
    for (int i = 0; i < m; i++) free(result[i]);
    free(a);
    free(b);
    free(result);

    return 0;
}
