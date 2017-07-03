#include <stdio.h>
#include <math.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h> 

int main(int argc, string argv[]) 
{
    //preparing
    string message = "";
    int input = 0;
    int key = 0;

    //check that user type 2 arguments
    if (argc != 2)
    {
        printf("Usage: ./caesar 'your key'\n");
        return 1;
    }
    
    //get user's number 
    string keyword = argv[1];
    
    //convert string to int 
    key = atoi(keyword);
    
    //get message from user
    message = GetString();
    
    //count message length
    input = strlen(message);
    
    //start 
    for (int i = 0; i < input; i++)
    {
        
        //check, that 'i' is a letter
        if(isalpha(message[i]))
        {
            
            //check, letter in 'i' to be uppercase
            if (isupper(message[i]))
            {
                
                //convert ACSII to alphabet, encrypt and convert back to ASCII
                printf("%c", ((((message[i] - 65) + key) % 26) + 65));
            }
            
            //if 'i' lowercase do this
            else
            {
                
                //convert ACSII to alphabet, encrypt and convert back to ASCII
                printf("%c", ((((message[i] - 97) + key) % 26) + 97));
            }
        }
        
        //if 'i' is not a letter, just print what 'i' consist
        else
        {
            printf("%c", message[i]);
        }
    }

    printf("\n");
}