#include <stdio.h>
#include <cs50.h>

int main(void){
    int h;
    do {
    printf ("Height: ");
    h = GetInt();
    }
    while (h<0 || h>23);
    int i = 0, k = 0, l = 1;
    while (h>0) {
        for (i = h - 1; i>0; i--) printf(" ");
        for (k = l; k>0; k--) printf("#");
        printf("  ");
        for (k = l; k>0; k--) printf("#");
        //for (i = h - 1; i>0; i--) printf(" ");
        printf("\n");
        l++;
        h--;
    }
    return 0;
}