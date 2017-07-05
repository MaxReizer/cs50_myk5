#include <stdio.h>
#include <cs50.h>
#include <math.h>
 
int main (void)
{
    float total;
     
    do
    {
    printf("Need change? ");
    total = GetFloat(); 
    }
    while (total < 0);
       
    float d = round(total * 100);
    int i = d;
    // printf("%d", i);
    int quarters = i / 25;
    int dimes = (i % 25) / 10;
    int nickels = ((i % 25) % 10) / 5;
    int pennies = (((i % 25) % 10) % 5);
    int change = quarters + dimes + nickels + pennies;
     
     
    printf("%d\n", change);
     
}