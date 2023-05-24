#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

// fazer uma função para inverter uma string
void mudarpalavra(char palavra[]){
    int i, aux,fim, tam=strlen(palavra);
    fim=tam-1;
    for (i = 0; i < tam/2; i++)
    {
        aux=palavra[i];
        palavra[i]=palavra[fim];
        palavra[fim]=aux;
        fim--;
        
    }   
}

// segunda forma inverção pela função
char* mudarpalavra2(char palavra[]){
    int i, aux,fim, tam=strlen(palavra);
    char *novo=calloc(tam+1, sizeof(char));
    fim=tam-1;
    for (i = 0; i < tam; i++)
    {
        novo[i]=palavra[fim];
        fim--;
        
    }   
    novo[i]='\0';
    return novo;
}


//Ponteiro para struct
typedef struct
{
    int dia, mes, ano;
}Data;

void printData(Data *x){
    printf("%d/%d/%d\n", x->dia, x->mes, x->ano);
}

 //Ponteiro como parâmetro em uma função
void  printponteiro(int *k){
    printf(" Valor do a na função %d\n", *k);
    *k=20;
}

//Vetores lindando com o conceito de ponteiros
void printv(int vetor[], int tam, int vantigo[]){
    for (int i = 0; i <tam; i++)
    {
        vantigo[i]=vetor[i];
        vetor[i]=vetor[i]*2;
    }
    
}

void printvp(int vetor[], int tam){
    for (int i = 0; i < tam; i++)
    {
        printf("%d ", vetor[i]);
       
    }
     printf("\n");
}

void printvantigo(int vantigo[], int tam){
    printf("Imprimindo vetor antigo\n");
    for (int i = 0; i < tam; i++)
    {
        printf("%d ", vantigo[i]);
        
    }
    printf("\n");    
}

// Aritmetica de ponteiro
void imprimir(int vet[], int tam){
    for (int i = 0; i < tam; i++)
    {
        printf("%d ", *(vet +i ));
    }
    printf("\n");  
}

// Maior e o menor elemento de um vector com ponteiros
void printMmevetor(int vetor[], int tam, int *M, int *m){

    for (int i = 0; i <tam; i++)
    {
        if(vetor[i]> *M){
            *M= vetor[i];
        }
        if (vetor[i]<*m)
        {
            *m=vetor[i];
        }   
    } 
}

// Maior e o menor elemento de um vector com ponteiros usando aritmetica de ponteiro
void MaiorMenor(int *vet, int tam, int *M, int*m){
    *M= *vet;// segundo a aritmetica de ponteiro aponta para o conteudo do primeiro endereço no vetor
    *m= *vet;// segundo a aritmetica de ponteiro aponta para o conteudo do primeiro endereço no vetor
    for (int i = 0; i < tam; i++)
    {
        if(*m>*(vet+i))
            *m=*(vet+i);
        if(*M<*(vet+i))
            *M=*(vet+i);
    }
    
}

// Trocar o conteúdo de duas variáveis por meio de ponteiros
void Troca(int *m, int *n){
    int cop;
    cop=*m;
    *m=*n;
    *n= cop;

   
}

//Imprimir endereço e conteúdo de cada posição de um vetor
void ECvetor(int *vet, int tam){
    for (int i = 0; i < tam; i++)
    {
       printf("O endereço do vetor na posição %d é:%p\t e o conteudo é:%d\n",i, (vet+i), *(vet+i));
    }
}

//Como realizar multiplicações com ponteiros de ponteiros
void DTQ(int *s, int **t,int ***u, int v){
  
   s=&v;
   t=&s;
   u=&t;

   printf("Dobro: %d\n", *s*2);
   printf("Triplo: %d\n", **t*3);
   printf("Quadruplo: %d\n", ***u*4);

}

int stringcopia(char *destino, char *origem){
    int i=0;
    while (*(origem+i) !='\0')
    {
        *(destino +i)=*(origem +i);
        i++;
    }
    *(destino+i)='\0';
    return i;
}


