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
        printf("\n\tvalor %d armazenado\n", novo->valor);
        return novo;
    }else{
        printf("\n\tErro ao alocar memoria!\n");
        return NULL;
        }

}

No* desempilhar_pilha(No **pilha){
    No *remover=NULL;
    if(*pilha){
        remover=*pilha;
        *pilha=remover->proximo;
    }
    else
        printf("\n\tPIlha Vazia\n");
    return NULL;
}

void imprimir_pilha(No *pilha){
    printf("\n\t-----Pilha-----\n\t");
    while(pilha){
        printf("%d\n\t",pilha->valor);
        pilha= pilha->proximo;
    }
    printf("\n\t-----FIm Pilha-----\n");
}

void liberar_nopilha(No *pilha){
    printf("\n\tElemento %d Removido!\n", pilha->valor);
    //free(pilha);
}

int ler_elementoPilha(){
    int num;
    printf("\n\tDigite o Elemento para pilha: \n\t");
    scanf("%d", &num);
    return num;
}

int menu_pilha(){
    int opcao;
    printf("\n\t0- Sair\n\t1- Empilhar\n\t2- Desempilhar\n\t3- Imprimir\n\t");
    scanf("%d", &opcao);
    return opcao;
}
void operacoes_pilha(int opcao){
    No *rmve;
    No *pilha=NULL;
    int num;
    switch(opcao){
        case 1:
            num=ler_elementoPilha();
            pilha=empilhar_pilha(pilha,num);
            break;
        case 2:
            rmve=desempilhar_pilha(&pilha);
            if(rmve){
               liberar_nopilha(rmve); 
               free(rmve);
            }
            break;
        case 3: 
            imprimir_pilha(pilha);
            break;
        default:
            if(opcao!=0)
                printf("\n\t Opcao Invalida!\n");
            break;
    }

}
void execucao_pilha(void){
    No *pilha=NULL, *rmve;
    int opcao;
    int num;
    do{
        opcao=menu_pilha();
        //operacoes_pilha(opcao);   
        switch(opcao){
            case 1:
                num=ler_elementoPilha();
                pilha=empilhar_pilha(pilha,num);
                break;
            case 2:
                rmve=desempilhar_pilha(&pilha);
                if(rmve){
                    liberar_nopilha(rmve); 
                }
                break;
            case 3: 
                imprimir_pilha(pilha);
                break;
            default:
                if(opcao!=0)
                    printf("\n\t Opcao Invalida!\n");
                break;
        }
    }while(opcao!=0);

}
int main(){
    execucao_pilha();


 return 0;   
}

