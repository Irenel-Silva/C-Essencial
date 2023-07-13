#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

typedef struct no{
    int valor;
    struct no *proximo;
}No;


typedef struct{
    No *inicio;
    int tam;
}Lista;

// Inicializar Lista

void criar_lista(Lista *lista){
    lista->inicio=NULL;
    lista->tam=0;
}


void Inserir_InicioLista(Lista *lista, int numero){
    No *novo=malloc(sizeof(No));
    if(novo){
        novo->valor=numero;
        novo->proximo=lista->inicio;
        lista->inicio= novo;
        lista->tam++;
    }
    else
        printf("\n\tErro ao alocar Memoria!\n");

}


void Inserir_FimLista(Lista *lista, int numero){
    No *aux;
    No *novo=malloc(sizeof(No));
    if(novo){
        novo->valor= numero;
        novo->proximo= NULL;
        if(lista->inicio==NULL)
            lista->inicio=novo;
        else{
            aux=lista->inicio;
            while(aux->proximo)
                aux= aux->proximo;
            aux->proximo=novo;

        }
        lista->tam++;

    }
    else
        printf("\n\tErro ao alocar Memoria!\n");
}


void Inserir_MeioLista(Lista *lista, int numero, int antesinsercao){
        No *aux, *novo=malloc(sizeof(No));
        if(novo){
            novo->valor=numero;
            if(lista->inicio==NULL){
                novo->proximo=lista->inicio;
                lista->inicio=novo;
            }else{
                aux= lista->inicio;
                while(aux->proximo && aux->valor!=antesinsercao)
                    aux=aux->proximo;
                novo->proximo=aux->proximo;
                aux->proximo=novo;
            }
            lista->tam++;
        }
        else
            printf("\n\tErro ao alocar Memoria!\n");
}

void imprimir_Lista(Lista lista){
    No *no= lista.inicio;
    printf("\n\t-----Lista tamanho %d -------\n\t",lista.tam);
    while(no){
        printf("%d ", no->valor);
        no= no->proximo;
    }
    printf("\n\t-----Fim Lista-----\n");
}



void Inserir_ordenado(Lista *lista, int num){
    No *aux, *novo=malloc(sizeof(No));
    if(novo){
        novo->valor=num;
        if(lista->inicio==NULL){
            novo->proximo=lista->inicio;
            lista->inicio=novo;
        }
        else{
            if((lista->inicio)->valor>novo->valor){
                novo->proximo=lista->inicio;
                lista->inicio=novo;
            }
            else{
                aux=lista->inicio;
                while(aux->proximo && aux->proximo->valor<novo->valor)
                    aux=aux->proximo;
                novo->proximo=aux->proximo;
                aux->proximo=novo;

            }
        }
        lista->tam++;
    }
    else
        printf("\n\tErro ao alocar memoria!\n");
}



No* remocao_lista(Lista *lista, int num){
    No *aux, *remover=NULL;
    if(lista->inicio){
        if((lista->inicio)->valor==num){
            remover=lista->inicio;
            lista->inicio=remover->proximo;
            lista->tam--;
        }
        else{
            aux=lista->inicio;
            while(aux->proximo && aux->proximo->valor!=num)
                aux=aux->proximo;
            if(aux->proximo){
                remover=aux->proximo;
                aux->proximo=remover->proximo;
                lista->tam--;
            }
        }
        

    }
    else
        printf("\n\tLista Vazia!\n");

    return remover;
}

No* buscar_lista(Lista *lista, int num){
    No *nodo=NULL, *aux;
    aux=lista->inicio;
    while(aux && aux->valor!=num)
        aux=aux->proximo;
    if(aux)
        nodo=aux;
    return nodo;
}

int buscar_elemento(){
    int valor;
    printf("\n\tDigite o valor a procurar na lista: \n\t");
    scanf("%d", &valor);
    return valor;
}


int ler_elemento(){
    int valor;
    printf("\n\tDigite o valor: \n\t");
    scanf("%d", &valor);
    return valor;
}


int Remover_elemento(){
    int valor;
    printf("\n\tDigite o valor a remover: \n\t");
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
    Lista lista;
    criar_lista(&lista);
    No *remover, *buscar;
    int opcao, elemento, meio;
    do{
        printf("\n\t0- sair\n\t1- Inserir Inicio\n\t2- Inserir no Meio\n\t3- Inserir no Fim\n\t4- Inserir de forma ordenada\n\t5- Remover item da lista\n\t6- Buscar na lista\n\t7- Imprimir Lista\n\t");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            elemento=ler_elemento();
            Inserir_InicioLista(&lista, elemento);
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
            elemento=ler_elemento();
            Inserir_ordenado(&lista, elemento);
            break;
        case 5:
            elemento=Remover_elemento();
            remover=remocao_lista(&lista,elemento);
            if(remover){
                printf("\n\t Elemento %d removido com sucesso!\n", remover->valor);
                imprimir_Lista(lista);
                free(remover);
            }

            break;
        case 6:
            elemento=buscar_elemento();
            buscar=buscar_lista(&lista, elemento);
            if(buscar)
                printf("\n\tElemento %d encontrado na lista!\n", buscar->valor);
            else
                printf("\n\tElemento não existe na lista!\n");
            break;


        case 7:
            imprimir_Lista(lista);
            break;
        default:
            if(opcao!=0)
                printf("\n\tOpcao invalida!\n");
        }
    }while(opcao!=0);

    return 0;

}