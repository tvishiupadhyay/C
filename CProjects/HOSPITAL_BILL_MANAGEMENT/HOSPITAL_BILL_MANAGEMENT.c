#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct patient {
    int id;
    char name[50];
    int age;
    char gender[10];
    char admission_date[15];
    char discharge_date[15];
    char contact[15];
    char address[100];
    char room_type[20];
};

struct treatment {
    float room_fee;
    float doc_fee;
    float lab_fee;
    float med_fee;
    float surgery_fee;
    float misc;
};

struct bill {
    int patient_id;
    int days_admitted;
    float total;
    float tax;
    float discount;
    float grand_total;
};

void add_patient();
void update_patient();
void delete_patient();
void generate_bill();

int main() {
    int choice;

    while (1) {
        printf("\nWELCOME TO SERENOVA CARE & HEALING INSTITUTE");
        printf("\nWhat would you like to do today?\n");
        printf("1. Add patient record\n");
        printf("2. Update patient info\n");
        printf("3. Delete patient record\n");
        printf("4. Generate patient bill\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: add_patient(); break;
            case 2: update_patient(); break;
            case 3: delete_patient(); break;
            case 4: generate_bill(); break;
            case 5:
                printf("Thank you for using the system. Always Happy to help :)\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void add_patient() {
    FILE *fp = fopen("patients.txt", "ab");
    struct patient p;

    printf("\nEnter patient ID(7-digit): ");
    scanf("%d", &p.id);
    printf("Enter name: ");
    scanf(" %[^\n]", p.name);
    printf("Enter age: ");
    scanf("%d", &p.age);
    printf("Enter gender(MALE/FEMALE/OTHER): ");
    scanf("%s", p.gender);
    printf("Enter admission date (DD-MM-YYYY): ");
    scanf("%s", p.admission_date);
    printf("Enter discharge date (DD-MM-YYYY): ");
    scanf("%s", p.discharge_date);
    printf("Enter contact number(+91-1234567890): ");
    scanf("%s", p.contact);
    printf("Enter address: ");
    scanf(" %[^\n]", p.address);
    printf("Enter room type (ICU/Private/General): ");
    scanf("%s", p.room_type);

    fwrite(&p, sizeof(p), 1, fp);
    fclose(fp);

    printf("✅ Patient record added successfully.\n");
}

void update_patient() {
    FILE *fp = fopen("patients.txt", "rb+");
    struct patient p;
    int id, found = 0;

    printf("\nEnter patient ID to update: ");
    scanf("%d", &id);

    while (fread(&p, sizeof(p), 1, fp)) {
        if (p.id == id) {
            found = 1;
            fseek(fp, -sizeof(p), SEEK_CUR);

            printf("Enter updated name: ");
            scanf(" %[^\n]", p.name);
            printf("Enter updated age: ");
            scanf("%d", &p.age);
            printf("Enter updated contact number: ");
            scanf("%s", p.contact);
            printf("Enter updated address: ");
            scanf(" %[^\n]", p.address);

            fwrite(&p, sizeof(p), 1, fp);
            printf("🔁 Patient record updated.\n");
            break;
        }
    }

    fclose(fp);

    if (!found)
        printf("⚠️ Patient ID not found.\n");
}

void delete_patient() {
    FILE *fp = fopen("patients.txt", "rb");
    FILE *temp = fopen("temp.txt", "wb");
    struct patient p;
    int id, found = 0;

    printf("\nEnter patient ID to delete: ");
    scanf("%d", &id);

    while (fread(&p, sizeof(p), 1, fp)) {
        if (p.id == id) {
            found = 1;
            continue;
        }
        fwrite(&p, sizeof(p), 1, temp);
    }

    fclose(fp);
    fclose(temp);
    remove("patients.txt");
    rename("temp.txt", "patients.txt");

    if (found)
        printf("🗑️ Patient record deleted successfully.\n");
    else
        printf("⚠️ Patient ID not found.\n");
}

void generate_bill() {
    int id, days;
    struct treatment t;
    struct bill b;
    struct patient p;
    FILE *fp = fopen("patients.txt", "rb");
    int found = 0;

    printf("\nEnter patient ID to generate bill: ");
    scanf("%d", &id);

    while (fread(&p, sizeof(p), 1, fp)) {
        if (p.id == id) {
            found = 1;
            break;
        }
    }

    fclose(fp);
    if (!found) {
        printf("⚠️ Patient not found.\n");
        return;
    }

    printf("\nEnter days admitted: ");
    scanf("%d", &days);
    printf("Room fee per day: ");
    scanf("%f", &t.room_fee);
    printf("Doctor's fee: ");
    scanf("%f", &t.doc_fee);
    printf("Lab fee: ");
    scanf("%f", &t.lab_fee);
    printf("Medication cost: ");
    scanf("%f", &t.med_fee);
    printf("Surgery fee (if any, else 0): ");
    scanf("%f", &t.surgery_fee);
    printf("Miscellaneous charges: ");
    scanf("%f", &t.misc);

    float total = (days * t.room_fee) + t.doc_fee + t.lab_fee + t.med_fee + t.surgery_fee + t.misc;
    b.total = total;
    b.tax = total * 0.18;
    b.discount = total * 0.05;
    b.grand_total = total + b.tax - b.discount;

    printf("\n--- 🧾 BILL SUMMARY ---\n");
    printf("Patient Name     : %s\n", p.name);
    printf("Room Type        : %s\n", p.room_type);
    printf("Total Charges    : Rs.%.2f\n", b.total);
    printf("Tax (18%%)        : Rs.%.2f\n", b.tax);
    printf("Discount (5%%)    : Rs.%.2f\n", b.discount);
    printf("Grand Total      : Rs.%.2f\n", b.grand_total);
}