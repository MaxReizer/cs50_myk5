#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main(void) 
{
    int coinsMeter = 0;
    
    printf("O hai! How much change is owed? \n");
    float change = GetFloat();
    while (change < 0) {
        printf("How much change is owed? \n");
        change = GetFloat();
    }

    int amount =  round(change * 100);
    
    while (amount > 0) {
        if ((amount - 25) >= 0) { amount = amount - 25; coinsMeter++; }
        else if ((amount - 10) >= 0) { amount = amount - 10; coinsMeter++; }
        else if ((amount - 5) >= 0) { amount = amount - 5; coinsMeter++; }
        else if ((amount - 1) >= 0) { amount = amount - 1; coinsMeter++; }
    }
    
    printf("%d\n", coinsMeter);
}