#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int x = 12;
    printf("minutes: \n");
    int y = GetInt();
    printf("bottles: %i\n", x * y);
}