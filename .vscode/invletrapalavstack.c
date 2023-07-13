#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

//Como inverter a ordem das letras de uma string(Frase com uma ou mais palavras) preservando a ordem das palavras



typedef struct no{
    char caracter;
    struct no *proximo;
}No;


No* empilhar(No *pilha, char palavra){
    No *novo= malloc(sizeof(No));
    if(novo){
        novo->caracter=palavra;
        novo->proximo= pilha;
        //return novo;
    }
    else
        printf("\nErro ao alocar Memoria!\n");
    return novo;
}



No* desempilhar(No **pilha){
    No *remover;
    if(*pilha){
        remover=*pilha;
        *pilha=remover->proximo;
    }
    else
        printf("\nPilha vazia!\n");
    return remover;
}

/*void imprimir_pilha(No *pilha){
    printf("\tPilha\n");
    while(pilha){
        printf("\t%c", pilha->caracter);
        pilha= pilha->proximo;
    }
    printf("\n");
    printf("\tFim Pilha\n");
}*/



void inverter_strings(char x[]){
    No *remover, *pilha=NULL;
    int i=0;
      while(x[i]!='\0'){
        if(x[i]!=' ')
            pilha=empilhar(pilha, x[i]);
        else{
            while(pilha){
                remover= desempilhar(&pilha);
                if(remover){
                    printf("%c",remover->caracter); // Outro jeito seria armazenar em um vector;
                    free(remover);
                }
            }
            printf(" ");
        }
        i++;
      }
      while(pilha){
        remover= desempilhar(&pilha);
        if(remover){
            printf("%c",remover->caracter); // Outro jeito seria armazenar em um vector;
            free(remover);
        }
      }
      printf("\n");
}




int main(){
    char frase[50]={"Abra a porta Mariquinha"};
    inverter_strings(frase);


    return 0;
}