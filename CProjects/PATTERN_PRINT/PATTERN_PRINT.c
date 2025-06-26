#include <stdio.h>
#include <string.h>
#include <ctype.h>

void printRectangle(int rows, int cols, char ch) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c ", ch);
        }
        printf("\n");
    }
}

void printTriangular(int rows, char ch) {
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%c ", ch);
        }
        printf("\n");
    }
}

int main() {
    int rows, cols;
    char inputType[20], ch;
    char patternType[20];

    printf("Do you want to print a special character, alphabet, or digit? ");
    scanf("%s", inputType);

    if (strcmp(inputType, "special") == 0 || strcmp(inputType, "digit") == 0 || strcmp(inputType, "alphabet") == 0) {
        printf("Enter the character you want to print: ");
        scanf(" %c", &ch);

        // Validate based on type
        if (strcmp(inputType, "digit") == 0 && !isdigit(ch)) {
            printf("Error: You said digit, but entered something else.\n");
            return 1;
        } else if (strcmp(inputType, "alphabet") == 0 && !isalpha(ch)) {
            printf("Error: You said alphabet, but entered something else.\n");
            return 1;
        } else if (strcmp(inputType, "special") == 0 && (isdigit(ch) || isalpha(ch))) {
            printf("Error: You said special character, but entered a digit or alphabet.\n");
            return 1;
        }
    } else {
        printf("Invalid input type. Please enter either 'special', 'digit', or 'alphabet'.\n");
        return 1;
    }

    printf("Enter number of rows: ");
    scanf("%d", &rows);

    printf("Enter number of columns: ");
    scanf("%d", &cols);

    printf("Choose pattern type (rectangle / triangular): ");
    scanf("%s", patternType);

    printf("\n--- Output Pattern ---\n");

    if (strcmp(patternType, "rectangle") == 0) {
        printRectangle(rows, cols, ch);
    } else if (strcmp(patternType, "triangular") == 0) {
        printTriangular(rows, ch);
    } else {
        printf("Invalid pattern type.\n");
    }

    return 0;
}