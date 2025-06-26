#include <stdio.h>
#include <ctype.h> // for islower, isupper, tolower, toupper

int main() {
    char str[1000];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin); // read string with spaces

    for (int i = 0; str[i] != '\0'; ++i) {
        if (islower(str[i])) {
            str[i] = toupper(str[i]);
        } else if (isupper(str[i])) {
            str[i] = tolower(str[i]);
        }
    }

    printf("Toggled case string: %s\n", str);
    return 0;
}