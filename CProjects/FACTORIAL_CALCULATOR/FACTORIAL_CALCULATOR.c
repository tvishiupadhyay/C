#include <stdio.h>

int main() {
    int num;
    unsigned long long factorial = 1;

    printf("Enter a positive integer: ");
    scanf("%d", &num);

    // Check for negative input
    if (num < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        for(int i = 1; i <= num; ++i) {
            factorial *= i;
        }
        printf("Factorial of %d = %llu\n", num, factorial);
    }

    return 0;
}