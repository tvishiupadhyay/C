#include <stdio.h>
#include <math.h>

int main() {
    int numDigits, i, digit, sum = 0;
    long long number;

    printf("Enter how many digits the number should have: ");
    scanf("%d", &numDigits);

    if (numDigits <= 0) {
        printf("Invalid number of digits.\n");
        return 1;
    }

    printf("Enter a %d-digit number: ", numDigits);
    scanf("%lld", &number);

    if ((int)log10(number) + 1 != numDigits) {
        printf("The number you entered does not have %d digits.\n", numDigits);
        return 1;
    }
    
    long long temp = number;
    while (temp != 0) {
        digit = temp % 10;
        sum += digit;
        temp /= 10;
    }

    printf("The sum of the digits of %lld is %d\n", number, sum);

    return 0;
}