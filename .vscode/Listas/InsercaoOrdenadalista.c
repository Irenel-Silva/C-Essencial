#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>


typedef struct no{
    int valor;
    struct no *proximo;
}No;

// Insercão ordenada na lista encadeada


void Insercao_ordenada(No **lista, int num){
    No *aux, *novo=malloc(sizeof(No));
    if(novo){
        novo->valor=num;
        // A lista está vazia
        if(*lista==NULL){
            novo->proximo=*lista;
            *lista=novo;
        }// é o menor?
        else{
            if((*lista)->valor> novo->valor){
                novo->proximo=*lista;
                *lista= novo;
            }
            else{
                aux=*lista;
                while(aux->proximo && novo->valor>aux->proximo->valor)
                    aux=aux->proximo;
                novo->proximo=aux->proximo;
                aux->proximo=novo;
            }
        }




    }
    else
        printf("\n\tErro ao alocar Memoria!\n");
}

void Imprimir_lista(No *lista){
    printf("\n\t-----Lista-----\n\t");
    while(lista){
        printf("%d ", lista->valor);
        lista=lista->proximo;
    }
    printf("\n\t-----Fim Lista-----\n");
}





int ler_elemento(){
    int valor;
    printf("\n\tDigite o valor: \n\t");
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
    /*Lista lista;
    criar_lista(&lista);*/

    No *remover, *lista= NULL;
    int opcao, elemento, meio;
    do{
        printf("\n\t0- sair\n\t1- Inserir Inicio\n\t2- Inserir no Meio\n\t3- Inserir no Fim\n\t4- Imprimir Lista\n\t5- Inserir Ordenado\n\t");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            //elemento=ler_elemento();
            //Inserir_InicioLista(&lista, elemento);
            break;
        case 2:
            //elemento=ler_elemento();
            //meio= ler_elementoMeio();
            //Inserir_MeioLista(&lista, elemento, meio);
            break;
        case 3:
            //elemento=ler_elemento();
            //Inserir_FimLista(&lista, elemento);
            break;
        case 4:
            Imprimir_lista(lista);
            break;
        case 5:
            elemento=ler_elemento();
            Insercao_ordenada(&lista, elemento);
            break;
        default:
            if(opcao!=0)
                printf("\n\tOpcao invalida!\n");
        }
    }while(opcao!=0);

    return 0;

}