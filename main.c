#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

//Função que vai percorrer cada letra a partir de um endereço informado, pelo numero de letras informado
//o endereço informado vai ser o inicio da substring
//o numero de letras vai ser o limite da substring
//para cada letra, vai entrar em um for procurando seu par
bool isNiceSubStrig(char* str, int stringSize){
    //for que itera por cada letra 
    for(int i = 0; i < stringSize; i++){
        bool matchFound = false;

        for(int j = 0; j < stringSize; j++){
            //pega letra x da substring e procura por um par pra ela em cada casa da substring
            if(str[i] == (str[j] + 32) || str[i] == (str[j] - 32)){
                matchFound = true;
            }
        }

        //caso nao encontre o par de apenas uma das letras já era
        if(!matchFound) return false;
    }

    //se chegou aqui é pq encontrou um par para todas as letras da substring, configurando niceString
    return true;
}

char* longestNiceSubString(char* s){
    int longestSize = 0;
    char* longestSubString = NULL; 

    for(int i = 0; i < strlen(s); i++){
        for(int j = strlen(s); j > i; j--){
            int subStringSize = j - i;
            char* substring = (char*)malloc((subStringSize + 1) * sizeof(char));
            
            if(substring == NULL) {
                printf("\nErro ao alocar memória.");
                exit(0);
            }

            //gera substring a partir da letra iterada
            for(int q = 0; q < subStringSize; q++){
                substring[q] = s[q + i];
            }
            substring[subStringSize] = '\0';

            //testa se a subString em questão é niceString
            //se for uma niceString e seu tamanho for maior do que o maior tamanho de nicestring já registrado
            if(isNiceSubStrig(substring, subStringSize) && subStringSize > longestSize){
                //libera antigo maior niceString
                if(longestSubString != NULL) free(longestSubString);

                //atualiza os valores de maior nice substring já encontrada
                longestSize = subStringSize;
                longestSubString = substring;
            }else{
                free(substring);
            }
            
        }
    }

    return longestSubString;
}

void main(){
    char* s = "c";
    printf("String em teste: %s", s);

    printf("\n%s", longestNiceSubString(s));
}