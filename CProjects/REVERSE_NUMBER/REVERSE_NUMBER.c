#include <stdio.h>

int main() {
    long long num, reversed = 0;

    printf("Enter a number: ");
    scanf("%lld", &num);

    while (num != 0) {
        int digit = num % 10;
        reversed = reversed * 10 + digit;
        num = num / 10;
    }

    printf("Reversed number: %lld\n", reversed);

    return 0;
}