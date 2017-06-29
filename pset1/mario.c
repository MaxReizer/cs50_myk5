#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    do
    {
        printf("height: ");
        height = GetInt();
    }
while (height <= 0 || height > 23);

    int i, j, k;
    for(i = 0; i < height; i ++)
    {
        for(j = height - 1; j > i; j --)
        {
            printf(" ");
        }
        
        printf("#");
        for(k = 0; k < i; k ++)
        {
            printf("#");
        }
        printf("#");
        printf("\n");
    }
}