#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>


typedef struct no{
    int valor;
    struct no *proximo;
}No;

//Inserir no inicio da lista;
void inserir_princLista(No **lista, int num){
    No *novo=malloc(sizeof(No));
    if(novo){
        novo->valor=num;
        novo->proximo=*lista;
        *lista=novo;
    }else{
        printf("\nErro ao alocar Memoria!\n");
    }
}
// Inserir no fim da lista

void Inserir_fimLista(No **lista, int numero){
    No *aux;
    No *novo= malloc(sizeof(No));
    if(novo){
        novo->valor=numero;
        novo->proximo= NULL;
        if(*lista==NULL)
            *lista=novo;
        else{
            aux= *lista;
            while(aux->proximo)
                aux=aux->proximo;
            aux->proximo=novo;
        }
    }
    else 
        printf("\nErro ao alocar Memoria!\n");

}

