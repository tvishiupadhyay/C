#include<stdio.h>
int main(){
  int choice, quantity;
    float total = 0;
    char cont;

    do {
        printf("Hello! What would you like to order? \n");
        printf("1. Pizza- 240.0Rs \n2. Burger- 80.0Rs \n3. French Fries- 90.0Rs \n4. Noodles- 150.0Rs \n5. Cold Drinks- 100.0Rs \n");
        printf("Enter your choice and the corresponding number to it: ");
        scanf("%d", &choice);

        printf("\nEnter quantity: ");
        scanf("%d", &quantity);

        switch(choice) {
            case 1:
                total += 240 * quantity;
                break;
            case 2:
                total += 80 * quantity;
                break;
            case 3:
                total += 90 * quantity;
                break;
            case 4:
                total += 150 * quantity;
                break;
            case 5:
                total += 100 * quantity;
                break;
            default:
                printf("Invalid choice. Please select a number between 1 and 5.\n");
        }

        printf("Do you want to add another item? (y/n): ");
        scanf(" %c", &cont);

    } while(cont == 'y' || cont == 'Y');

    printf("\nYour total bill is: Rs%.2f\n", total);
    printf("Thank you for shopping!\n");

    return 0;
}