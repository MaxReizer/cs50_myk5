#include <cs50.h> //подключение используемых библиотек
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void printInitials(string name); //объявление функции

int main(void) //объявление основной функции
{
    string name = GetString();
    printInitials(name);
}

void printInitials(string name)
{
    printf("%c", toupper(name[0]));
    
    for(int i = 0, c = strlen(name); i < c; i++)
    {
        if (name[i] == ' ' || name[i] == '\0')
        {
            printf("%c", toupper(name[i + 1]));
        }
    }
    printf("\n");
}