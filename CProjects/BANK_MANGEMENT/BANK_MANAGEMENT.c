#include<stdio.h>

void checkBalance(float balance);
float deposit();
float withdraw(float balance);

int main ()
{
    int choice = 0;
    float balance = 0.0f;

    printf("WELCOME TO THE BANK");

    do{
        printf("\nSelect an option:\n");
        printf("\n1. Check Balance \n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("\nEnter your Choice: ");
        scanf("%d", &choice); 


        switch(choice)
            {
                case 1: 
                    checkBalance(balance);
                    break;
                case 2: 
                    balance += deposit();
                    break;
                case 3: 
                    balance -= withdraw(balance);
                    break; 
                case 4: printf("\n Thank you for using the bank!\n");
                        break;
                default: printf("\nplease enter a valid input\n");
                        break;
            }
    }while(choice != 4);

    return 0;
}

void checkBalance(float balance)
{
    printf("\n Your current balance is: Rs. %.2f\n", balance);

}
float deposit()
{
    float amount = 0.0f;
    printf("\n Enter amount to deposit: Rs. ");
    scanf("%f", &amount);

    if(amount<0)
    {
        printf("Invalid amount!");
        return 0.0f;
    }
    else{
        printf("Successfully deposited Rs. %.2f\n", amount);
        return amount;
    }
}
float withdraw(float balance)
{
    float amount =0.0f;
    printf("\nEnter amount to withdraw: Rs. ");
    scanf("%f", &amount);

    if(amount <0)
    {
        printf("\nInvalid amount!\n");
        return 0.0f;
    }
    else if(amount> balance){
        printf("Insufficent funds!\n Your balance is: Rs. %.2f\n", balance);
        return 0.0f;
    }
    else {
        printf("Successfully withdrew Rs.%.2f\n", amount);
        return amount;
    }

}
