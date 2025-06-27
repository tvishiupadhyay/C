#include <stdio.h>

int main() {
    int num, original, reversed = 0, remainder;

    printf("Enter an integer: ");
    scanf("%d", &num);

    original = num;  // Save original number

    // Reverse the number
    while (num != 0) {
        remainder = num % 10;
        reversed = reversed * 10 + remainder;
        num /= 10;
    }

    // Check if original and reversed are the same
    if (original == reversed) {
        printf("%d is a palindrome.\n", original);
    } else {
        printf("%d is not a palindrome.\n", original);
    }

    return 0;
}