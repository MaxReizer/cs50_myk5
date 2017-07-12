#include <stdio.h>  //объвление используемых библиотек
#include <cs50.h>
#include <math.h>

int main (void) //объявление основой функции
{
    float total; //объявление переменной общего кол-ва монет типа float

    do //ввод суммы здачи и проверка на условие
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
