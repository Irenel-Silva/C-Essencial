#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

typedef struct no{
    int valor;
    struct no *proximo;
}No;

// Empilhar
No* empilhar(No *pilha, int num);

// Desempilhar

No* desempilhar(No **pilha);



//IMprimir Pilha

void imprimir_pilha(No *pilha);



#endif // PILHA_H_INCLUDED