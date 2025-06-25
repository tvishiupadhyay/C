#include<stdio.h>
int rect();
int sqr();
int tri();
int ratri();
int eqtri();
int isotri();        
int pllgm();
int rhom();
int trap();
int circ();

int main() {
    int choice;
    printf("Choose a shape: ");
    printf("\n1.RECTANGLE \n2.SQUARE \n3.TRIANGLE \n4.RIGHT-ANGLED TRIANGLE \n5.EQUILATERAL TRIANGLE \n6.ISOSCELES TRIANGLE  \n7.PARALLELOGRAM \n8.RHOMBUS \n9.TRAPEZIUM \n10.CIRCLE");
    printf("\nChoose a shape and enter the corresponding number to it:");
    scanf("%d", &choice);
    switch (choice)
    {
        case 1: rect();
                break;
        case 2: sqr();
                break;
        case 3: tri();
                break;
        case 4: ratri();
                break;
        case 5: eqtri();
                break;
        case 6: isotri();
                break;
        case 7: pllgm();
                break;
        case 8: rhom();
                break;
        case 9: trap();
                break;
        case 10: circ();
                break;
        default: printf("Please enter a valid input");
                break;
            
        

    }
    return 0; 
}

int rect()
    {
        int i,a,p,l,b;
        printf("What do you want to calculate?:");
        printf("\n1. Perimeter of a rectangle \n2. Area of a rectangle");
        printf("\nEnter the number corresponding to your choice: ");
        scanf("%d", &i);
        switch (i)
        {
        case 1:
            printf("\nPlease enter the length of the rectangle: ");
            scanf("%d", &l);
            printf("\nPlease enter the breadth of the rectangle:");
            scanf("%d", &b);
            p=2*(l+b);
            printf("\nThe Perimeter of the rectangle is: %d", p);
            break;
        case 2: 
             printf("\nPlease enter the length of the rectangle: ");
            scanf("%d", &l);
            printf("\nPlease enter the breadth of the rectangle:");
            scanf("%d", &b);
            a=l*b;
            printf("\nThe Area of the rectangle is: %d", a);
            break;
        
        default: printf("Please enter a valid input");
            break;
        }
    return 0; 
    }
