#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <math.h>

//Fila Versão 2

typedef struct no{
    int valor;
    struct no *proximo;
}No;


typedef struct{
    int tamanho;
    No *prim;
    No *fim;
}Fila;


void criar_fila(Fila *fila){
    fila->tamanho=0;
    fila->fim=NULL;
    fila->prim=NULL;
}

void inserir_fila(Fila *fila, int num){
    No *novo=malloc(sizeof(No));
    No *aux;
    if(novo){
        novo->valor= num;
        novo->proximo=NULL;
        if(fila->prim==NULL){
            fila->prim= novo;
            fila->fim=novo;
        }
        else
        {
        fila->fim->proximo=novo;
        fila->fim=novo;
        }
        fila->tamanho++;
        
    }
    else
        printf("\n\tErro ao alocar Memoria!\n");

}


No *remocao_fila(Fila *fila){
    No *remover=NULL;
    if(fila->prim){
        remover=fila->prim;
        fila->prim = remover->proximo;
        fila->tamanho--;

    }
    else
        printf("\n\tFila vazia!\n");
    return remover;

}

void imprimir_fila(Fila *fila){
    No *aux=fila->prim;
    printf("\n\t-----Fila--------\n\t");
    while(aux){
        printf("%d ", aux->valor);
        aux=aux->proximo;
    }
    printf("\n\t-----FimFila-----\n\t");
}


int main(){
    Fila fila;
    No *remover;
    int opcao, digito;
    criar_fila(&fila);
    printf("\n\tOperações na Fila:\n");
    do{
        printf("\n\t0- Sair\n\t1- Inserir\n\t2- Remover\n\t3- Imprimir\n\t");
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                printf("\n\tDigite o valor a inserir na Lista:\n\t");
                scanf("%d", &digito);
                inserir_fila(&fila, digito);
                break;
            case 2:
                remover=remocao_fila(&fila);
                if (remover)
                {
                 printf("\n\tValor %d Removido\n", remover->valor);  
                 free(remover); 
                }
                break;
            case 3:
                imprimir_fila(&fila);
                break;
            default :
                if(opcao!=0)
                    printf("\n\tOpcão invalida!\n");
                

        }
    }while(opcao!=0);



    return 0;
}