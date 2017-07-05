#include <stdio.h>
#include <cs50.h>

int main(void) 
{
	int height = 0;
	
	do {
		printf("Height:");
		height = GetInt();
        if (height == 0)
        {
            return 0;
        }
	} while (height < 1 || height > 23);

	for(int i = 0; i < height; i++) 
	{
		for(int m = 0; m < height-i-1; m++)
        	{
            		printf("%s", " ");
        	}
        
		for(int t = 0; t < i+2; t++)
		{
			printf("#");
		}
		printf("\n");
	}	
	return 0;
}
