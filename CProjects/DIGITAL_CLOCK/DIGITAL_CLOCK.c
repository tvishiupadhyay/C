#include <stdio.h>
#include <time.h>

int main() {
    // Get the current system time
    time_t now = time(NULL);
    struct tm *local = localtime(&now);

    // Display the time in HH:MM format
    printf("DIGITAL CLOCK!");
    printf("\nTHE CURRENT TIME IS : %02d:%02d", 
           local->tm_hour, 
           local->tm_min);

    return 0;
}