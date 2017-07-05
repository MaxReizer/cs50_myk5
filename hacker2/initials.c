#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

void printInitials(string s){
    bool flag = true;
    for(int i = 0, n = strlen(s); i < n; i++){
        s[i] = tolower(s[i]);
        if(s[i]>96 && s[i]<123){
            if(flag){
                printf("%c", toupper(s[i]));
                flag = false;
            }
        }else{
            flag = true;
        }
    }
    printf("\n");
}

int main(void){
    string s = GetString();
    printInitials(s);
}