#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

typedef struct no{
    int valor;
    struct no *proximo;
}No;
//-------------------------------PILHA-------------------------------------
No* empilhar(No *pilha, int num){
    No *novo= malloc(sizeof(No));
    if(novo){
        novo->valor=num;
        novo->proximo=pilha;
        return novo;
    }
    else{
        printf("\n\tErro ao alocar Memoria!\n\t");
        return NULL;
    }
}

No* desempilhar(No **pilha){
    No *remover=NULL;
    if(*pilha){
        remover=*pilha;
        *pilha= remover->proximo;
    }
    else
        printf("\n\tPilha Vazia!\n\t");
    return remover;
}

void Imprimir_pilha(No *pilha){
    printf("\n\t--------Pilha------\n\t");
    while(pilha){
        printf("\t%d\n", pilha->valor);
        pilha=pilha->proximo;
    }
    printf("\n\t--------FIMPilha------\n\t");

}

//-------------------------------PILHA-------------------------------------






//-------------------------------FILA-------------------------------------

void inserir(No **fila, int num){
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
                aux=aux->proximo;
            aux->proximo=novo;

        }
    }
    else
        printf("\n\tErro ao alocar Memoria!\n");
}


No* remover_fila(No **fila){
    No *remover=NULL;
    if(*fila){
        remover= *fila;
        *fila=remover->proximo;

    }
    else
        printf("\n\tFila vazia!\n\t");

    return remover;
}

void Inserir_prioridade(No **fila, int num){
    No *aux;
    No *novo=malloc(sizeof(No));
    if(novo){
        novo->valor=num;
        if(*fila==NULL)
            novo->proximo=*fila;
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
                while(aux->proximo)
                    aux=aux->proximo;
                aux->proximo=novo;
            }
        }

    }
    else
        printf("\n\tErro ao alocar Memoria!\n");
}


void Inserir_2prioridade(No **fila, int num){
    No *aux;
    No *novo=malloc(sizeof(No));
    if(novo){
        novo->valor=num;
        if(*fila){
            novo->proximo=*fila;
            *fila=novo;
        }
        else{
            if(num>79){
                if((*fila)->valor<80){
                    novo->proximo=*fila;
                    *fila=novo;
                }
                else{
                    aux=*fila;
                    while(aux->proximo && aux->proximo->valor>79)
                        aux=aux->proximo;
                    novo->proximo=aux->proximo;
                    aux->proximo=novo;
                }


            }
            else{
                aux=*fila;
                while(aux->proximo)
                    aux=aux->proximo;
                novo->proximo=aux->proximo;
                aux->proximo=novo;

            }
        }
    }
    else
        printf("\n\tErro ao alocar Memoria!\n\t");

}

void Imprimir_Fila(No *fila){
    printf("\n\t-----Fila---------\n\t");
    while(fila){
        printf("%d ", fila->valor);
        fila=fila->proximo;
    }
    printf("\n\t-----FimFila---\n\t");
}


//-------------------------------FILA-------------------------------------

//-------------------------------LISTA----------------------------------------------------------------------------------------------------
// funcções : inserir( inicio, fim, de forma ordenada e no meio da lista); remover elemento da lista, buscar elemento na lista e Imprimir; 

void inseri_InicioLista(No **lista, int num){
    No *novo=malloc(sizeof(No));
    if(novo){
        novo->valor= num;
        novo->proximo=*lista;
        *lista=novo;
    }
    else
        printf("\n\tErro ao alocar Memoria!\n\t");
}


void inserir_FimLista(No **lista, int num){
    No *aux, *novo= malloc(sizeof(No));
    if(novo){
        novo->valor=num;
        novo->proximo=NULL;
        if(*lista==NULL)
            *lista=novo;
        else{
            aux=*lista;
            while(aux->proximo)
                aux=aux->proximo;
            aux->proximo=novo;
        }
    }
    else
        printf("\n\tErro ao alocar Memoria!\n\t");
}


