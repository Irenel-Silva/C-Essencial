#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

typedef struct no{
    int valor;
    struct no *proximo;
}No;

//Implentando Listas

//Inserir no inicio da lista


void inserir_InicioLista(No **lista, int numero){
    No *novo= malloc(sizeof(No));
    if(novo){
        novo->valor=numero;
        novo->proximo=*lista;
        *lista=novo;// Ligação do nó na lista
    }
    else
        printf("\n\tErro ao alocar Memoria!\n");
}


// Inserir No fim da Lista

void Inserir_FimLista(No **lista, int numero){
    No *aux;
    No *novo=malloc(sizeof(No));
    if(novo){
        novo->valor=numero;
        novo->proximo=NULL;
        if(*lista==NULL){
            *lista=novo;
        }
        else{
            aux=*lista;
            while(aux->proximo)
                aux=aux->proximo;
            aux->proximo=novo;// inseri na ultima posição da lista
        }
    }
    else
        printf("\n\tErro ao alocar memoria!\n");
}


// Inserir no meio da lista

void Inserir_MeioLista(No **lista, int numero, int antesinsercao){
    No *aux;
    No *novo=malloc(sizeof(No));
    if(novo){
        novo->valor=numero;
        if(*lista==NULL){
            novo->proximo=NULL;
            *lista=novo;
        }
        else
        {
            aux=*lista;
            while(aux->proximo && aux->valor!=antesinsercao)
                aux=aux->proximo;
            novo->proximo=aux->proximo;
            aux->proximo=novo;
        }

    }
    else
        printf("\n\tErro ao alocar memoria!\n");
}


void Imprimir_lista(No *lista){
    printf("\n\t-----Lista-----\n\t");
    while(lista){
        printf("%d ", lista->valor);
        lista=lista->proximo;
    }
    printf("\n\t-----Fim Lista-----\n");
}

// Removendo nô de uma lista simplesmente encadeada


No* remocao_lista(No **lista, int num){
    No *aux, *remover=NULL;
    if(*lista){
        if((*lista)->valor==num){
            remover=*lista;
            *lista=remover->proximo;
        }
        else{
            aux=*lista;
            while(aux->proximo && aux->proximo->valor!=num)
                aux=aux->proximo;
            if(aux->proximo){
                remover= aux->proximo;
                aux->proximo=remover->proximo;
            }
        }
    }
    else
        printf("\n\tLista Vazia!\n");
    return remover;
}

No* buscar_lista(No **lista, int num){

    No *aux, *nodo=NULL;
    aux=*lista;
    while(aux && aux->valor!=num)
        aux=aux->proximo;
    if(aux)
        nodo=aux;
    return nodo;
}

int ler_elemento(){
    int valor;
    printf("\n\tDigite o valor: \n\t");
    scanf("%d", &valor);
    return valor;
}


int Remover_elemento(){
    int valor;
    printf("\n\tDigite o valor a remover da lista: \n\t");
    scanf("%d", &valor);
    return valor;
}


int buscar_elemento(){
    int valor;
    printf("\n\tDigite o valor a procurar na lista: \n\t");
    scanf("%d", &valor);
    return valor;
}


int ler_elementoMeio(){
    int valor;
    printf("\n\tDigite o valor do meio da lista para que seja inserido apos deste valor na lista: \n\t");
    scanf("%d", &valor);
    return valor;
}
int main(){
    No *lista=NULL, *remover, *buscar;
    int opcao, elemento, meio;
    do{
        printf("\n\t0- sair\n\t1- Inserir Inicio\n\t2- Inserir no Meio\n\t3- Inserir no Fim\n\t4- Remover valor\n\t5- Buscar na Lista\n\t6- Imprimir Lista\n\t");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            elemento=ler_elemento();
            inserir_InicioLista(&lista, elemento);
            break;
        case 2:
            elemento=ler_elemento();
            meio= ler_elementoMeio();
            Inserir_MeioLista(&lista, elemento, meio);
            break;
        case 3:
            elemento=ler_elemento();
            Inserir_FimLista(&lista, elemento);
            break;
        case 4:
            elemento= Remover_elemento();
            remover=remocao_lista(&lista, elemento);
            if(remover){
                printf("\n\tElemento %d removido com sucesso\n", remover->valor);
                Imprimir_lista(lista);
                free(remover);
            }
            break;

        case 5:
            elemento=buscar_elemento();
            buscar=buscar_lista(&lista, elemento);
            if(buscar)
                printf("\n\tElemento %d encontrado com sucesso!\n", buscar->valor);
            else
                printf("\n\tElemento não existe na pilha!\n");
            break;
        case 6:
            Imprimir_lista(lista);
            break;
        default:
            if(opcao!=0)
                printf("\n\tOpcao invalida!\n");
        }
    }while(opcao!=0);

    return 0;

}