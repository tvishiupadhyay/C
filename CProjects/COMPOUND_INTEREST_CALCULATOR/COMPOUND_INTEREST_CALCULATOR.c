#include <stdio.h>
#include <math.h>

int main() 
{
    double principal, rate, time, compound, amount;

    printf("Enter the principal amount: ");
    scanf("%lf", &principal);
    printf("Enter annual interest rate (in percentage): ");
    scanf("%lf", &rate);
    printf("Enter time (in years): ");
    scanf("%lf", &time);
    printf("Enter number of times interest is compounded per year: ");
    scanf("%lf", &compound);

    amount = principal * pow((1 + (rate / (compound * 100))), compound * time);

    printf("Compound Interest: %.2lf\n", amount - principal);
    printf("Total Amount after %.2lf years: %.2lf\n", time, amount);

    return 0;
}