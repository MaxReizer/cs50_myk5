#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool IsSymbol(char c);
bool IsNotNull(string key, string text);
void Encrypt(string key, string text);

int main(int argc, string argv[]){
    string key;
    if(argc>1)
        key = argv[1];
    else
        key = "";
    string text = GetString();
    Encrypt(key, text);
}

bool IsSymbol(char c){
    if((c>64&&c<91)||(c>96&&c<123))
        return true;
    return false;
}

void Encrypt(string key, string text){
    int temp, k;
    int j = 0;
    for(int i = 0, n = strlen(text), lenKey = strlen(key); i < n; i++){
        if(IsSymbol(text[i])&&IsNotNull(key, text)){
            k = (int)tolower(key[j])-97;
            temp = (int)text[i] + k;
            j = (j+1)%lenKey;
            if(islower(text[i])){
                while(temp>122)
                    temp = temp - 122 + 96;
                text[i] = (char)temp;
            }else{
                while(temp>90)
                    temp = temp - 90 + 64;
                text[i] = (char)temp;
                }
        }
        
    }
    printf("%s\n", text);
}

bool IsNotNull(string key, string text){
    if(key != NULL && text != NULL && strlen(key)>0)
        return true;
    return false;
}