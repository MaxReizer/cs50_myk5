#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
 
int main(int argc, string argv[])
{   
    //ensure user entered a valid key
    if (argc != 2)
    {
        printf("Enter: ./caesar key\n");
        return 1;     
    }
    else
    {
        //get plaintext from user
        string plainTxt = GetString();
        int k = atoi(argv[1]);
    
    //encrypt message
    for (int i = 0, n = strlen(plainTxt); i < n; i++)
    {
        if (isalpha(plainTxt[i]))
        {
            if (islower(plainTxt[i]))
            {
                int small = (((plainTxt[i] - 97 + k) % 26) + 97);
                printf("%c", small);
            }
            if (isupper(plainTxt[i]))
            {
                int big = (((plainTxt[i] - 65 + k) % 26) + 65);
                printf("%c", big);
            }
        }
        else
        {
            //print encrypted message
             printf("%c", plainTxt[i]);
        }
        
    }   
    printf("\n"); 
}
}