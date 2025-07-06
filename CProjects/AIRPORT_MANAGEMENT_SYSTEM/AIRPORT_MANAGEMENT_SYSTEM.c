#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ADMIN_PASS "flyadmin"

struct Flight {
    int flightID;
    char airline[50];
    char source[50];
    char destination[50];
    char departure[10];
    char arrival[10];
    char status[20]; // On-time, Delayed, Cancelled
};

struct Passenger {
    int bookingID;
    int flightID;
    char name[50];
    char passport[20];
    int age;
    char seat[5];
    int checkedIn; // 1 = Yes, 0 = No
};

void addFlight();
void updateFlight();
void cancelFlight();
void viewFlights();
void registerPassenger();
void checkInPassenger();
void viewPassengers();
int flightExists(int flightID);
void pressEnter();

// Waits for user to press Enter before continuing
void pressEnter() {
    printf("\nPress Enter to continue...");
    getchar(); // consumes leftover newline
    getchar(); // waits for Enter
}

int main() {
    int choice;

    while (1) {
        printf("\nAIRPORT MANAGEMENT SYSTEM\n");
        printf("1. Add Flight (Admin)\n");
        printf("2. Update Flight Info (Admin)\n");
        printf("3. Cancel Flight (Admin)\n");
        printf("4. View Flights\n");
        printf("5. Register Passenger\n");
        printf("6. Check-in Passenger\n");
        printf("7. View Passengers for Flight\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addFlight(); break;
            case 2: updateFlight(); break;
            case 3: cancelFlight(); break;
            case 4: viewFlights(); break;
            case 5: registerPassenger(); break;
            case 6: checkInPassenger(); break;
            case 7: viewPassengers(); break;
            case 8:
                printf("Thank you for using Airport Management System!\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
                break; 
        }

        pressEnter();
    }
    return 0;
}

//Add a Flight (Admin Only)
void addFlight() {
    char password[20];
    printf("Enter admin password: ");
    scanf("%s", password);

    if (strcmp(password, ADMIN_PASS) != 0) {
        printf("Access denied.\n");
        return;
    }

    FILE *fp = fopen("flights.dat", "ab");
    struct Flight f;

    printf("Enter Flight ID: ");
    scanf("%d", &f.flightID);
    printf("Airline Name: ");
    scanf(" %[^\n]", f.airline);
    printf("Source Airport: ");
    scanf(" %[^\n]", f.source);
    printf("Destination Airport: ");
    scanf(" %[^\n]", f.destination);
    printf("Departure Time (HH:MM): ");
    scanf("%s", f.departure);
    printf("Arrival Time (HH:MM): ");
    scanf("%s", f.arrival);
    strcpy(f.status, "On-Time");

    fwrite(&f, sizeof(f), 1, fp);
    fclose(fp);
    printf("Flight added successfully.\n");
}

//Update Flight Status
void updateFlight() {
    char password[20];
    printf("Enter admin password: ");
    scanf("%s", password);

    if (strcmp(password, ADMIN_PASS) != 0) {
        printf("Access denied.\n");
        return;
    }

    FILE *fp = fopen("flights.dat", "rb+");
    struct Flight f;
    int id, found = 0;

    printf("Enter Flight ID to update: ");
    scanf("%d", &id);

    while (fread(&f, sizeof(f), 1, fp)) {
        if (f.flightID == id) {
            found = 1;
            fseek(fp, -sizeof(f), SEEK_CUR);
            printf("Enter new status (On-Time/Delayed/Cancelled): ");
            scanf("%s", f.status);
            fwrite(&f, sizeof(f), 1, fp);
            break;
        }
    }

    fclose(fp);
    if (found)
        printf("Flight status updated.\n");
    else
        printf("Flight ID not found.\n");
}

//Cancel Flight
void cancelFlight() {
    char password[20];
    printf("Enter admin password: ");
    scanf("%s", password);

    if (strcmp(password, ADMIN_PASS) != 0) {
        printf("Access denied.\n");
        return;
    }

    FILE *fp = fopen("flights.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");
    struct Flight f;
    int id, found = 0;

    printf("Enter Flight ID to cancel: ");
    scanf("%d", &id);

    while (fread(&f, sizeof(f), 1, fp)) {
        if (f.flightID == id) {
            found = 1;
            continue;
        }
        fwrite(&f, sizeof(f), 1, temp);
    }

    fclose(fp); fclose(temp);
    remove("flights.dat");
    rename("temp.dat", "flights.dat");

    if (found)
        printf("Flight cancelled successfully.\n");
    else
        printf("Flight not found.\n");
}

//View Flights
void viewFlights() {
    FILE *fp = fopen("flights.dat", "rb");
    struct Flight f;

    printf("\n--- Scheduled Flights ---\n");
    while (fread(&f, sizeof(f), 1, fp)) {
        printf("Flight ID: %d | Airline: %s | Route: %s ➜ %s | Dep: %s | Arr: %s | Status: %s\n",
            f.flightID, f.airline, f.source, f.destination, f.departure, f.arrival, f.status);
    }

    fclose(fp);
}

//Register Passenger
void registerPassenger() {
    int flightID;
    struct Passenger p;
    static int bookingCounter = 1001;

    printf("Enter Flight ID: ");
    scanf("%d", &flightID);

    if (!flightExists(flightID)) {
        printf("Flight does not exist.\n");
        return;
    }

    p.flightID = flightID;
    p.bookingID = bookingCounter++;

    printf("Name: ");
    scanf(" %[^\n]", p.name);
    printf("Passport No.: ");
    scanf("%s", p.passport);
    printf("Age: ");
    scanf("%d", &p.age);
    printf("Seat (e.g., 12A): ");
    scanf("%s", p.seat);
    p.checkedIn = 0;

    FILE *fp = fopen("passengers.dat", "ab");
    fwrite(&p, sizeof(p), 1, fp);
    fclose(fp);

    printf("Booking confirmed! Your Booking ID: %d\n", p.bookingID);
}

//Check-in Passenger
void checkInPassenger() {
    int id, found = 0;
    struct Passenger p;
    FILE *fp = fopen("passengers.dat", "rb+");

    printf("Enter Booking ID to check-in: ");
    scanf("%d", &id);

    while (fread(&p, sizeof(p), 1, fp)) {
        if (p.bookingID == id) {
            found = 1;
            fseek(fp, -sizeof(p), SEEK_CUR);
            p.checkedIn = 1;
            fwrite(&p, sizeof(p), 1, fp);
            break;
        }
    }

    fclose(fp);
    if (found)
        printf("Check-in complete. Have a safe flight!\n");
    else
        printf("Booking ID not found.\n");
}

//View Passengers for a Flight
void viewPassengers() {
    int flightID, found = 0;
    struct Passenger p;
    FILE *fp = fopen("passengers.dat", "rb");

    printf("Enter Flight ID: ");
    scanf("%d", &flightID);

    printf("\n--- Passenger List for Flight %d ---\n", flightID);
    while (fread(&p, sizeof(p), 1, fp)) {
        if (p.flightID == flightID) {
            found = 1;
            printf("BookingID: %d | Name: %s | Seat: %s | Checked-In: %s\n",
                p.bookingID, p.name, p.seat, p.checkedIn ? "Yes" : "No");
        }
    }

    fclose(fp);
    if (!found)
        printf("No passengers found for this flight.\n");
}

// Helper: Check if Flight Exists
int flightExists(int flightID) {
    FILE *fp = fopen("flights.dat", "rb");
    struct Flight f;

    while (fread(&f, sizeof(f), 1, fp)) {
        if (f.flightID == flightID) {
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);
    return 0;
}
