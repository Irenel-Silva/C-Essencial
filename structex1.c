#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Aprendendo typedef e struct básico
//typedef char user[25];
struct User
{
    /* data */
    char nome[25];
    char password[12];
    int id;
};

typedef struct{
    char nome[25];
    char password[12];
    int id;
}User;

typedef struct{
    char nome[20];
    int score;

}Player;


int main(){
    int a[6], i, aux=0, j;
    // Gerando valores aleatórios únicos(não repetidos)
    srand(time(0)); 
    //int n= rand()% 10;
    for(i=0; i<6;i++){
        
        a[i]= rand() %10;
        //printf("%d %d\n ", i,  a[i]);
        for(j=0; j<i; j++){
            // while(a[i] == a[j]){
            while(a[j] == a[i])
            { 
                a[i]= rand() % 10;
                j=0;
                
            }
          
        } 
        //printf("%d %d\n", i, a[i]); 
        
    }
    printf("Vector sem ordenação\n");
    for ( i = 0; i < 6; i++)
    {
        /* code */
        printf("%d ", a[i]);
    }
    printf("\n");
// Implementando o BubleSort
   /* for(i=1; i<6;i++){
        for (int j = 0; j< i; j++)
        {
            if (a[j]>a[i])
            {
              aux= a[j];
              a[j]=a[i];
              a[i]=aux;  
              j=0;
            }
            
        }
        

    }*/

    /*printf("Vector com ordenação BubleSort\n");
    for ( i = 0; i < 6; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n"); */

    //printf("%d\n", n);

// Implementando o SelectionSort
    int indice, maior;
    for(i=0; i<6;i++){
        aux=a[i];
        maior=0;
        indice=0;
        for (int j = i; j<5; j++)
        {
            if (aux>a[j+1])
            {
                aux= a[j+1];
                indice=j+1;
                maior=1;
            }  
            printf("%d \n",aux);
        }
        if(maior>0){
            a[indice]=a[i];
            a[i]=aux;

        }
    
    }

    printf("Vector com ordenação SelectionSort\n");
    for ( i = 0; i < 6; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    //*Typedef definindo um apelido
    // user u1= "Bro";
    //*Usando struct
    //struct User u1= {"Bro", "xyz", 2};
    //struct User u2= {"Dad", "klm", 4};

    //* Usando typedef struct
    /*User u1= {"Bro", "xyz", 2};
    User u2= {"Dad", "klm", 4};

    printf("%d\n", u1.id);
    printf("%s\n", u1.nome);
    printf("%s\n", u1.password);

    printf("\n");

    printf("%d\n", u2.id);
    printf("%s\n", u2.nome);
    printf("%s\n", u2.password);*/


    //Exemplo 2
    //Player p1= {"victor", 200};
    //Player p2={"bruno", 100};
    // Exemplo 2 adicionando valores a cada elemento do struct
    //strcpy(p1.nome, "Adas");
    //p1.score=50;

    /*printf(" As pontuacoes dos jogadores sao: \n");
    printf("%s ", p1.nome);
    printf("%d ", p1.score);
    printf("\n");
    printf("%s ", p2.nome);
    printf("%d\n", p2.score);*/


    return 0;
}