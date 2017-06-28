#include <stdio.h>
#include <cs50.h>
#include <math.h>
int main (void)                         //Решение методом деления
{
    float d;
    do 
    {
        printf("O hai! How much change is owed?\n");
        d = GetFloat();
    }
    while  (d <= 0);
    d = d * 100;
    int c = round(d);

    int x = 25;
    int y = 10;
    int z = 5;
    int p = 1;
    int k = 0;
    
    k = k + (c/x);
    k = floor(k);                   
    c = c - (k*x);

    int k2 = (c/y);
    k2 = floor(k2); 
    c = c - (k2*y);
    k = k + k2;
    k = floor(k);
  
    int k3 = (c/z);
    k3 = floor(k3); 
    c = c - (k3*z);
    k = k + k3;
    k = floor(k);

    int k4 = (c/p);
    k4 = floor(k4); 
    c = c - (k4*p);
    k = k + k4;
    k = floor(k);
        
    printf("%d\n", k);
}
 

