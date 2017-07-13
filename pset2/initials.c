#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string name = GetString();
    //print first initial
    printf ("%c", toupper(name[0]));

    for(int i=0, n=strlen(name); i<n; i++)
    {
        //search "space"
        if(name[i]==' ')
        {
            // print next initial
            printf("%c", toupper(name[i+1]));
        }
    }
 printf("\n"); 
 return(0);
}
