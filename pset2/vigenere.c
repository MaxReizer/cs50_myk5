#include <stdio.h>
#include <math.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h> 


int main(int argc, string argv[])
{ 
    bool check = false;
    int z=0;
    string key = argv[1];
    int keylen=0;
    
    
    if(argc != 2)
    { 
    printf("print 1 argument\n");
    return 1;
    }
    else
    {
        
    keylen = strlen(argv[1]);
        
      for (int i=0; i<keylen; i++)
        {
         if (!isalpha(key[i]))
            {
            printf("print correct argument\n");
            return 1;
            }
            else
            {
            check=true;
            }
        }
    }

while(!check);

int digitkey[keylen];

for(int j = 0; j<keylen; j++)
{
 if(isupper (key[j]))
    {
        digitkey[j]=(((key[j])+32)-97);
    }
    else
        digitkey[j]=((key[j])-97); 
}

string text = GetString();

    for (int i = 0; i < strlen(text); i++)
    {
        if(isalpha(text[i]))
        {
          if(isupper (text[i]))
             {
            printf("%c", (((((text[i])-65)+digitkey[z])%26)+65));
             }
            else
            {
            printf("%c", (((((text[i])-97)+digitkey[z])%26)+97));
            }
            if(z<keylen-1)
                {
                z++;
                }
            else
                {
                z=0;
                }
        }
        else
        {
        printf("%c", text[i]);
        }
    }
printf("\n");
return 0;
}
