#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Dynamically allocate memory
    int* original = (int*)malloc(n * sizeof(int));
    int* reversed = (int*)malloc(n * sizeof(int));

    if (original == NULL || reversed == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &original[i]);
    }

    for (int i = 0; i < n; i++) {
        reversed[i] = original[n - 1 - i];
    }

    printf("Reversed array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", reversed[i]);
    }

    // Free allocated memory
    free(original);
    free(reversed);

    return 0;
}