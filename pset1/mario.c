#include <stdio.h>
#include <cs50.h>

int main(void) // здесь запускается програма //
{
	int height = 0;
	
	do {
		printf("Height:"); // программа запрашивает ввести высоту //
		height = GetInt(); // поле ввода высоты //
        if (height == 0) //если ввести высоту 0, тогда программа опять запросит ввести высоту//
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
