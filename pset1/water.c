#include <cs50.h> //объявление основных функций
#include <stdio.h>

int main(void)  //основная функция
{
    printf("minutes: "); //вывод текста на экран
    int minutes = GetInt(); //ввод кол-ва минут

    if (minutes > 0) //условие кол-ва минут
    {
        int bottles = ( 128 * (1.5 * minutes) ) / 16; //формула подсчета минут
        printf("bottles: %d\n", bottles); //вывод кол-ва бутылок по формуле
    }
    else
    {
        printf("Number must be more than zero!\n"); //вывод ошибки неправильного ввода кол-ва минут
    }
}
