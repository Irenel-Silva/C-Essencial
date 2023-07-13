#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

// Lista circular encadeada todo o aprendizado

typedef struct no{
    int valor;
    struct no *proximo;
    //struct no *anterior;
}No;

typedef struct{
    struct no *inicio;
    struct no *fim;
    int tam;
}Lista;

void criar_lista(Lista *lista){
    //Lista *lista;
    lista->inicio=NULL;
    lista->fim=NULL;
    lista->tam= 0;
}

// Inserir no Inicio Da lista Circular
void Inserir_InicioLista(Lista *lista, int numero){
    No *novo= malloc(sizeof(No));
    if(novo){
        novo->valor=numero;
        novo->proximo=lista->inicio;
        lista->inicio= novo;
        if(lista->fim==NULL)
        {
            lista->fim = novo;
        }
        else{
            lista->fim->proximo= lista->inicio;
        }
        
        lista->tam++;


    }
    else
        printf("\n\t Erro ao alocar Memoria!\n\t");
}


// Inserir no fim da Lista circular

void Inserir_FimLista(Lista *lista, int numero){
    No *aux, *novo=malloc(sizeof(No));

    if(novo){
        novo->valor=numero;
        //novo->proximo=NULL;
        if(lista->inicio==NULL){
            lista->inicio=novo;
            lista->fim=novo;
            lista->fim->proximo=lista->inicio;
        }
        else{
            lista->fim->proximo=novo;
            lista->fim=novo;
            //lista->fim->proximo=novo;// serve
            novo->proximo=lista->inicio;// serve e resultam na mesma solução
        }
        lista->tam++;

    }
    else
        printf("\n\tErro ao alocar Memoria!\n\t");
}

void inserir_ordenadoLista(Lista *lista, int numero){
    No *aux, *novo=malloc(sizeof(No));

    if(novo){
        novo->valor=numero;
        if(lista->inicio==NULL)
        {
            Inserir_InicioLista(lista, numero);
        }
        else{
            if(lista->inicio->valor > novo->valor){
                Inserir_InicioLista(lista, numero);
            }
            else{
                aux=lista->inicio;
                while(aux->proximo!= lista->inicio && novo->valor > aux->proximo->valor)
                    aux=aux->proximo;
                if(aux->proximo == lista->inicio){
                    Inserir_FimLista(lista, numero);
                }
                else{
                    novo->proximo= aux->proximo;
                    aux->proximo=novo;
                    lista->tam++;
                }
                
            }

        }

    }
    else
        printf("\n\tErro ao alocar Memoria!\n\t");

}


No* remover_lista(Lista *lista, int numero){
    No *aux, *remover=NULL;
    if(lista->inicio){
        if(lista->inicio==lista->fim && lista->inicio->valor==numero){// unico no na lista a condicao trata
            remover=lista->inicio;
            lista->inicio=NULL;
            lista->fim=NULL;
            lista->tam--;
        }
        else{
            if(lista->inicio->valor==numero){
                remover=lista->inicio;
                lista->inicio=remover->proximo;
                lista->fim->proximo=lista->inicio;
                lista->tam--;
            }
            else
            {
                aux=lista->inicio;
                while(aux->proximo!=lista->inicio && aux->proximo->valor!=numero)
                    aux=aux->proximo;
                if(aux->proximo->valor==numero){
                    if(aux->proximo==lista->fim){
                        remover=aux->proximo;
                        aux->proximo=remover->proximo;
                        lista->fim=aux;
                    }
                    else{
                        remover=aux->proximo;
                        aux->proximo=remover->proximo;
                    }
                    lista->tam--;

                }

            }
        }

    }
    return remover;
}

No* buscar_lista(Lista *lista, int numero){
    No *aux;
    aux=lista->inicio;
    if(aux){
        do{
            if(aux->valor==numero)
                return aux;
            aux=aux->proximo;
        }while(aux!= lista->inicio);
    }
    return NULL;
}


void imprimir_lista(Lista lista){
    No *imprimir=lista.inicio;
    printf("\n\tLista tam %d \n\t", lista.tam);
    if(imprimir){
        do{
            printf("%d ", imprimir->valor);
            imprimir= imprimir->proximo;
        }while(imprimir!=lista.inicio);
        printf("\n\t Inicio da lista: %d \n\t", imprimir->valor);
    }
    printf("\n\tFim Lista-----------\n\t");
    printf("\n\t\n\t");
}

int main(){
    int opcao, valor, anterior;
    Lista lista;
    No *remover;
    criar_lista(&lista);
    do
    {
       printf("\n\t0- sair\n\t1- Inserir Inicio\n\t2- Inserir no fim\n\t3- Inserir Ordenado\n\t4- Buscar na lista\n\t5- Remover\n\t6- Imprimir Lista\n\t");
        scanf("%d", &opcao);
        getchar();
        switch(opcao){
            case 1:
                printf("\n\tDigite o valor a inserir na lista\n\t");
                scanf("%d", &valor);
                Inserir_InicioLista(&lista, valor);
                break;
            case 2:
                printf("\n\tDigite o valor a inserir na lista\n\t");
                scanf("%d", &valor);
                Inserir_FimLista(&lista, valor);
                break;
            case 3:
                /*printf("\n\tDigite a posição anterior a inserção: \n\t");
                scanf("%d", &anterior);
                getchar();*/
                printf("\n\tDigite o valor a inserir na lista\n\t");
                scanf("%d", &valor);
                inserir_ordenadoLista(&lista,valor);
                break;
            case 4:
                printf("\n\tDigite o valor a pesquisar na lista\n\t");
                scanf("%d", &valor);
                remover= buscar_lista(&lista, valor);
                if(remover){
                    printf("\n\tValor %d encontrado com sucesso!\n\t", remover->valor);
                }
                else
                    printf("\n\tValor inexistente!\n\t");

                break;
            case 5:
                printf("\n\tDigite o valor a remover da lista\n\t");
                scanf("%d", &valor);
                remover= remover_lista(&lista, valor);
                if(remover){
                    printf("\n\tValor %d removido com sucesso!\n\t", remover->valor);
                    free(remover);
                }
                else
                    printf("\n\tValor inexistente!\n\t");
                break;
            case 6:
                imprimir_lista(lista);
                break;

            default:
                if(opcao!=0){
                    printf("\n\tOpção invalida!\n\t");
                }
                break;
        }
    } while (opcao!=0);
    

    return 0;
}