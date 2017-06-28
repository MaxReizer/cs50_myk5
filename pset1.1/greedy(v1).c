#include <stdio.h>
#include <cs50.h>
#include <math.h>
int main (void)                     //Решение методом вычитания и округления
{
    float d;
    int k = 0;
    do 
    {
        printf("O hai! How much change is owed?\n");
        d = GetFloat();
    }
    while  (d <= 0);
    d = d * 100;
    int c = round(d);
 
    while(c>=25 && c>0)
     {
    c = c-25;
    k++;
    }
   
    while(c>=10 && c>0)
    {
    c= c-10;
    k++;
    }
    
    while(c>=5 && c>0)
    {
    c= c-5;
    k++;
    }
    
    while(c>=1 && c>0)
    {
    c= c-1;
    k++;
    }
    
    printf("%d\n", k);
}
    