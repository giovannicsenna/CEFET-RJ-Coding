#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int num;
    struct no *prox;
} No;

typedef struct
{
    No *topo;
    No *ultimo;
} Fila;

/* Inicializa a fila */
void inicializaFila(Fila *f)
{
    f->topo = NULL;
    f->ultimo = NULL;
}

/* Insere no final da fila */
void enfileirar(Fila *f, int num)
{
    No *novo = (No *)malloc(sizeof(No));

    if (novo == NULL) //não tem nenhum endereço, erro do malloc
    {
        printf("Erro de alocacao!\n");
        return;
    }

    novo->num = num; //preenchimento dos campos do tipo Fila
    novo->prox = NULL; //NULL porque ainda não temos o próximo endereço

    if (f->topo == NULL) //o primeiro elemento da fila ta vazio, não tem ninguém
    {
        f->topo = novo; //o primeiro elemento da lista vai ser o novo
        f->ultimo = novo;//e o último também, porque só tem ele
    }
    else
    {
        f->ultimo->prox = novo; //se entrar no else, já tem alguem na fila, então é como se isso significasse  vá até o nó e altere seu prox (diferente do primeiro campo, prox recebe um endereço, nesse caso, o novo endereço que está sendo adicionado)
        f->ultimo = novo; //agora o último elemento é o que foi adicionado nesse else
    }
}

/* Remove do início da fila */
int desenfileirar(Fila *f, int *num)
{
    if (f->topo == NULL) //topo igual NULL significa que não tem ninguém na fila
    {
        return 0; // fila vazia
    }

    No *temp = f->topo; //temos um novo ponteiro que aponta pro topo

    *num = temp->num; //guarda o valor do elemento sendo adicionado
    f->topo = temp->prox; //avança o elemento depois do topo, o segundo da fila

    if (f->topo == NULL) //novamente testa se a lista está vazia
    {
        f->ultimo = NULL;
    }

    free(temp); //libera o espaço da memória para uma nova chamada da função
    return 1;
}

/* Exibe os elementos */
void listar(Fila *f) 
{
    No *aux = f->topo;//variável auxilar para exibir os elementos

    if (aux == NULL)
    {
        printf("Fila vazia!\n");//auto explicativo
        return;
    }

    printf("Fila: ");

    while (aux != NULL)//enquanto a fila tiver elementos...
    {
        printf("%d ", aux->num);//mostra o conteúdo dentro do campo num, o valor da posição na fila
        aux = aux->prox; //avança pro próximo elemento da fila
    }

    printf("\n");//só pula a linha
}

/* Verifica se está vazia */
int filaVazia(Fila *f)
{
    return (f->topo == NULL);
}

int main()
{
    Fila f;
    int valor;

    inicializaFila(&f); //inicializou tudo

    enfileirar(&f, 10); //passou direto os valores, sem variáveis
    enfileirar(&f, 20);
    enfileirar(&f, 30);

    listar(&f);

    if (desenfileirar(&f, &valor)) //não exclui o valor em si, exclui o endereço inteiro, o primeiro da fila
    {
        printf("Removido: %d\n", valor);
    }

    listar(&f);

    return 0;
}