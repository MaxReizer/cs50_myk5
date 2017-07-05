#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool IsSymbol(char c);
void Encrypt(int key, string text);
int GetKey();

int main(int argc, string argv[]){
    int key;
    if(argc>1){
        key = atoi(argv[1])%26;
    }
    else{
        key = 0;
    }
    string text = GetString();
    Encrypt(key, text);
}


bool IsSymbol(char c){
    if((c>64&&c<91)||(c>96&&c<123))
        return true;
    return false;
}

void Encrypt(int key, string text){
    int temp;
    if(key>0)
        for(int i = 0, n = strlen(text); i < n; i++){
            if(IsSymbol(text[i])){
                temp = (int)text[i] + key;
                if(islower(text[i])){
                    if(temp>122)
                        temp = temp - 122 + 96;
                    text[i] = (char)temp;
                }else{
                    if(temp>90)
                        temp = temp - 90 + 64;
                    text[i] = (char)temp;
                    }
            }
            
        }
    printf("%s\n", text);
}