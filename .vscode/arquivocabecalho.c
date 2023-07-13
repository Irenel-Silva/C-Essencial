#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include "pilha.h"

// CRIANDO ARQUIVOS DE CABEÇALHO .H  e arquivos de código EM C



int factorial_stack(int num){
    No *remover, *pilha=NULL;
    while (num>1)
    {
        pilha= empilhar(pilha,num);
        num--;
    }
    imprimir_pilha(pilha);

    while (pilha)
    {
        remover= desempilhar(&pilha);
        if(remover){
            num=remover->valor*num;
            //printf("\t%d\n", num);
            free(remover);
        }
    }
    return num;
    
}

int main(){
int numero;
printf("\nDigite um valor maior que zero para o factorial: ");
scanf("%d", &numero);


printf("\tFactorial de %d é: %d\n", numero, factorial_stack(numero));


    return 0;
}



