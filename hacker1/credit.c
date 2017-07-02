#include <cs50.h>
#include <stdio.h>

int main(void){
    // Получаем номер карты
    printf("Number: ");
    int i = 0, c = 0, sum1 = 0, sum2 = 0;
    long long card = GetLongLong();
    //делим число на цифры
    for(;card>0;i++){
                c = card % 10;
                card/=10;
                if (i % 2 != 0){ //каждая второя цифра с конца
                    if (c>4) sum1 = sum1 + (c*2 % 10) + 1; //те числа, которые больше за 4 разделим на десятки и единицы
                    else sum1+=c*2;
                }
                else sum2+=c;
                
        }
    //проверяем валидности номера карты
    if ((sum1 + sum2) % 10 == 0){ 
        //проверяем тип карты
        switch (i){
            case 15: printf ("AMEX\n"); break;
            case 13: printf ("VISA\n"); break;
            case 16: 
                if (c == 4) printf ("VISA\n");
                else printf ("MASTERCARD\n");
                break;
            default: printf ("INVALID\n");
        }
    }
    else printf("INVALID\n"); 
    return 0;
}