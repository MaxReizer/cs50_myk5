/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */
typedef unsigned char byte;
 
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE* infile = fopen("card.raw", "r");
    FILE* out;
    
    char name[7];
    int counter = 0;
    
    if (infile == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }
    
    unsigned char body[512];
    
    //Reading to EOF
    while (fread(body, sizeof(body), 1, infile) && !feof(infile))
    {
        if(body[0]==0xff&&body[1]==0xd8&&body[2]==0xff){
            if(counter<10)
                sprintf(name, "00%d.jpg", counter);
            else
                sprintf(name, "0%d.jpg", counter);
            counter++;
            out = fopen(name, "w");
            fwrite(body, 512, 1, out);
        }else if (counter > 0)
        {
            fwrite(body, 512, 1, out);            
        }
    }
    
    fclose(infile);
    fclose(out);
}