void calculoMatriz(int **matriz,int *f,int *g, int *li, int *co){
    int l, c, somal, somac;
    
    printf("Digite o valor da Linha: ");
    scanf("%d", &l);
    printf("Digite o valor da coluna: ");
    scanf("%d", &c);
    *li=l;
    *co=c;
    matriz=malloc(l*sizeof(int*));
    for ( int i = 0; i < l; i++)
        matriz[i]=malloc(c*sizeof(int));
    
    srand(time(0));

    for (int i = 0; i < l; i++)
    {
        somal=0;
        for (int j= 0; j < c; j++){
            matriz[i][j]=rand()%100;
            somal+=matriz[i][j];
        }
        f[i]=somal;
    }
    for (int j = 0; j < c; j++)
    {
        somac=0;
        for (int i= 0; i < l; i++){
            matriz[i][j]=rand()%100;
            somac+=matriz[i][j];
        }
        g[j]=somac;
    }
    printf("Matriz Dinâmica:\n");
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%3d ", matriz[i][j]);
        }
        printf("\n");  
    }
    printf("O Total de cada linha e:\n");
    for (int i = 0; i < l; i++)
    {
        printf("Linha %d\tTotal: %d\n", i, f[i]);
    }
    printf("O Total de cada Coluna e:\n");
    for (int i = 0; i < c; i++)
    {
        printf("Coluna %d\tTotal: %d\n", i, g[i]);
    }
}

