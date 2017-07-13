#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    if(argc != 2)
    { 
    printf("print the key next time \n");
    return(1);
    }
int k = atoi(argv[1]);

string p = GetString();

for (int i = 0, n = strlen(p); i < n; i++)
{
    if(isalpha(p[i]))
    {
      if(isupper (p[i]))
         {
        printf("%c", (((((p[i])-65)+k)%26)+65));
         }
        else
        printf("%c", (((((p[i])-97)+k)%26)+97));
    }
    else
    printf("%c", p[i]);
}
printf("\n");
}