void inserir_MeioLista(No **lista, int num, int antesdovalor){
    No *aux, *novo= malloc(sizeof(No));
    if(novo){
        novo->valor=num;
        if(*lista==NULL){
            novo->proximo=NULL;
            *lista=novo;
        }
        else
            {
                aux=*lista;
                while(aux->proximo && aux->valor!=antesdovalor)
                    aux=aux->proximo;
                if(aux){
                    novo->proximo=aux->proximo;
                    aux->proximo=novo;
                }
            }

    }
}

void inserir_OrdenadaLista(No **lista, int num){
    No *aux, *novo= malloc(sizeof(No));
    if(novo){
        novo->valor=num;
        if(*lista==NULL){
            novo->proximo=*lista;
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
                    aux= aux->proximo;
                if(aux->proximo){
                    novo->proximo=aux->proximo;
                    aux->proximo=novo;
                }
                else{
                    novo->proximo=aux->proximo;
                    aux->proximo= novo;
                }
            }
        }

    }
    else
        printf("\n\tErro ao alocar Memoria!\n\t");
}

No* buscar_lista(No **lista, int num){
    No *aux, *buscar=NULL;
    aux=*lista;
    while(aux && aux->valor!= num)
        aux= aux->proximo;
    if(aux){
        buscar=aux;
    }
    return buscar;

}

No* remover_Elementolista(No **lista, int num){
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
                remover=aux->proximo;
                aux->proximo=remover->proximo;
            }
        }
    }
    else
        printf("\n\tLista vazia!\n\t");
    return remover;
}


void Imprimir_lista(No *lista){
    printf("\n\t-----Lista-------------\n\t");
    while(lista){
        printf("%d ", lista->valor);
        lista=lista->proximo;
    }
    printf("\n\t-----Fim Lista---------\n\t");

}


void copiar_lista(No **lista, No **A){
    No *aux;
    aux= *lista;
    while(aux){
        inseri_InicioLista(A,aux->valor);
        aux= aux->proximo;
    }
}

void ParImpar_lista(No **lista, No **P, No **I){
    No *aux=*lista;
    while(aux){
        if(aux->valor > 0)
        {
            if(aux->valor %2 == 0)
                inseri_InicioLista(P, aux->valor);
            else
                inseri_InicioLista(I, aux->valor);
        }
        aux=aux->proximo;
    }

}
//-------------------------------LISTA----------------------------------------------------------------------------------------------------










int ler_extrutura(){
    int valor;
    printf("\n\tSelecione a estrutura digitando um dos valores correspondente ao menu: \n\t");
    scanf("%d", &valor);
    return valor;
}

int ler_opcao(){
    int valor;
    printf("\n\tDigite o valor da opcao: \n\t");
    scanf("%d", &valor);
    return valor;
}

int ler_elemento(){
    int valor;
    printf("\n\tDigite o elemento a introduzir na estrutura: \n\t");
    scanf("%d", &valor);
    return valor;
}

