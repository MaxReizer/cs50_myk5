#include <cs50.h>
#include <stdio.h>

int main(void)
{   
    int minutes;
    do
    {
        printf("minutes: ");
        minutes = GetInt();
    }
    while (minutes < 1);
    
    if (minutes > 0)
    {
        int bottles = ( 128 * (1.5 * minutes) ) / 16;
        printf("bottles: %d\n", bottles);
    }
    else
    {
        printf("Number must be more than zero!\n");
    }
}