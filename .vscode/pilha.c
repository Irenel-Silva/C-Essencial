#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"



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