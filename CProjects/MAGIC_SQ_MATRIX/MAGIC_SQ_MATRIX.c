#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, cols;

    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    if (rows != cols) {
        printf("Not a square matrix. Magic square must be square.\n");
        return 0;
    }

    int n = rows;

    // Dynamically allocate 2D matrix
    int** matrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int*)malloc(n * sizeof(int));
    }

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int magicSum = 0;
    for (int j = 0; j < n; j++) {
        magicSum += matrix[0][j];
    }

    // Check rows
    for (int i = 1; i < n; i++) {
        int rowSum = 0;
        for (int j = 0; j < n; j++) {
            rowSum += matrix[i][j];
        }
        if (rowSum != magicSum) {
            printf("Not a magic square.\n");
            return 0;
        }
    }

    // Check columns
    for (int j = 0; j < n; j++) {
        int colSum = 0;
        for (int i = 0; i < n; i++) {
            colSum += matrix[i][j];
        }
        if (colSum != magicSum) {
            printf("Not a magic square.\n");
            return 0;
        }
    }

    // Check diagonals
    int diag1 = 0, diag2 = 0;
    for (int i = 0; i < n; i++) {
        diag1 += matrix[i][i];
        diag2 += matrix[i][n - 1 - i];
    }

    if (diag1 != magicSum || diag2 != magicSum) {
        printf("Not a magic square.\n");
    } else {
        printf("Yes! It is a magic square.\n");
    }

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}