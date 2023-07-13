#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

// IMplementando Filas com Prioridade 
typedef struct no{
    int valor;
    struct no *proximo;
}No;


void inserir_fila(No **fila, int num){
    No *aux;
    No *novo=malloc(sizeof(No));
    if(novo){
        novo->valor=num;
        novo->proximo=NULL;
        if(*fila==NULL)
            *fila=novo;
        else{
            aux=*fila;
            while(aux->proximo)
                aux=aux->proximo;
            aux->proximo=novo;

        }
    }
    else
        printf("\n\tErro ao alocar Memoria!\n");
}


void inserir_comprioridade_fila(No **fila, int num){
    No *aux;
    No *novo=malloc(sizeof(No));
    if(novo){
        novo->valor=num;
        novo->proximo=NULL;
        if(*fila==NULL)
            *fila=novo;
        else{
            if(num>59){
                if((*fila)->valor<60){
                    novo->proximo =*fila;// Aponta o primeiro nó da fila;
                    *fila= novo;
                }else{
                    aux=*fila;
                    while(aux->proximo && aux->proximo->valor>59)
                        aux=aux->proximo;
                    novo->proximo= aux->proximo;// Aponta o primeiro nó da fila;
                    aux->proximo= novo;
                }
            }
            else{
                aux=*fila;
                while(aux->proximo)
                    aux=aux->proximo;
                aux->proximo=novo;

            }
            

        }
    }
    else
        printf("\n\tErro ao alocar Memoria!\n");
}