int ler_elementoIntermedio(){
    int valor;
    printf("\n\tDigite o elemento anterior a inserçao: \n\t");
    scanf("%d", &valor);
    return valor;
}
int main(){
    No *remover, *buscar, *pilha=NULL, *fila=NULL, *lista=NULL, *listaB=NULL, *listaC=NULL, *Par= NULL, *Impar= NULL;
    int opcao, extrutura, elemento, meio;
    do{
        printf("\n\t0- Sair\n\t1- Pilha\n\t2- Fila\n\t3- Lista\n\t");
        extrutura=ler_extrutura();
        switch (extrutura)
        {
            // Pilha
            case 1:
                do{
                    printf("\n\t0- Sair\n\t1- Empilhar\n\t2-Desempilhar\n\t3- Imprimir\n\t");
                    opcao=ler_opcao();
                    switch(opcao){
                        case 1:
                            elemento=ler_elemento();
                            pilha=empilhar(pilha, elemento);
                            break;
                        case 2:
                            remover=desempilhar(&pilha);
                            if(remover){
                                printf("\n\tElemento %d removido com sucesso!\n\t", remover->valor);
                                free(remover);
                            }
                            break;
                        case 3:
                            Imprimir_pilha(pilha);
                            break;
                        default:
                            if(opcao!=0)
                                printf("\n\tValor invalido!");
                            break;
                            
                    }

                }while(opcao!=0);

                break;
            //Fila
            case 2:
                do{
                    printf("\n\t0- Sair\n\t1- Inserir\n\t2- Inserir com prioridade\n\t3- Remover\n\t4- Imprimir\n\t");
                    opcao=ler_opcao();
                    switch(opcao){
                        case 1:
                            elemento=ler_elemento();
                            inserir(&fila, elemento);
                            break;
                        case 2:
                            elemento=ler_elemento();
                            if(elemento>79)
                                Inserir_2prioridade(&fila, elemento);
                            else
                                Inserir_prioridade(&fila, elemento);
                            break;
                        case 3:
                            remover=remover_fila(&fila);
                            if(remover){
                                printf("\n\tElemento %d removido com sucesso da fila!\n\t", remover->valor);
                                free(remover);
                            }
                            break;
                        case 4:
                            Imprimir_Fila(fila);
                            break;
                        default:
                            if(opcao!=0)
                                printf("\n\tValor invalido!");
                            break;
                            
                    }

                }while(opcao!=0);
                break;
            //Lista
            case 3:
                do{
                    printf("\n\t0- Sair\n\t1- Inserir no Inicio\n\t2- Inserir no fim\n\t3- Inserir no meio\n\t4- Inserir ordenado \n\t5- Buscar\n\t6- Remover \n\t7- Copiar Listas\n\t8- Dividir Lista em par ou Impar\n\t9- Imprimir\n\t");
                    opcao=ler_opcao();
                    switch(opcao){
                        case 1:
                            elemento=ler_elemento();
                            inseri_InicioLista(&lista, elemento);
                            //segundo para o exemplo da copia de lista
                            elemento=ler_elemento();
                            inseri_InicioLista(&listaB, elemento);
                            break;
                        case 2:
                            elemento=ler_elemento();
                            inserir_FimLista(&lista, elemento);
                            break;
                        case 3:
                            meio=ler_elementoIntermedio();
                            elemento=ler_elemento();
                           // inserir_MeioLista(&lista, elemento, meio);
                           // segundo exemplo copia de lista
                            inserir_MeioLista(&listaB, elemento, meio);
                            break;
                        case 4:
                            elemento=ler_elemento();
                            inserir_OrdenadaLista(&lista, elemento);
                            break;
                        case 5:
                            elemento=ler_elemento();
                            buscar= buscar_lista(&lista, elemento);
                            if(buscar)
                                printf("\n\tElemento %d encontrado com sucesso!\n\t", buscar->valor);
                            else
                                printf("\n\tElemento não existe na lista!\n\t");
                            break;
                        case 6:
                            elemento=ler_elemento();
                            remover=remover_Elementolista(&listaC, elemento);
                            if(remover){
                                printf("\n\tElemento %d removido com sucesso!\n\t", remover->valor);
                                free(remover);

                            }
                            break;
                        case 7:
                            copiar_lista(&lista, &listaC);
                            copiar_lista(&listaB, &listaC);
                            break;
                        case 8:
                            ParImpar_lista(&lista, &Par, &Impar);
                            printf("\n\t Divisão realizada com sucesso!\n");
                            ParImpar_lista(&listaB, &Par, &Impar);
                            printf("\n\t Divisão realizada com sucesso!\n");
                            break;
                        case 9:
                            printf("\n\tLista A:\n");
                            Imprimir_lista(lista);
                            printf("\n\tLista B:\n");
                            Imprimir_lista(listaB);
                            printf("\n\tLista C:\n");
                            Imprimir_lista(listaC);
                            printf("\n\tLista Par:\n");
                            Imprimir_lista(Par);
                            printf("\n\tLista Impar:\n");
                            Imprimir_lista(Impar);
                            break;
                        default:
                            if(opcao!=0)
                                printf("\n\tValor invalido!");
                            break;
                            
                    }

                }while(opcao!=0);
                break;
            default:
                if(extrutura!=0)
                    printf("\n\tValor invalido!");
                break;
        }

    }while(extrutura!=0);



    return 0;
}