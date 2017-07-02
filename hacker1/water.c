#include <cs50.h>
#include <stdio.h>

int main(void){
    int min;
    do {
    printf ("minutes: ");
    min = GetInt();
    }
    while (min<=0);
    printf ("bottles: %i\n", min*12);
    return 0;
}