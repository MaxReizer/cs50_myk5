#include <stdio.h>
#include <cs50.h>
int main (void)
{
    int v, p, h;
    
    do 
    {
        printf("Height:");
        v = GetInt();
    }
    while  (v < 0 || v > 23);
    
    p = v-2;
    h = 2;
    for (int x = v; x > 0; x--)
    {
        for (int y = p; y >= 0; y--)
        {
        printf(" ");
        }
        for (int z = h; z > 0; z--)
        {
            printf("#");
        }
        printf("\n");
        p--;
        h++;
        
    }
}