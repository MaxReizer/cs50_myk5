#include <cs50.h>  //объявление основных функций
#include <stdio.h>

int main(void) //основная функция
{   
    int minutes;
    do
    {
        printf("minutes: ");  //цикл проверки условия
        minutes = GetInt();
    }
    while (minutes < 1);
    
    if (minutes > 0)
    {
        int bottles = ( 128 * (1.5 * minutes) ) / 16;  //подсет кол-ва бутылок по формуле из условия
        printf("bottles: %d\n", bottles);
    }
    else
    {
        printf("Number must be more than zero!\n");  //вывод текста с ошибкой 
    }
}