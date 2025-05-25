#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

// Versão feita em casa - 25/05/2025

//Função que vai percorrer cada letra de uma substring informada e procurar um par para ela
//para cada letra, vai entrar em um while procurando seu par.
//se não for encontrado um par para alguma letra da substring, ela não é nice e retorna false
bool isNiceSubStrig(char* str){
    int i = 0;
    while( str[i] != '\0' ){
        int j = 0;
        bool matchFound = false;

        //pega letra x da substring e procura por um par pra ela em cada casa da substring
        while( str[j] != '\0' ){
            if( str[i] == ( str[j] + 32 ) || str[i] == ( str[j] - 32 ) ){
                matchFound = true;
            }
            j++;
        }
        if( !matchFound ) return false;
        i++;
    }

    //se chegou aqui é pq encontrou um par para todas as letras da substring, configurando niceString
    return true;
}

char* longestNiceSubString(char* s){
    int longestSize = 0;
    char* longestSubString = NULL; 

    for( int i = 0; i < strlen(s); i++ ){
        for( int j = strlen(s); j > i; j-- ){
            int subStringSize = j - i;
            char* substring = (char*)malloc( (subStringSize + 1) * sizeof(char) );
            
            if( substring == NULL ) {
                printf( "\nErro ao alocar memória." );
                exit(0);
            }

            //gera substring a partir da letra iterada
            for( int q = 0; q < subStringSize; q++ ){
                substring[q] = s[q + i];
            }
            substring[subStringSize] = '\0';

            //testa se a subString em questão é niceString
            //se for uma niceString e seu tamanho for maior do que o maior tamanho de nicestring já registrado
            if( isNiceSubStrig(substring) && ( subStringSize > longestSize ) ){
                //libera antigo maior niceString
                if(longestSubString != NULL) free(longestSubString);

                //atualiza os valores de maior nice substring já encontrada
                longestSize = subStringSize;
                longestSubString = substring;
            }else{
                free( substring );
            }
            
        }
    }

    return longestSubString;
}

void main(){
    char* s = "YazaAay";
    printf( "String em teste: %s", s );

    printf( "\nNiceString mais longe: %s", longestNiceSubString(s) );
}