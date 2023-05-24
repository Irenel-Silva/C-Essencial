#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>


typedef struct no{
    int valor;
    struct no *proximo;
}No;

// Empilhar
No* empilhar(No *pilha, int num){
    No *novo= malloc(sizeof(No));
    if(novo){
        novo->valor= num;
        novo->proximo=pilha;
        return novo;
    }
    else
        printf("\nErro ao alocar Memoria\n");
    return NULL;
}

// desempilhar

No* desempilhar(No **pilha){
    if(*pilha!=NULL){
        No *remover= *pilha;
        *pilha= remover->proximo;
        return remover;
    }
    else
        printf("\npilha vazia\n");
    return NULL;
}



//IMprimir Pilha

void imprimir_pilha(No *pilha){
    printf("\tImprimindo a Pilha\n");
    while (pilha)
    {
        printf("\t%d\n", pilha->valor);
        pilha= pilha->proximo;

    }
    printf("\n");
    
}
int factorial_stack(int num){
    No *remover, *pilha=NULL;
    while (num>1)
    {
        pilha= empilhar(pilha,num);
        num--;
    }
    imprimir_pilha(pilha);

    while (pilha)
    {
        remover= desempilhar(&pilha);
        if(remover){
            num=remover->valor*num;
            //printf("\t%d\n", num);
            free(remover);
        }
    }
    return num;
    
}

int main(){
int numero;
printf("\nDigite um valor maior que zero para o factorial: ");
scanf("%d", &numero);


printf("\tFactorial de %d é: %d\n", numero, factorial_stack(numero));


    return 0;
}

