#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>


//Resolver expressão em notação pós-fixa (notação polonesa reversa)



typedef struct no{
    float valor;
    //char letra;
    struct no *proximo;
}No;

No *empilhar(No *pilha, float num){
    No *novo= malloc(sizeof(No));
    if (novo)
    {
        novo->valor=num;
        novo->proximo=pilha;
        return novo;
    }
    else{
        printf("\n\tErro ao alocar memoria!\n");
        return NULL; 
    }  
}


No *desempilhar(No **pilha){
    No *remover= NULL;
     if(*pilha)
    {
        remover= *pilha;
        *pilha=remover->proximo;
    }
    else
        printf("\n\tPilha Vazia\n");
    return remover;  
}


void imprimir_pilha(No *pilha){
    printf("\n\tPilha\n");
    while(pilha){
        printf("%2.f", pilha->valor);
        pilha= pilha->proximo;
    }
    printf("\n\tFim Pilha\n");
}

float definir_operacao(float n1, float n2, char operacao){
    float r;
    switch (operacao)
    {
    case '+':
        r= n1 +n2;
        break;
    case '-':
        r= n1-n2;
        break;
    case '*':
        r= n1*n2;
        break;
    case '/':
        r= n1/n2;
        break;
    default:
        r=0.0;
        break;
    }
    return r;
}
float polonesa_funcao(char x[]){ // (51+13*12)  51 13 12 * +
    No *remover, *pilha=NULL;
    No *n1, *n2;
    char *pt;
    float num;
    pt= strtok(x, " ");
    int i=0;
    while(pt){
        if(pt[0]=='+' || pt[0]=='-' || pt[0]=='*' ||pt[0]=='/'){
            n1=desempilhar(&pilha);
            n2=desempilhar(&pilha);
            num= definir_operacao(n2->valor,n1->valor,pt[0]);
            pilha= empilhar(pilha, num);
            free(n1);
            free(n2);
        }
        else{
            num= strtol(pt, NULL,10);
            pilha=empilhar(pilha, num);
        }
        pt=strtok(NULL, " ");
    }
    n1=desempilhar(&pilha);
    num=n1->valor;
    free(n1);

    return num;
}

int main(){
    /*
        51 13 12 * +   =207
        5 3 2 + * 4 / 6 -    =0,25
        5 3 + 2 4 * + 6 7 * 1 *  -    =-26
        5 3 2 4 6 7 1 + * + * + *    = 535
    
    */
    char expre[50]={"5 3 2 4 6 7 1 + * + * + * "};
    printf("\nResultado de %s:\t", expre);
    printf("%.2f\n ",polonesa_funcao(expre));
    return 0;
}