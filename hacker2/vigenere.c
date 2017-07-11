#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


 int main(int argc, string argv[])
 {
    // check for 2 arguments only
    if (argc != 2)
    {
        printf("Error\n");
        return 1;
    }
    
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (isalpha(argv[1][i]) == 0)
        {
            printf("Error\n");
            return 1;
        }
    }
    
    string codeword = GetString();
    int j = 0;
    
    // loop through the codeword. If not a letter than print unmodified.
    for (int i = 0, n = strlen(codeword); i < n; i++)
    {
        // to keep looping through the key continously
        j = j % strlen(argv[1]);
        
        // check if the char is alpha
        if (isalpha(codeword[i]))
        {
            // only 4 types of outcomes
            if (islower(codeword[i]) && islower(argv[1][j]))
                printf("%c", (((codeword[i] - 97) + (argv[1][j] - 97)) % 26) + 97);
            else if (isupper(codeword[i]) && islower(argv[1][j]))
                printf("%c", (((codeword[i] - 65) + (argv[1][j] - 97)) % 26) + 65);
            else if (islower(codeword[i]) && isupper(argv[1][j]))
                printf("%c", (((codeword[i] - 97) + (argv[1][j] - 65)) % 26) + 97);
            else if (isupper(codeword[i]) && isupper(argv[1][j]))
                printf("%c", (((codeword[i] - 65) + (argv[1][j] - 65)) % 26) + 65);
            j++;
        }
        else
        {
            printf("%c", codeword[i]);
        }
    }
    printf("\n");
}