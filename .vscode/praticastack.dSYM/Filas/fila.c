#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

//Introdução as Filas 

typedef struct no{
    int valor;
    struct no *proximo;
}No;

void inserir_fila(No **fila, int num){
    No *aux;
    No *novo=malloc(sizeof(No));
    if (novo)
    {
        novo->valor= num;
        novo->proximo=NULL;
        if(*fila==NULL)
            *fila=novo;
        else{
            aux=*fila;
            while (aux->proximo)
                aux= aux->proximo;   
            aux->proximo=novo;
            
        }
    }
    else
        printf("\n\tErro ao alocar Memoria!\n");
    
}

No* removocao_fila(No **fila){
    No *remover=NULL;
    if(*fila){
        remover=*fila;
        *fila=remover->proximo;
    }
    else{
        printf("\n\tFila Vazia!\n");
    }
    return remover;
}

void imprimir_fila(No *fila){
    printf("\n\t-----Fila-----\n\t");
    while (fila)
    {
        printf("%d ", fila->valor);
        fila=fila->proximo;
    }
    
    printf("\n\t-----Fim Fila-----\n");
}


int main(){
    No *fila=NULL, *remover;
    int opcao, digito;
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
                remover=removocao_fila(&fila);
                if (remover)
                {
                 printf("\n\tValor %d Removido\n", remover->valor);  
                 free(remover); 
                }
                break;
            case 3:
                imprimir_fila(fila);
                break;
            default :
                if(opcao!=0)
                    printf("\n\tOpcão invalida!\n");
                

        }
    }while(opcao!=0);



    return 0;
}