void printMatriz(int **matriz, int *f,int *g,int li, int co){
    printf("linhas: %d\tcolunas: %d\n", li, co);
    printf("Matriz Dinâmica:\n");
    for (int i = 0; i < li; i++)
    {
        for (int j = 0; j < co; j++)
        {
            printf("%d", matriz[i][j]);
        }
        printf("\n");  
    }
    printf("O Total de cada linha e:\n");
    for (int i = 0; i < li; i++)
    {
        printf("Linha %d\tTotal: %d\n", i, f[i]);
    }
    printf("O Total de cada Coluna e:\n");
    for (int i = 0; i < co; i++)
    {
        printf("Coluna %d\tTotal: %d\n", i, g[i]);
    }
}
void Invertestring(char *palavra,int tamanho ){
    char invertida[tamanho];
    printf("palavra real:\n");
    for (int i = 0; i < tamanho; i++)
    {
        printf("%c", palavra[i]);
    }
    printf("\n");
    int j=0;
    for (int i = tamanho-1; i >=0; i--)
    {
        invertida[j]=palavra[i];
        j++;
    }
    invertida[j]='\0';   
    //printf("%d\n", j);
    printf("palavra Invertida:\n");
    for (int i = 0; i < tamanho; i++)
    {
        printf("%c", invertida[i]);
    }
    printf("\n");
    
}
int main(){
    
    int a=6;
    int *p;
    int **c;
    int ***d;
    int maior=0, menor=1000, M, m; 
    p=&a;
    c=&p;
    int vet[]= {45, 89, 25,14, 78,32, 28,55,42};
    int tam= sizeof(vet)/sizeof(vet[0]);
    int vold[tam];
    printf("valor do tamanho do vetor: %d\n", tam);

    char palavra[100];
    char destino[25], origem[25]= {"Bom dia."};

    //Ponteiro como parâmetro em uma função
    printponteiro(&a);
    printf(" Valor do a fora da função: %d\n", a);

    //Vetores lindando com o conceito de ponteiros
    /*printvp(vet, tam);
    printv(vet, tam, vold);
    printvp(vet, tam);
    printvantigo(vold, tam);*/

    // Aritmetica de ponteiro
    //imprimir(vet, tam);

    // Ponteiro para struct

    Data data;
    Data *l;
    data.dia= 29;
    data.mes=4;
    data.ano=2022;
    l= &data;
    /*printf("data: %p\t p: %p\n", &data, l);

    printData(l);

    printf("%d/%d/%d\n", data.dia, data.mes, data.ano);*/

    // Ponteiro para ponteiro
    /*printf("Tamanho do ponteiro: %d\n",  sizeof(p));
    printf("Endereço de a: %p\t conteudo de a:%d\n", &a, a);
    printf("Endereço de p: %p\t conteudo de p:%p\n", &p, p);
    printf("conteudo apontado por p: %d\n", *p);
    printf("Endereço de c: %p\t conteudo de c:%p\n", &c, c);
    printf("conteudo apontado por c: %d\n", **c);*/

    // Maior e o menor elemento de um vector com ponteiros
    /*printMmevetor(vet, tam, &maior, &menor);
    printf("O Maior valor é:%d\t O Menor valor é: %d\n", maior, menor);
    MaiorMenor(vet, tam, &M, &m);
    printf("O Maior valor é:%d\t O Menor valor é: %d\n", M, m);*/

    // Trocar o conteúdo de duas variáveis por meio de ponteiros
    /*printf("Valores antes da Troca: a:%d\t menor:%d\n", a, menor);
    Troca(&a,&menor);
    printf("Valores depois da Troca: a:%d\t menor:%d\n", a, menor);*/

    //Imprimir endereço e conteúdo de cada posição de um vetor
        //ECvetor(vet, tam);

    //Como realizar multiplicações com ponteiros de ponteiros
    //DTQ(p,c,d, a);

    //função strcpy para fazer a cópia de uma string usando ponteiros
    /*printf("tamanho: %d\n", stringcopia(destino, origem));
    printf("Destino: %s\n", destino);*/

    //Alocação dinâmica de memória com a função MALLOC
    /*int *x;
    x=malloc(sizeof(int));
    // verifica se alocou a memoria
    if(x){
        printf("Memoria alocada com sucesso!\n");
        printf("x: %d\n", *x);
        *x=50;
        printf("x: %d\n", *x);

    }
    else
    {
        printf("Erro ao alocar memoria!\n");
    }*/
    
    //Alocação dinâmica de memória com a função CALLOC
    int *x;
    /*x=calloc(1, sizeof(int));
    // verifica se alocou a memoria
    if(x){
        printf("Memoria alocada com sucesso!\n");
        printf("x: %d\n", *x);
        *x=50;
        printf("x: %d\n", *x);

    }
    else
    {
        printf("Erro ao alocar memoria!\n");
    }*/

    //alocar um vetor dinâmico na linguagem C
    /*int *ve, tama;
    printf("Digite o tamanho do vector: ");
    scanf("%d", &tama);
    srand(time(NULL)); //Poderia ser tambem  srand(time(0));
    ve= malloc(tama * sizeof(int));
    if(ve){
        printf("Alocado com sucesso!\n");
        for (int i = 0; i < tama; i++)
        {
            *(ve+i)=rand()%100;
        }
        for (int i = 0; i < tama; i++)
        {
            printf("%d ", *(ve +i));
            
        }
        printf("\n");
        

    }
    else{
        printf("Erro ao alocar!\n");
    }*/


    //aumentar o tamanho de um vetor com a função realloc

    /*int *ve, tama;
    printf("Digite o tamanho do vector: ");
    scanf("%d", &tama);
    srand(time(NULL)); //Poderia ser tambem  srand(time(0));
    ve= malloc(tama * sizeof(int));
    if(ve){
        printf("Alocado com sucesso!\n");
        for (int i = 0; i < tama; i++)
        {
            *(ve+i)=rand()%100;
        }
        for (int i = 0; i < tama; i++)
        {
            printf("%d ", *(ve +i));
            
        }
        printf("\n");
        printf("Digite o novo tamanho do vector: ");
        scanf("%d", &tama);
        ve=realloc(ve, tama);
        for (int i = 0; i < tama; i++)
        {
            if(*(ve +i)==0){
                *(ve +i)= rand()%100;
            }
           
            
        }
        printf("\n vetor realocado:\n");
        for (int i = 0; i < tama; i++)
        {
            printf("%d ", *(ve +i));
            
        }
        printf("\n");
        

    }
    else{
        printf("Erro ao alocar!\n");
    }*/

    // Liberar memória alocada dinamicamente com a função free()
    /*int *ve, tama;
    printf("Digite o tamanho do vector: ");
    scanf("%d", &tama);
    srand(time(NULL)); //Poderia ser tambem  srand(time(0));
    ve= malloc(tama * sizeof(int));
    if(ve){
        printf("Alocado com sucesso!\n");
        for (int i = 0; i < tama; i++)
        {
            *(ve+i)=rand()%100;
        }
        for (int i = 0; i < tama; i++)
        {
            printf("%d ", *(ve +i));
            
        }
        printf("\n");
        printf("Digite o novo tamanho do vector: ");
        scanf("%d", &tama);
        ve=realloc(ve, tama);
        for (int i = 0; i < tama; i++)
        {
            if(*(ve +i)==0){
                *(ve +i)= rand()%100;
            }
           
            
        }
        printf("\n vetor realocado:\n");
        for (int i = 0; i < tama; i++)
        {
            printf("%d ", *(ve +i));
            
        }
        printf("\n");
        free(ve);
        

    }
    else{
        printf("Erro ao alocar!\n");
    }*/

    //alocar uma matriz dinâmica
    /*int **matriz, i, j;
    int li, co;
    printf("Digite o número de linhas: ");
    scanf("%d", &li);
    printf("Digite o número de colunas: ");
    scanf("%d", &co);
    //Alocação dinâmica para as linhas
    matriz= malloc(li*sizeof(int*));
    //Alocação dinâmica para as colunas
    for ( i = 0; i < li; i++)
    {
        for(j=0; j<co; j++)
            matriz[i]=malloc(co*sizeof(int));
    }
    srand(time(0));
    for ( i = 0; i < li; i++)
    {
        for(j=0; j<co; j++)
            matriz[i][j]= rand()%100;
    }

    for ( i = 0; i < li; i++)
    {
        for(j=0; j<co; j++)
            printf("%2d ", matriz[i][j]);
        printf("\n");
    }*/
    
    // Exercício : Ler nome e nota de três estudantes e imprimir uma tabela
    int li, co, **matriz, *f,*g;
    //calculoMatriz(matriz,f,g, &li, &co);
    //printf("linhas: %d\tcolunas:%d\n", li, co);
    //printMatriz(matriz, f, g,li,co);


    //percorrer uma matriz dinâmica com aritmética de ponteiros

    /*int **matriz, i, j;
    int li, co;
    printf("Digite o número de linhas: ");
    scanf("%d", &li);
    printf("Digite o número de colunas: ");
    scanf("%d", &co);*/
    //Alocação dinâmica para as linhas
    //matriz= malloc(li*sizeof(int*));
    //Alocação dinâmica para as colunas
    /*for ( i = 0; i < li; i++)
    {
        for(j=0; j<co; j++)
            *(matriz+i)=malloc(co*sizeof(int));
    }
    srand(time(0));
    for ( i = 0; i < li; i++)
    {
        for(j=0; j<co; j++)
            *(*(matriz+i)+j)= rand()%100;
    }

    for ( i = 0; i < li; i++)
    {
        for(j=0; j<co; j++)
            printf("%2d ", *(*(matriz+i)+j));
        printf("\n");
    }*/
    
  // fazer uma função para inverter uma string
    //char palavra[100];
    /*int tamanho=0;
    printf("Digite a Palavra: ");
    scanf("%s", palavra);
    int i=0;
    while (palavra[i]!='\0')
    {
        printf("%c", palavra[i]);
        i++;
        tamanho++;
    }
    //printf("\n");
    //printf("%d\n", tamanho);
    Invertestring(palavra,tamanho);*/

    // liberar a memória de uma matriz dinâmica
   /* int **matriz, i, j;
    int li, co;
    printf("Digite o número de linhas: ");
    scanf("%d", &li);
    printf("Digite o número de colunas: ");
    scanf("%d", &co);
    //Alocação dinâmica para as linhas
    matriz= malloc(li*sizeof(int*));
    //Alocação dinâmica para as colunas
    for ( i = 0; i < li; i++)
    {
        for(j=0; j<co; j++)
            matriz[i]=malloc(co*sizeof(int));
    }
    srand(time(0));
    for ( i = 0; i < li; i++)
    {
        for(j=0; j<co; j++)
            matriz[i][j]= rand()%100;
    }

    for ( i = 0; i < li; i++)
    {
        for(j=0; j<co; j++)
            printf("%2d ", matriz[i][j]);
        printf("\n");
    }
    for (int i = 0; i < li; i++)
    {
        free(matriz[i]);
    }
    free(matriz);*/

    // fazer uma função para inverter uma string
    char *r;
    printf("digite a Frase! ");
    scanf("%100[^\n]", palavra);
    printf("Frase: %s\n", palavra);
    mudarpalavra(palavra);
    //printf("\n");
    printf("Frase Invertida: %s\n", palavra);
    r=mudarpalavra2(palavra);
    printf("Frase Invertida: %s\n", r);
    free(r);






    //Lendo uma string  
    //scanf("%100[^\n]", palavra);
    //printf("%s\n", palavra);




    //System("pause");
    return 0;
}