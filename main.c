#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

char* longestNiceSubString(char* s){
    char* result;
    char alphabet[strlen(s)];
    int tmpIndex = 0;

    int strlenAlphabet = sizeof(alphabet)/sizeof(char);

    for(int i = 0; i < strlen(s); i++){
        if(i == 0){
            alphabet[tmpIndex] = s[i];
        }else{
            bool insideAlphabet = false;
            printf("%d", strlen(alphabet));
            for(int j = 0; j < strlen(alphabet); j++){
                if(s[i] == alphabet[j] || s[i] == (alphabet[j] + 32) || s[i] == (alphabet[j] - 32)){
                    insideAlphabet = true;
                }
            }
            if(!insideAlphabet){
                alphabet[++tmpIndex] = s[i];
            }
        }
    }

    for(int i = 0; i < sizeof(alphabet)/sizeof(char); i++){
        printf("%c", alphabet[i]);
    }
}

void main(){
    char* s = "YazaAay";
    printf("String em teste: %s", s);

    longestNiceSubString(s);
}