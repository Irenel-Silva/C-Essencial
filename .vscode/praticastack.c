#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

typedef struct{
    int dia, mes, ano;
}Data;

typedef struct{
    char nome[25];
    char genero[10];
    Data data;
}Pessoa;

typedef struct no{
    Pessoa p;
    struct no *proximo;   
}No;

Pessoa ler_pessoa(){
    Pessoa p;
    printf("\nDigite O Nome, Genero e data de Nascimento\n");
    scanf("%25[^\n]", p.nome);
    getchar();
    scanf("%10[^\n]", p.genero);
    getchar();
    scanf("%2d%2d%4d", &p.data.dia, &p.data.mes, &p.data.ano);
    return p;
}

void imprimir_pessoa(Pessoa p){
    printf("\nNome: %s\nGenero: %s\nData: %d/%d/%d\n", p.nome, p.genero, p.data.dia, p.data.mes, p.data.ano);
}

// Empilhar

No* empilhar(No *topo){
    No *novo= malloc(sizeof(No));
    if(novo){
        novo->p= ler_pessoa();
        novo->proximo= topo;
        return novo;
    }
    else
        printf("\nErro ao alocar Memoria\n");
    return NULL;
}

// Desempilhar
No* desempilhar(No **topo){
    if(*topo!=NULL){
        No *remover= *topo;
        *topo= remover->proximo;
        return remover;
    }
    else
        printf("\n Pilha Vazia!\n");
    return NULL;
}

// Imprimir Pilha
void imprimir_pilha(No *topo){
    printf("\n----------Pilha----------\n");
    while(topo){
        imprimir_pessoa(topo->p);
        topo= topo->proximo;
    }
    printf("\n----------FIMPilha----------\n");
}


// Segunda Forma
typedef struct{
    No *topo;
    int tam;
}Pilha;

//Inicializar Pilha
void criar_pilha(Pilha *p){
    p->topo=NULL;
    p->tam=0;
}
// Empilhar 
void empilhar_pilha(Pilha *p){
    No *novo= malloc(sizeof(No));
    if(novo){
        novo->p=ler_pessoa();
        novo->proximo=p->topo;
        p->topo=novo;
        p->tam++;
    }
    else
        printf("\nErro ao alocar memoria\n");
}
// Desempilhar
No* Desempilhar(Pilha *p){
    if(p->topo!= NULL){
        No *remover= p->topo;
        p->topo=remover->proximo;
        p->tam--;
        return remover;
    }
    else
        printf("\nPilha Vazia!\n");
    return NULL;
}

// Imprimir Pilha Metodo 2

void print_pilha(Pilha *p){
    No *aux;
    aux= p->topo;
    printf("\n-----------PilhaM2 %d-----------\n", p->tam);
    while(aux){
        imprimir_pessoa(aux->p);
        aux= aux->proximo;
    }

    printf("\n-----------FIMPilhaM2-----------\n");
}

int main(){
   // No *remover, *topo=NULL;
   Pilha p;
   No *remover;
   criar_pilha(&p);
    int opcao;
    do{
        printf("\n1- Empilhar\n2- Desempilhar\n3- Imprimir\n0- Sair\n");
        scanf("%d", &opcao);
        getchar();
        switch(opcao){
            case 1:
                //topo= empilhar(topo);
                empilhar_pilha(&p);
                break;
            case 2:
                //remover= desempilhar(&topo);
                remover= Desempilhar(&p);
                if(remover){
                    printf("\nElemento removido sucesso!\n");
                    imprimir_pessoa(remover->p);
                    free(remover);
                }
                else
                    printf("\nSem Elemento a remover!\n");
                break;
            case 3:
                //imprimir_pilha(topo);
                print_pilha(&p);
            break;
            default:
                if(opcao!=0)
                    printf("\nValor invalido!\n");
        }
    }while(opcao!=0);
    
    return 0;
}