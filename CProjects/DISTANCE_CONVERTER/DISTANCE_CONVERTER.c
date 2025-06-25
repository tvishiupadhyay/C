#include <stdio.h>

int main() {
    int choice;
    float input, result;

    printf("---- Distance Converter ----\n");
    printf("Select conversion:\n");
    printf("1. Millimeters to Centimeters\n");
    printf("2. Centimeters to Millimeters\n");
    printf("3. Centimeters to Meters\n");
    printf("4. Meters to Centimeters\n");
    printf("5. Meters to Kilometers\n");
    printf("6. Kilometers to Meters\n");

    printf("Enter your choice (1-6): ");
    scanf("%d", &choice);

    printf("Enter the distance value: ");
    scanf("%f", &input);

    switch (choice) {
        case 1:
            result = input / 10;
            printf("Result: %.2f cm\n", result);
            break;
        case 2:
            result = input * 10;
            printf("Result: %.2f mm\n", result);
            break;
        case 3:
            result = input / 100;
            printf("Result: %.2f m\n", result);
            break;
        case 4:
            result = input * 100;
            printf("Result: %.2f cm\n", result);
            break;
        case 5:
            result = input / 1000;
            printf("Result: %.2f km\n", result);
            break;
        case 6:
            result = input * 1000;
            printf("Result: %.2f m\n", result);
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}