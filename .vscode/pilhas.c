#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>


typedef struct 
{
    int dia;
    int mes;
    int ano;

}Data;

typedef struct 
{
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
    printf("Digite o nome, genero e a Data de nascimento em dd mm aaaa:\n");
    /*scanf("%25[^\n]\n%d%d%d", p.nome, &p.data.dia, &p.data.mes, &p.data.ano);*/
    scanf("%25[^\n]", p.nome);
    getchar();
    scanf("%10[^\n]", p.genero);
    getchar();
    scanf("%d%d%d",&p.data.dia, &p.data.mes, &p.data.ano);
    return p;
}
void imprimir_pessoa(Pessoa p){
    printf("\nNome: %s\nGenero: %s\nData: %2d/%2d/%4d\n", p.nome,p.genero, p.data.dia, p.data.mes, p.data.ano);
}


// Funçao para empilhar (Push) \nGenero: %c     p.genero

No* empilhar(No *topo){
    No *novo;
    novo=malloc(sizeof(No));
    if(novo){
        novo->p=ler_pessoa();
        novo->proximo=topo;
        return novo;
    }
    else
        printf("\nErro ao alocar a memoria!!");
    return NULL;   
}

// Desempilhar o Ponteiro 
No *desempilhar(No **topo){
    if(*topo !=NULL){
        No *remover= *topo;
        *topo= remover->proximo;
        return remover;
    }
    else
        printf("\npilha vazia!\n");
    return NULL;   
}

// Imprimir Elementos da Pilha      
void imprimir_pilha(No *topo){
    printf("\n----------Pilha----------\n");
    while(topo){
        imprimir_pessoa(topo->p);
        topo= topo->proximo;

    }
    printf("\n----------FIM da Pilha----------\n");
}


// Segunda versão para a estrutura de dados dinâmica do tipo PILHA 

//Usar a estr no para ligar os nos/elementos da pilha a seguir usar, reutilizar o ler_pessoa e o imprimir pessoa e o  imprimir pilha
typedef struct {
    No *topo;
    int tam;
}Pilha;

void criar_pilha(Pilha *pi){
    pi->topo=NULL;
    pi->tam=0;
}

void empilha(Pilha *p){
    No *novo=malloc(sizeof(No));
    if (novo)
    {
        novo->p=ler_pessoa();
        novo->proximo=p->topo;
        p->topo= novo;
        p->tam++;
    }
    else{
        printf("\n Erro ao alocar memoria\n");
    }
}


No *Desempilhar(Pilha *p){
    if(p->topo!=NULL){
        No *remover= p->topo;
        p->topo= remover->proximo;
        p->tam--;
        return remover;
    }
    else
        printf("\npilha vazia!\n");
    return NULL;   
}
void imprimir_pilhaNova(Pilha *p){
    No *aux= p->topo;
    printf("\n----------Pilha Tam: %d ---------\n", p->tam);
    while(aux){
        imprimir_pessoa(aux->p);
        aux= aux->proximo;

    }
    printf("\n----------FIM da Pilha----------\n");
}


int main(){
No *topo= NULL, *remover;
// No *remover; Pilha *p;
/*
    criar_pilha(&p); 
*/

//Factorial com Pilha


int opcao;
do{
    printf("\n0 - Sair\n1 - Empilhar(Push)\n2 - Desempilhar(Pop)\n3 - Imprimir\n");
    scanf("%d", &opcao);
    getchar();
    switch (opcao)
    {
    case 1:
        topo= empilhar(topo);
        //empilha(&p);
        
        break;
    case 2:
        remover= desempilhar(&topo);
        //remover=Desempilhar(&p);
        if (remover)
        {
            printf("\nElemento removido com sucesso!\n");
            imprimir_pessoa(remover->p);
            free(remover);
        }
        else
        printf("\nSem no a remover.\n");
        
        break;
    case 3:
        imprimir_pilha(topo);
        //imprimir_pilhaNova(&p);
        break;
    
    default:
        if(opcao!=0)
         printf("\nOpcção inexistente\n");
        break;
    }
}while(opcao!= 0);




    return 0;
}