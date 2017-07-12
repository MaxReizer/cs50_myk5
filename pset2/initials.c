#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void printInitials(string name);

int main(void)
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