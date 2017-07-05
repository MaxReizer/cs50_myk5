#include <stdio.h>
#include <cs50.h>

int main(void) 
{
	int h = 0;
	
	do 
	{
		printf("Height: ");
		h = GetInt();       //ввод высоты башни
        if (h == 0)         //проверка высоты башни на значени 0
        	{
        		return 0;
        	}
	} 
	while (h < 1 || h > 23);  //проверка значения высоты башни в пределах 1-23

	for(int i = 0; i < h; i++) 
	{
		for(int j = 0; j < h-i-1; j++) //рисуем пробелы
        {
            printf("%s", " ");
        }
        
		for(int k = 0; k < i+2; k++) //рисуем хештеги первой башни
		{
			printf("#");
		}
		printf("%s", " "); //пробел между башнями
		for(int k = 0; k < i+2; k++) //рисуем хештеги второй башни
		{
			printf("#");
		}
		printf("\n");  //перенос строки
	}	
	return 0;
}