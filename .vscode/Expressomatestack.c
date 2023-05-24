#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
// Verificar se uma expressão matemática está mal formada com PILHA em c
/*
    3*[(5-2)/5] ->certo
    3*[(5-2)/5 ->errada
*/


typedef struct no{
    char caracter;
    struct no *proximo;

}No;

No* empilhar(No *pilha, char expr){
    No *novo= malloc(sizeof(No));
    if(novo){
        novo->caracter=expr;
        novo->proximo= pilha;
        return novo;
    }
    else
        printf("\nErro ao alocar memoria!\n");
    return NULL;
}

// desempilhar

No* desempilhar(No **pilha){
    No *remover;
    if(*pilha){
        remover=*pilha;
        *pilha=remover->proximo;
        return remover;
    }
    else
        printf("\nPilha vazia\n");
    return NULL;
}


// IMprimir Pilha

void imprimir_pilha(No *pilha){
    printf("\n\tPilha\n");
    while(pilha){
        printf("\t%c\n",pilha->caracter);
        pilha= pilha->proximo;
    }
    printf("\tFim Pilha\n\n");
}
// f- fechamento e d- desempilhar
int forma_pare(char f, char d){
    switch (f)
    {
    
    case ')':
        if(d=='(')
            return 1;// bem formada
        else
            return 0;// Mal formada
        break;
    case ']':
        if(d=='[')
            return 1;
        else
            return 0;
        break;
    case '}':
        if(d=='{')
            return 1;
        else
            return 0;
        break;
    }
}
int identificar_formacao(char x[]){
    No *remover, *pilha=NULL;
    int i=0;
    while(x[i]!='\0'){
        //Empilhar
        if(x[i]=='[' || x[i]=='(' || x[i]=='{'){
            pilha=empilhar(pilha,x[i]);
            imprimir_pilha(pilha);
        }
        else
            if(x[i]==']'||x[i]==')' || x[i]=='}'){
                remover=desempilhar(&pilha);
                if(remover){
                    //printf("\tExpressão\n");
                    if(forma_pare(x[i], remover->caracter)==0){
                        printf("\tEXPRESSÃO MAL FORMADA!\n");
                        return 1;
                    } 
                    free(remover);
                }
            }
            i++;
    }
    imprimir_pilha(pilha);
    if(pilha){
        printf( "\texpressão mal formada!\n");
        return 1;
    }
    else{
        printf("\texpressão bem formada!\n");
        return 0;
    }
}

int main(){
    char expre[50];
    printf("\tDigite uma expessao:  ");
    scanf("%49[^\n]", expre);
    printf("\nExpressão: %s\nRetorno: %d\n", expre, identificar_formacao(expre));

    return 0;
}