#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


typedef struct no{
    int valor;
    struct no *proximo;
}No;

void InserirInicio_lista(No **lista, int num){
    No *novo= malloc(sizeof(No));
    if(novo){
        novo->valor=num;
        novo->proximo=*lista;
        *lista=novo;
    }
    else
        printf("\n\t Erro ao alocar Memoria!\n");
}

void InserirFim_lista(No **lista, int num){
    No *aux, *novo= malloc(sizeof(No));
    if(novo){
        novo->valor=num;
        //Lista está vazia
        if(*lista==NULL){
            novo->proximo=NULL;
            *lista=novo;
        }
        else{
            //Lista possui elementos
            aux=*lista;
            while(aux->proximo)
                aux=aux->proximo;
            novo->proximo=aux->proximo;
            aux->proximo=novo;
        }
    }
    else
        printf("\n\t Erro alocar memoria!\n");
}


void InserirMeio_lista(No **lista, int num, int ant){
    No *aux, *novo=malloc(sizeof(No));
    if(novo){
        novo->valor=num;
        //Lista está vazia
        if(*lista==NULL){
            novo->proximo=NULL;
            *lista=novo;
        }
        else{
            aux=*lista;
            while(aux->proximo && aux->proximo->valor!=ant)
                aux=aux->proximo;
            if(aux->proximo){
                novo->proximo=aux->proximo;
                aux->proximo=novo;
            }
        }
    }
    else
        printf("\n\tErro ao alocar Memoria!\n");
}

void InserirOrdenado_lista(No **lista, int num){
    No *aux, *novo=malloc(sizeof(No));
    if(novo){
        novo->valor=num;
        //Lista esta vazia
        if(*lista==NULL){
            novo->proximo=NULL;
            *lista=novo;
        }
        else{
            if((*lista)->valor>num){
                novo->proximo=*lista;
                *lista=novo;
            }
            else{
                aux=*lista;
                while(aux->proximo && aux->proximo->valor<num)
                    aux=aux->proximo;
                if(aux->proximo){
                    novo->proximo=aux->proximo;
                    aux->proximo=novo;
                }
            }
        }
    }
    else
        printf("\n\tErro ao alocar Memoria!\n");
}

void Imprimi_lista(No *lista){
    printf("\n\t----Inicio Lista\n");
    if(lista){
        while(lista){
            printf(" %d ", lista->valor);
            lista=lista->proximo;
        }
    }
    else
        printf("\n\tLista vazia\n");

    printf("\n\t----Fim Lista\n");
}

No* remocao_lista(No **lista, int num){
    No *aux, *remove=NULL;
    if(*lista){
        if((*lista)->valor==num){
            remove=*lista;
            *lista=remove->proximo;
        }
        else{
            aux=*lista;
            while(aux->proximo && aux->proximo->valor!=num)
                aux=aux->proximo;
            if(aux->proximo){
                remove=aux->proximo;
                aux->proximo=remove->proximo;
            }
        }
    }
    return remove;

}

No* busca_lista(No **lista, int num){
    No *aux, *buscar=NULL;
    if(*lista){
        if((*lista)->valor==num){
            buscar=*lista;
        }
        else{
            aux=*lista;
            while(aux->proximo && aux->proximo->valor!=num)
                aux=aux->proximo;
            if(aux){
                buscar=aux;
            }
        }
    }


    return buscar;
}