#include <stdio.h>
#include <cs50.h>

int main (void)
{
printf("Pleace, enter length of your shower in minutes\n");
int x = GetInt();
int y = 12;
printf("Bottles: %i\n", x * y);
}
