#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n;

    printf("Enter the size of the square matrix (n x n): ");
    scanf("%d", &n);

    // Allocate memory dynamically
    int** matrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int*)malloc(n * sizeof(int));
    }

    // Input the matrix
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int trace = 0;
    double norm = 0.0;

    // Compute trace and norm
    for (int i = 0; i < n; i++) {
        trace += matrix[i][i];
        for (int j = 0; j < n; j++) {
            norm += matrix[i][j] * matrix[i][j];
        }
    }
    norm = sqrt(norm);

    // Output results
    printf("Trace of the matrix: %d\n", trace);
    printf("Norm of the matrix: %.2f\n", norm);

    // Free memory
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}