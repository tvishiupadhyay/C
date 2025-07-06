#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ADMIN_PASS "busadmin"
#define MAX_SEATS 30

struct Bus {
    int busID;
    char source[50];
    char destination[50];
    char departure[10];
    char arrival[10];
    int totalSeats;
    float fare;
};

struct Passenger {
    int bookingID;
    int busID;
    char name[50];
    int age;
    char gender[10];
    int seatNumber;
};

void addBus();
void viewBuses();
void searchBuses();
void bookTicket();
void cancelTicket();
void viewPassengers();
int isSeatTaken(int busID, int seat);

int main() {
    int choice;

    while (1) {
        printf("\n=== BUS RESERVATION SYSTEM ===\n");
        printf("1. Add Bus (Admin)\n");
        printf("2. View All Buses\n");
        printf("3. Search Buses by Route\n");
        printf("4. Book Ticket\n");
        printf("5. Cancel Ticket\n");
        printf("6. View Passengers in a Bus\n");
        printf("7. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: addBus(); break;
            case 2: viewBuses(); break;
            case 3: searchBuses(); break;
            case 4: bookTicket(); break;
            case 5: cancelTicket(); break;
            case 6: viewPassengers(); break;
            case 7: printf("Thank you! Safe travels!\n"); exit(0);
            default: printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

void addBus() {
    char password[20];
    printf("\nEnter admin password to add a bus: ");
    scanf("%s", password);
    if (strcmp(password, ADMIN_PASS) != 0) {
        printf("Access denied.\n");
        return;
    }

    FILE *fp = fopen("buses.dat", "ab");
    struct Bus b;

    printf("Enter Bus ID: ");
    scanf("%d", &b.busID);
    printf("From (Source): ");
    scanf(" %[^\n]", b.source);
    printf("To (Destination): ");
    scanf(" %[^\n]", b.destination);
    printf("Departure Time (e.g., 09:00): ");
    scanf("%s", b.departure);
    printf("Arrival Time (e.g., 15:30): ");
    scanf("%s", b.arrival);
    printf("Total Seats (max %d): ", MAX_SEATS);
    scanf("%d", &b.totalSeats);
    printf("Fare per ticket: Rs");
    scanf("%f", &b.fare);

    fwrite(&b, sizeof(b), 1, fp);
    fclose(fp);

    printf(" Bus added successfully.\n");
}

void viewBuses() {
    FILE *fp = fopen("buses.dat", "rb");
    struct Bus b;

    printf("\n--- Available Buses ---\n");
    while (fread(&b, sizeof(b), 1, fp)) {
        printf("Bus ID: %d | Route: %s → %s | Departs: %s | Arrives: %s | Seats: %d | Fare: Rs.%.2f\n",
               b.busID, b.source, b.destination, b.departure, b.arrival, b.totalSeats, b.fare);
    }

    fclose(fp);
}

void searchBuses() {
    FILE *fp = fopen("buses.dat", "rb");
    struct Bus b;
    char src[50], dest[50];
    int found = 0;

    printf("\nEnter source: ");
    scanf(" %[^\n]", src);
    printf("Enter destination: ");
    scanf(" %[^\n]", dest);

    printf("\n--- Matching Buses ---\n");
    while (fread(&b, sizeof(b), 1, fp)) {
        if (strcasecmp(b.source, src) == 0 && strcasecmp(b.destination, dest) == 0) {
            printf("Bus ID: %d | Departs: %s | Arrives: %s | Fare: Rs.%.2f\n",
                   b.busID, b.departure, b.arrival, b.fare);
            found = 1;
        }
    }

    if (!found)
        printf("No buses found for this route.\n");

    fclose(fp);
}

void bookTicket() {
    FILE *fpBus = fopen("buses.dat", "rb");
    struct Bus b;
    int busID, found = 0;

    printf("\nEnter Bus ID to book: ");
    scanf("%d", &busID);

    while (fread(&b, sizeof(b), 1, fpBus)) {
        if (b.busID == busID) {
            found = 1;
            break;
        }
    }

    fclose(fpBus);

    if (!found) {
        printf("Bus ID not found.\n");
        return;
    }

    int seat;
    do {
        printf("Enter seat number (1–%d): ", b.totalSeats);
        scanf("%d", &seat);
        if (seat < 1 || seat > b.totalSeats || isSeatTaken(busID, seat)) {
            printf("Seat unavailable or invalid. Try again.\n");
        } else {
            break;
        }
    } while (1);

    struct Passenger p;
    static int bookingIDCounter = 1000;
    p.bookingID = bookingIDCounter++;
    p.busID = busID;
    p.seatNumber = seat;

    printf("Enter passenger name: ");
    scanf(" %[^\n]", p.name);
    printf("Enter age: ");
    scanf("%d", &p.age);
    printf("Enter gender: ");
    scanf("%s", p.gender);

    FILE *fp = fopen("passengers.dat", "ab");
    fwrite(&p, sizeof(p), 1, fp);
    fclose(fp);

    printf("\nTicket Booked!\n");
    printf("Booking ID: %d | Bus ID: %d | Seat: %d\n", p.bookingID, p.busID, p.seatNumber);
}

int isSeatTaken(int busID, int seat) {
    FILE *fp = fopen("passengers.dat", "rb");
    struct Passenger p;

    while (fread(&p, sizeof(p), 1, fp)) {
        if (p.busID == busID && p.seatNumber == seat) {
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);
    return 0;
}

void cancelTicket() {
    FILE *fp = fopen("passengers.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");
    struct Passenger p;
    int bookingID, found = 0;

    printf("\nEnter Booking ID to cancel: ");
    scanf("%d", &bookingID);

    while (fread(&p, sizeof(p), 1, fp)) {
        if (p.bookingID == bookingID) {
            found = 1;
            continue;
        }
        fwrite(&p, sizeof(p), 1, temp);
    }

    fclose(fp);
    fclose(temp);
    remove("passengers.dat");
    rename("temp.dat", "passengers.dat");

    if (found)
        printf("Ticket cancelled successfully.\n");
    else
        printf("Booking ID not found.\n");
}

void viewPassengers() {
    FILE *fp = fopen("passengers.dat", "rb");
    struct Passenger p;
    int busID, found = 0;

    printf("\nEnter Bus ID to list passengers: ");
    scanf("%d", &busID);

    printf("\n--- Passenger List for Bus %d ---\n", busID);
    while (fread(&p, sizeof(p), 1, fp)) {
        if (p.busID == busID) {
            printf("Booking ID: %d | Name: %s | Seat: %d | Age: %d | Gender: %s\n",
                   p.bookingID, p.name, p.seatNumber, p.age, p.gender);
            found = 1;
        }
    }

    fclose(fp);
    if (!found)
        printf("No passengers found for this bus.\n");
}