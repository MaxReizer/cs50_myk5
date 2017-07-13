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

    float d = round(total * 100); //переводим денежную сумму в целую сумму монетами
    int i = d;
    // printf("%d", i);
    int quarters = i / 25; //считаем четвертаки
    int dimes = (i % 25) / 10;  //считаем десятки
    int nickels = ((i % 25) % 10) / 5;  //считаем пятаки
    int pennies = (((i % 25) % 10) % 5);  //считаем пенни
    int change = quarters + dimes + nickels + pennies;  //считаем общее кол-во монет


    printf("%d\n", change); //вывод на экран кол-ва монеты

}
