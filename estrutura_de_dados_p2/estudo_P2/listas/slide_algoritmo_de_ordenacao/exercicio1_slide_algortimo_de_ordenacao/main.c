#include <stdlib.h>
#include <stdio.h>

typedef struct no
{
    int num;
    struct no *prox;
} No;

No* busca(No *topo, int valor) //retorna No pra facilitar remoção, alteração, acesso e etc
{
    No *aux = topo; //ponteiro percorre a lista sem alterar o topo

    while (aux != NULL) //garente que aux percorra enquanto existe um nó
    {
        if (aux->num == valor) //comparação do valor buscado
        {
            return aux; //se acho ele retorna aux
        }

        aux = aux->prox; //se não achar de primeira vai pro prox nó
    }

    return NULL; //se não achou, retorna NULL
}

void retirar(No **topo, int elemento) //ponteiro duplo pro caso de remover o próprio topo, pois teria que remover ele inteiro e não só o conteúdo, "o endereço do ponteiro topo"
{
    No *atual = *topo; //variáveis pra percorrer a lista, atual recebe a lista
    No *anterior = NULL;

    while (atual != NULL && atual->num != elemento) //procura o elemento da chamada
    {
        anterior = atual; //atualiza os valores. Aqui é como se anterior estivesse uma posição atrás de atual, como numa corrida, então anterior sempre vai ter o valor antigo de atual, até não ter prox
        atual = atual->prox;
    }

    if (atual == NULL) //chegou ao final e o campo num de atual não deu == elemento
    {
        printf("Elemento nao encontrado\n");
        return;
    }

    // remoção do primeiro nó
    if (anterior == NULL) //se anterior for igual a NULL quer dizer que o elemento ta no primeiro No
    {
        *topo = atual->prox; //nesse caso atual é igual a topo, então no free do final da função, vai liberar
    }
    else
    {
        anterior->prox = atual->prox; //aqui, o anterior vai receber o mesmo valor de atual, assim teriam dois endereços com os mesmos valores, dessa forma, o anterior recebe o endereço do prox de atual e o free libera o atual, algo assim

        /* 
            [10] -> [20] -> [30]   isso é o vetor anterior, queremos tirar 20, então...
        
            nesse momento, 10 é o anterior e 20 é o atual, pois é igual ao elemento.

            quando entra essa linha: (anterior->prox = atual->prox;) anterior->prox era como se fosse 10->prox, que é o endereço de 20, fica igual atual->prox, algo como 20.prox, que é o endereço de 30

            então quando anterior->prox passa a ser igual a atual->prox, o campo prox de anterior tbm vai ter o endereço de 30, ou seja, ninguém aponta mais pra 20, é como se ele tivesse ficado do lado da fila, algo assim:

            [10] -> [30]   aqui temos o anterior como 10->prox que recebeu 30 na linha anterior, excluindo 20, pois nesse caso anterior é do tipo No, só o campo prox foi alterado, o num ainda mantém 10

            [20] -> [30]   aqui é seria o 20 apontando pro endereço de 30, ele existe, mas como ninguém aponta pra ele...

            da pra vizualizar assim:
            
            Locomotiva -> Vagão 10 -> Vagão 20 -> Vagão 30, antes. Você “desengata” o vagão 20.
            Locomotiva -> Vagão 10 -> Vagão 30, depois
        */ 
    }

    free(atual); //só libera memória

    printf("Elemento encontrado e retirado\n");
}

void listar(No **lista)
{   
    No *atual = *lista;
    No *anterior = *lista;
    No *menor = *lista;

    while (atual != NULL)
    {
        if (atual->num < anterior ->num)
        {
            menor->num = atual->num;
            menor->prox = atual->prox;
        }
        if (menor->num != anterior->num)
        {
            No *temp;
            temp->num = anterior->num;
            anterior->num = menor->num;
            menor->num = temp->num;
        }
        
        atual = atual->prox;
    }
   
    while (atual != NULL)
    {
        printf("[%d]\n", atual->num);
    }

}