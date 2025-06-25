#include <stdio.h>

int main() {
    char name[100];
    int roll;
    float marks[5], sum = 0, average;
    char grade[10];

    // Taking input
    printf("Enter student's name: ");
    scanf(" %[^\n]", name);  // Reads full name including spaces

    printf("Enter roll number: ");
    scanf("%d", &roll);

    printf("Enter marks for 5 subjects:\n");
    for (int i = 0; i < 5; i++) {
        printf("Subject %d: ", i + 1);
        scanf("%f", &marks[i]);
        sum += marks[i];
    }

    average = sum / 5.0;

    // Grading logic
    if (average >= 90 && average <= 100)
        sprintf(grade, "A");
    else if (average >= 80 && average < 90)
        sprintf(grade, "B");
    else if (average >= 70 && average < 80)
        sprintf(grade, "C");
    else if (average >= 60 && average < 70)
        sprintf(grade, "D");
    else if (average >= 50 && average < 60)
        sprintf(grade, "E");
    else
        sprintf(grade, "FAIL");

    // Output
    printf("\n--- Report Card ---\n");
    printf("Name       : %s\n", name);
    printf("Roll Number: %d\n", roll);
    printf("Average    : %.2f\n", average);
    printf("Grade      : %s\n", grade);

    return 0;
}