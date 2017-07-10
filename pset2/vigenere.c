#include <stdio.h>
#include <math.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h> 


int main(int argc, string argv[]) 
{
    
    bool check = false;
    int length = 0;
    string message = "";
    int input = 0;
    int k = 0;

    //check that user type 2 arguments
    if (argc != 2)
    {
        printf("Usage: ./caesar 'your key'\n");
        return 1;
    }
    //check that argv is alphabetic    
    else 
    {
        //count length of argv[1]
        length = strlen(argv[1]);
        
        // get letter by letter from argv[1]
        for (int i = 0; i < length; i++)
        {
            // checking each letter
            if (!isalpha(argv[1][i]))
            {
                printf("key must be alphabetic\n");
                return 1;
            }
            else
            {
                check = true;
            }
        }
    }
    
    while(!check);
    
    //make array "key" with length = argv[1]
    int key[length];
    
    // convert ASCII to alphabet
    for (int i = 0; i < length; i++)
    {
        
        // if letter from key is uppercase convert it to lowercase
        if (isupper(argv[1][i]))
        {
            key[i] = ((argv[1][i] + 32) - 97);
        }
        else
        {
            key[i] = (argv[1][i] - 97);
        }
    }
    
    //get message from user
    message = GetString();
    
    //count message length
    input = strlen(message);
    
    //start 
    for (int j = 0; j < input; j++)
    {
    
        //if 'j' is not a letter, just print what 'j' consist
        if(!isalpha(message[j]))
        {
            printf("%c", message[j]);
        }
        
        //check, that 'j' is a letter
        else
        {

            //check, letter in 'j' to be uppercase ("caesar" cipher)
            if (isupper(message[j]))
            {
                //convert ACSII to alphabet, encrypt with letter from "key" in "k" position and convert back to ASCII
                printf("%c", ((((message[j] - 65) + key[k]) % 26) + 65));
            }
            
            //if 'j' lowercase do this
            else
            {
                //convert ACSII to alphabet, encrypt with letter from "key" in "k" position and convert back to ASCII
                printf("%c", ((((message[j] - 97) + key[k]) % 26) + 97));
            }
            
            // check "k" and get +1 to it
            if (k < length - 1)
            {
                k++;
            }
            else
            {
                k = 0;
            }
            
        }
    }
                
    printf("\n");
}



