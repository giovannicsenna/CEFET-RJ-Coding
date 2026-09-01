#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int valor; //o campo que recebe o valor
    struct no *prox; //campo que recebe o endereço do próximo no
} No;

typedef struct fila
{
    No *topo; //primeiro da fila
    No *ultimo; //ultimo da fila
} Fila;

void enqueue (Fila *f, int num) //recebe a própria fila e o valor que a gente vai adicionar
{
    No *novo = (No*) malloc(sizeof (No)); //malloc né, esse troço é esquisitão até hj não sei o que faz direito, só sei que direciona pra um endereço... ou cria um, sla, sei de nada tbm
    
    /*==========================tomei vergonha na cara e perguntei pro chat gpt===================================*/
        
        /*basicamente, o malloc reserva memória de forma dinâmica durante a execulão "memory allocation" por isso que esse troço chama malloc
        
            é tipo virar e falar pro sistema "Reserve um espaço na memória grande o suficiente para armazenar uma struct No e me devolva o endereço desse espaço."*/
    
    novo -> valor = num; //aqui preenche os campos de "novo" pq ele é do tipo No;
    novo -> prox = NULL; //NULL pq ainda n ta alocado;

    if (f -> topo  == NULL) //Nesse caso, como temos uma variável do tipo Fila, que possui os campos topo e ultimo, só *topo ou *ultimo não basta, é preciso usar f -> topo, pois é a fila apontando pro campo topo. Porém, se fosse usado **topo e **ultimo como parâmetros da função, sem a struct, *topo e *ultimo, simplesmente, bastariam.

    {
        f -> topo = novo; //o if verificou que não existe primeiro elemento, logo, não tem ninguém na fila, porque se não tem um "primeiro da fila" obviamente é porquê ela está vazia
        f -> ultimo = novo; //o último da fila e o primeiro da fila são a mesma pessoa, porque não tinha ninguém
    }
    else //já que tem alguém na fila...
    {
        (f -> ultimo) -> prox = novo; //aqui o nó já preenchido (último da fila) passa a apontar para o novo útlimo da fila
        f -> ultimo = novo; //nessa útlima linha o último nó passa a ser o novo que a gente adicionou
    }   
    
    
}

//OBS: O parênteses é igual o da matemática, não tem nada de especial nessa desgraça, ele só garante que primeiro a função vai fazer a fila apontar pra ultimo, pra depois o ultimo apontar pro prox. Só que como essa bosta funciona na direção da setinha esse troço é completamente inútil, pq ele vai fazer f->utlimo->prox do mesmo jeito