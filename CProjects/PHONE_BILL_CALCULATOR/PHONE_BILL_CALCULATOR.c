#include <stdio.h>

int main() {
    int calls;
    float bill = 0.0;

    printf("Enter the number of calls made: ");
    scanf("%d", &calls);

    if (calls <= 150) {
        bill = 0;
    } else if (calls <= 250) {
        bill = (calls - 150) * 0.90;
    } else if (calls <= 400) {
        bill = (100 * 0.90) + (calls - 250) * 1.20;
    } else {
        bill = (100 * 0.90) + (150 * 1.20) + (calls - 400) * 1.50;
    }

    printf("Total calls: %d\n", calls);
    printf("Total bill amount: Rs.%.2f\n", bill);

    return 0;
}