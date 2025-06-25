
#include <stdio.h>

int main() {
    int choice;
    float inputTemp, convertedTemp;

    printf("---- Temperature Converter ----\n");
    printf("Choose conversion:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("4. Kelvin to Celsius\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);

    printf("Enter the temperature: ");
    scanf("%f", &inputTemp);

    switch (choice) {
        case 1:
            convertedTemp = (inputTemp * 9 / 5) + 32;
            printf("Temperature in Fahrenheit: %.2fFare\n", convertedTemp);
            break;
        case 2:
            convertedTemp = (inputTemp - 32) * 5 / 9;
            printf("Temperature in Celsius: %.2fCel\n", convertedTemp);
            break;
        case 3:
            convertedTemp = inputTemp + 273.15;
            printf("Temperature in Kelvin: %.2fKel\n", convertedTemp);
            break;
        case 4:
            convertedTemp = inputTemp - 273.15;
            printf("Temperature in Celsius: %.2fCel\n", convertedTemp);
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}