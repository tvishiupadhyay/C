#include <stdio.h>
#include <ctype.h>

int main() {
    char ch;

    printf("Enter a single character: ");
    scanf(" %c", &ch);  // space to catch any stray newline

    if (isalpha(ch)) {
        // It's an alphabet
        char lowerCh = tolower(ch);  // Normalize case for vowel check
        if (lowerCh == 'a' || lowerCh == 'e' || lowerCh == 'i' || lowerCh == 'o' || lowerCh == 'u') {
            printf("'%c' is a vowel.\n", ch);
        } else {
            printf("'%c' is a consonant.\n", ch);
        }
    } else if (isdigit(ch)) {
        printf("'%c' is a digit.\n", ch);
    } else {
        printf("'%c' is a special character.\n", ch);
    }

    return 0;
}