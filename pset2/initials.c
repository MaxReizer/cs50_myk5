#include <stdio.h>
#include <math.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void) 
{
    string name = GetString();
    
    if (name != NULL)
    {
        //print first letter uppercase
        printf("%c", toupper(name[0]));
    }
    
    //loop to found next first letters
    for (int i = 0, n = strlen(name); i < n; i++)
    {
        //founding next letter, that must be after a space
        if (name[i] == ' ' && name[i + 1] != '\0')
        {
            //printing next letter, that we found when 'i on a "space"', so "name[i+1]"
            printf("%c", toupper(name[i + 1]));
        }
    }
    printf("\n");

}