int sqr()
{
    int i,a,p,s;
        printf("What do you want to calculate?:");
        printf("\n1. Perimeter of a Square \n2. Area of a Square");
        printf("\nEnter the number corresponding to your choice: ");
        scanf("%d", &i);
        switch (i)
        {
            case 1: 
                printf("\nPlease enter the side of the Square: ");
                scanf("%d", &s);
                p=4*s;
                printf("\nThe Perimeter of the Square is: %d", p);
                break;
            case 2:
                printf("\nPlease enter the side of the Square: ");
                scanf("%d", &s);
                a=s*s;
                printf("\nThe Area of the Square is: %d", a);
                break;
            default: printf("Please enter a valid input");
                    break;

        }
    return 0; 
}
int tri()
{
    int i,a,p,s1,s2,s3,h;
        printf("What do you want to calculate?:");
        printf("\n1. Perimeter of a Triangle \n2. Area of a Triangle");
        printf("\nEnter the number corresponding to your choice: ");
        scanf("%d", &i);
        switch (i)
        {
            case 1: 
                printf("\nEnter the first side of the Triangle: ");
                scanf("%d", &s1);
                printf("\nEnter the second side of the Triangle: ");
                scanf("%d", &s2);
                printf("\nEnter the third side of the Triangle: ");
                scanf("%d", &s3);
                p = s1+s2+s3; 
                printf("\nThe Perimeter of the Triangle is: %d", p);
                break; 
            case 2:
                printf("\nEnter the base of the Triangle: ");
                scanf("%d", &s3);
                printf("\nEnter the height of the Triangle:" );
                scanf("%d",&h);
                a= 0.5*s3*h;
                printf("\nThe Area of the Triangle is: %d", a);
                break;
        }
    return 0; 
}
int ratri()
{
    int i,a,p,P,B,H;
        printf("What do you want to calculate?:");
        printf("\n1. Perimeter of a Right - Angled Triangle \n2. Area of a Right - Angled Triangle");
        printf("\nEnter the number corresponding to your choice: ");
        scanf("%d", &i);
        switch (i)
        {
            case 1: 
                printf("\nEnter the perpendicular of the Right - Angled Triangle: ");
                scanf("%d", &P);
                printf("\nEnter the base of the Right - Angled Triangle: ");
                scanf("%d", &B);
                printf("\nEnter the height of the Right - Angled Triangle: ");
                scanf("%d", &H);
                p = P+B+H; 
                printf("\n The Perimeter of the Right - Angled Triangle is: %d", p);
                break; 
            case 2:
                printf("\nEnter the base of the Right - Angled Triangle: ");
                scanf("%d", &B);
                printf("\nEnter the height of the Right - Angled Triangle:" );
                scanf("%d",&H);
                a= 0.5*B*H;
                printf("\nThe Area of the Right - Angled Triangle is: %d", a);
                break;
        }
 
    return 0; 
}
int eqtri()
{
    int i,a,p,s,h;
        printf("What do you want to calculate?:");
        printf("\n1. Perimeter of an Equilateral Triangle \n2. Area of an Equilateral Triangle");
        printf("\nEnter the number corresponding to your choice: ");
        scanf("%d", &i);
        switch (i)
        {
            case 1: 
                printf("\nEnter the side of the Equilateral Triangle: ");
                scanf("%d", &s);
                p = 3*s; 
                printf("\nThe Perimeter of the Equilateral Triangle is: %d", p);
                break; 
            case 2:
                printf("\nEnter the base of the Equilateral Triangle: ");
                scanf("%d", &s);
                printf("\nEnter the height of the Equilateral Triangle:" );
                scanf("%d",&h);
                a= 0.5*s*h;
                printf("\nThe Area of the Equilateral Triangle is: %d", a);
                break;
        }
    return 0; 
}
int isotri()        
{
    int i,a,p,s,h;
        printf("What do you want to calculate?:");
        printf("\n1. Perimeter of an Isosceles Triangle \n2. Area of an Isosceles Triangle");
        printf("\nEnter the number corresponding to your choice: ");
        scanf("%d", &i);
        switch (i)
        {
            case 1: 
                printf("\nEnter the identical side of the Isosceles Triangle: ");
                scanf("%d", &s);
                printf("\nEnter the hypotenuse of the Isosceles Triangle:" );
                scanf("%d",&h);
                p = (2*s)+ h; 
                printf("\nThe Perimeter of the Isosceles Triangle is: %d", p);
                break; 
            case 2:
                printf("\nEnter the identical side of the Isosceles Triangle: ");
                scanf("%d", &s);
                printf("\nEnter the hypotenuse of the Isosceles Triangle:" );
                scanf("%d",&h);
                a= 0.5*s*s;
                printf("\nThe Area of the Isosceles Triangle is: %d", a);
                break;
        }
    return 0; 
}
int pllgm()
{
     int i,a,p,s1,s2,h;
        printf("What do you want to calculate?:");
        printf("\n1. Perimeter of a Parallelogram \n2. Area of a Parallelogram");
        printf("\nEnter the number corresponding to your choice: ");
        scanf("%d", &i);
        switch (i)
        {
        case 1:
            printf("\nPlease enter the first side of the Parallelogram: ");
            scanf("%d", &s1);
            printf("\nPlease enter the second side of the Parallelogram:");
            scanf("%d", &s2);
            p=2*(s1+s2);
            printf("\nThe Perimeter of the Parallelogram is: %d", p);
            break;
        case 2: 
            printf("\nPlease enter the first side of the Parallelogram: ");
            scanf("%d", &s1);
            printf("\nPlease enter the height of the Parallelogram:");
            scanf("%d", &h);
            a=s1*h;
            printf("\nThe Area of the Parallelogram is: %d", a);
            break;
        
        default: printf("Please enter a valid input");
            break;
        }
    return 0; 
}
int rhom()
{
    int i,a,p,s,d1,d2;
        printf("What do you want to calculate?:");
        printf("\n1. Perimeter of a Rhombus \n2. Area of a Rhombus");
        printf("\nEnter the number corresponding to your choice: ");
        scanf("%d", &i);
        switch (i)
        {
            case 1: 
                printf("\nPLease enter the side of the Rhombus: ");
                scanf("%d", &s);
                p=4*s;
                printf("\nThe Perimeter of the Rhombus is: %d", p);
                break;
            case 2:
                printf("\nPLease enter the first diagonal of the Rhombus: ");
                scanf("%d", &d1);
                printf("\nPLease enter the second diagonal of the Rhombus: ");
                scanf("%d", &d2);
                a=0.5*d1*d2;
                printf("\nThe Area of the Rhombus is: %d", a);
                break;
            default: printf("Please enter a valid input");
                    break;

        }
    return 0; 
}
int trap()
{
    int i,a,p,s,s1,s2,h;
        printf("What do you want to calculate?:");
        printf("\n1. Perimeter of a Trapezium \n2. Area of a Trapezium");
        printf("\nEnter the number corresponding to your choice: ");
        scanf("%d", &i);
        switch (i)
        {
            case 1: 
                printf("\nPLease enter the shorter side of the Trapezium: ");
                scanf("%d", &s1);
                printf("\nPLease enter the longer side of the Trapezium: ");
                scanf("%d", &s2);
                printf("\nPLease enter the identical side of the Trapezium: ");
                scanf("%d", &s);
                p=s+s+s1+s2;
                printf("\nThe Perimeter of the Trapezium is: %d", p);
                break;
            case 2:
                printf("\nPLease enter the shorter side of the Trapezium: ");
                scanf("%d", &s1);
                printf("\nPLease enter the longer side of the Trapezium: ");
                scanf("%d", &s2);
                printf("\nPlease enter the height of the Trapezium: ");
                scanf("%d", &h);
                a= 0.5*h*(s1+s2);
                printf("\nThe Area of the Trapezium is: %d", a);
                break;
            default: printf("Please enter a valid input");
                    break;

        }
    return 0; 
}
int circ()
{
    int i;
    float a,p,r;
        printf("What do you want to calculate?:");
        printf("\n1. Perimeter of a Circle \n2. Area of a Circle");
        printf("\nEnter the number corresponding to your choice: ");
        scanf("%d", &i);
        switch (i)
        {
            case 1: 
                printf("\nPLease enter the radius of the Circle: ");
                scanf("%f", &r);
                p=2*3.14*r;
                printf("\nThe Perimeter of the Circle is: %f", p);
                break;
            case 2:
               printf("\nPLease enter the radius of the Circle: ");
                scanf("%f", &r);
                a=3.14*r*r;
                printf("\nThe Area of the Circle is: %f", a);
                break;
            default: printf("Please enter a valid input");
                    break;

        }
    return 0; 
}