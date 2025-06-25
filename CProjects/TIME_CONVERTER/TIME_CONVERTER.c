#include <stdio.h>

int main() {
    int choice;
    double value, result;

    printf("\n--- Time Conversion Menu ---\n");
    printf("1. Seconds to Minutes\n");
    printf("2. Minutes to Seconds\n");
    printf("3. Minutes to Hours\n");
    printf("4. Hours to Minutes\n");
    printf("5. Hours to Days\n");
    printf("6. Days to Hours\n");
    printf("7. Days to Months\n");
    printf("8. Months to Days\n");
    printf("9. Months to Years\n");
    printf("10. Years to Months\n");
    printf("Enter your choice (1-10): ");
    scanf("%d", &choice);

    printf("Enter the time value: ");
    scanf("%lf", &value);

    switch (choice) {
        case 1:
            result = value / 60;
            printf("Result: %.2f minutes\n", result);
            break;
        case 2:
            result = value * 60;
            printf("Result: %.2f seconds\n", result);
            break;
        case 3:
            result = value / 60;
            printf("Result: %.2f hours\n", result);
            break;
        case 4:
            result = value * 60;
            printf("Result: %.2f minutes\n", result);
            break;
        case 5:
            result = value / 24;
            printf("Result: %.2f days\n", result);
            break;
        case 6:
            result = value * 24;
            printf("Result: %.2f hours\n", result);
            break;
        case 7:
            result = value / 30.44;
            printf("Result: %.2f months\n", result);
            break;
        case 8:
            result = value * 30.44;
            printf("Result: %.2f days\n", result);
            break;
        case 9:
            result = value / 12;
            printf("Result: %.2f years\n", result);
            break;
        case 10:
            result = value * 12;
            printf("Result: %.2f months\n", result);
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}