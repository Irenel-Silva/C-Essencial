#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

typedef struct no{
    int valor;
    struct no *proximo;
}No;


No* empilhar_pilha(No *pilha, int numero){
    No *novo=malloc(sizeof(No));
    if(novo){
        novo->valor=numero;
        novo->proximo=pilha;
        return novo;
    }
    else{
        printf("\n\tErro ao alocar Memoria!\n");
        return NULL;
    }
}


No* desempilhar_pilha(No **pilha){
    No *remover=NULL;
    if(pilha){
        remover=*pilha;
        *pilha=remover->proximo;
    }
    else
        printf("\n\tPilha vazia!\n");
    return remover;
}

void imprimir_pilha(No *pilha){
    printf("\n\t-----Pilha-----\n\t");
    while(pilha){
        printf("%d\n\t", pilha->valor);
        pilha=pilha->proximo;
    }
    printf("\n\t-----Fim Pilha-----\n\t");
}

//=================================||=======================================||=============================//
//Lidar com Filas
void inserir_fila(No **fila, int numero){
    No *novo= malloc(sizeof(No));
    No *aux;
    if(novo){
        novo->valor=numero;
        novo->proximo=NULL;
        if(*fila==NULL)
            *fila=novo;
        else{
            aux=*fila;
            while(aux->proximo)
                aux= aux->proximo;
            aux->proximo=novo;
        }
    }else
        printf("\n\t Erro ao alocar Memoria!\n");
}

No* desempilhar_fila(No **fila){
    No *remover=NULL;
    if(*fila){
        remover=*fila;
        *fila=remover->proximo;
    }else
        printf("\n\tFila vazia!\n");
    return remover;
}

void imprimir_fila(No *fila){
    printf("\n\t-----Fila---------\n\t");
    while(fila){
        printf("%d ", fila->valor);
        fila=fila->proximo;
    }
    printf("\n\t-----Fim Fila-----\n\t");
}

//=================================||=======================================||=============================//
// Fila Com Prioridade

void inserir_ComPrioridade(No **fila, int num){
    No *novo=malloc(sizeof(No));
    No *aux;
    if(novo){
        novo->valor=num;
        novo->proximo=NULL;
        if(*fila==NULL)
            *fila=novo;
        else{
            if(num>59){
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
            else{
                aux=*fila;
                while (aux->proximo)
                    aux=aux->proximo;
                aux->proximo=novo;
                
            }
        }

    }
    else
        printf("\n\tErro ao alocar Memoria!\n");

}

int main(){
    No *remove, *pilha=NULL;
    No *fila=NULL;
    int opcao, num;

    do{
        printf("\n\t0- Sair\n\t1- Empilhar\n\t2- Desempilhar\n\t3- Imprimir\n\t4- Inserir com Prioridade\n\t");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            printf("\n\tDigite o Elemento para pilha: \n\t");
            scanf("%d", &num);
            //pilha= empilhar_pilha(pilha, num);
            inserir_fila(&fila, num);
            break;
        case 2: 
            //remove= desempilhar_pilha(&pilha);
            remove= desempilhar_fila(&fila);
            if(remove){
                printf("\n\tElemento %d Removido!\n", remove->valor);
                free(remove);
            }
        case 3:
            //imprimir_pilha(pilha);
            imprimir_fila(fila);
            break;
        case 4:
            printf("\n\tDigite o Elemento para pilha: \n\t");
            scanf("%d", &num);
            inserir_ComPrioridade(&fila,num);
            break;
        
        default:
            if(opcao!=0)
            printf("\n\t Opcao Invalida!\n");
            break;
        }
    }while(opcao!=0);


    return 0;
}