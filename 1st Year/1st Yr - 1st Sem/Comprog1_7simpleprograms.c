#include <stdio.h>
#include <stdlib.h>


int main(){

    float pi = 3.1416;
    int r;
    printf("Input the radius: ");
    scanf("%d", &r);
    float volumeResult = 4  * pi * r * r * r / 3;
    printf("The volume of the sphere that has a radius of %d is %f\n", r, volumeResult);


    int c;
    printf("Enter a celcius degree: ");
    scanf("%d", &c);
    float fahrenheit = 9.0 / 5 * c + 32;
    printf("The fahrenheit degree equivalent is %.2f\n", fahrenheit);


    int d;
    printf("Put a dollar: ");
    scanf("%d", &d);
    float peso = d * 51.50;
    printf("That dollars turn into %f peso\n", peso);


    int in;
    printf("Gimme some inches: ");
    scanf("%d", &in);
    float centi = in * 2.54;
    printf("In centimeter, that is %f\n", centi);


    int x,y,temp;
    printf("Input the x varb: ");
    scanf("%d", &x);
    printf("Input the y varb: ");
    scanf("%d", &y);
    temp = x;
    x = y;
    y = temp;
    printf("The x varb now is %d, and the y varb now is %d\n", x ,y);

    int rad;
    printf("Input the radius: ");
    scanf("%d", &rad);
    float cir = 2 * pi * rad;
    printf("The circumference is %f\n", cir);

    int a,b;
    printf("Input the a varb: ");
    scanf("%d", &a);
    printf("Input the b varb: ");
    scanf("%d", &b);

    a = a + b;
    b = a - b;
    a = a - b;

    printf("The a varb now is %d, and the b varb now is %d\n", a, b);

    int P;
    printf("Show the price: ");
    scanf("%d", &P);
    int Y;
    printf("Show the years: ");
    scanf("%d", &Y);
    int S;
    printf("Show the salvage value: ");
    scanf("%d", &S);
    float D = (P-S)/Y;
    printf("The yearly depreciation for that item is %f\n", D);

    return 0;


}
