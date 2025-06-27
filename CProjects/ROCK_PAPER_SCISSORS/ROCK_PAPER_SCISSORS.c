#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int getComputerChoice();
int getUserChoice();
void checkWinner (int userChoice, int computerChoice);

int main ()
{
    srand(time(NULL));
    
    printf("ROCK PAPER SCISSORS\n");
    
    int userChoice = getUserChoice() ;
    int computerChoice = getComputerChoice();

    switch (userChoice)
    {
    case 1:
        printf("You chose ROCK\n");
        break;
    
    case 2:
        printf("You chose PAPER\n");
        break;
    
    case 3:
        printf("You chose SCISSORS\n");
        break;
    
    default:
        break;
    }

    switch (computerChoice)
    {
    case 1:
        printf("Computer chose ROCK\n");
        break;
    
    case 2:
        printf("Computer chose PAPER\n");
        break;
    
    case 3:
        printf("Computer chose SCISSORS\n");
        break;
    
    default:
        break;
    }

    checkWinner(userChoice, computerChoice);

    return 0; 
}

int getComputerChoice()
{
   
    return (rand() % 3)+1 ; 
}

int getUserChoice()
{
    int choice = 0;

    do{
        printf("Choose an Option\n");
        printf("1. ROCK\n");
        printf("1. PAPER\n");
        printf("1. SCISSORS\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
    }while(choice <1 || choice >3);
    return choice; 
}

void checkWinner (int userChoice, int computerChoice)
{
    if(userChoice == computerChoice){
        printf("Its a TIE");
    }
    else if(userChoice ==1 && computerChoice == 3 ){
        printf("You WIN"); 
    }
    else if(userChoice ==2 && computerChoice == 1 ){
        printf("You WIN"); 
    }
    else if(userChoice ==3 && computerChoice == 2 ){
        printf("You WIN"); 
    }
    else {
        printf("You LOSE");
    }

}