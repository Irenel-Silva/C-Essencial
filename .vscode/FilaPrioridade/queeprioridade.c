#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>


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
                aux= aux->proximo;
            aux->proximo=novo;
        }
    }
    else
        printf("\n\tErro ao alocar memoria!\n");

}

void inserir_comPrioridade(No **fila, int num){
    No *novo=malloc(sizeof(No));
    if(novo){
        novo->valor= num;
        novo->proximo=NULL;
        if(*fila==NULL)
            *fila=novo;
        else{
            No *aux;
            if((*fila)->valor<60){
                novo->proximo=*fila;
                *fila=novo;
            }
            else{
                aux=*fila;
                while(aux->proximo && aux->proximo->valor>59)
                    aux=aux->proximo;
                novo->proximo=aux->proximo;
                aux->proximo=novo;
            }
        }

    }else
        printf("\n\t Erro ao alocar Memoria!\n");



}
