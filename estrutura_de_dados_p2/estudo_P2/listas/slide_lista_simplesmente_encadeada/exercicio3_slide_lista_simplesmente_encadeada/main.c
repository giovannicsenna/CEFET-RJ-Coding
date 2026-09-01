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
}Fila;

void inicializa(Fila *f)
{
    f->topo = NULL;
    f->ultimo = NULL;
}

/* Insere no final da fila */
void enqueue(Fila *f, int num)
{
    No *novo = (No *)malloc(sizeof(No));

    if (novo == NULL)
    {
        printf("Erro de alocacao!\n");
        return;
    }

    novo->num = num;
    novo->prox = NULL;

    if (f->topo == NULL)
    {
        f->topo = novo;
        f->ultimo = novo;
    }
    else
    {
        f->ultimo->prox = novo;
        f->ultimo = novo;
    }

    printf("Elemento %d inserido na fila.\n", num);
}

int dequeue (Fila *f, int *num)
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

int filaVazia(Fila *f)
{
    return (f->topo == NULL);
}

void listar (Fila *f)
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
        printf("%d \n", aux->num);//mostra o conteúdo dentro do campo num, o valor da posição na fila
        aux = aux->prox; //avança pro próximo elemento da fila
    }
}

void menu(Fila *f)
{
    int escolha;
    int valor;

    printf("1 = Dequeue\t2 = Enqueue\t3 = Listar\t4 = Sair\n");
    scanf("%d", &escolha);

    while (escolha != 4)
    {
        if (escolha == 1)
        {
            if (dequeue(f, &valor))
            {
                printf("Elemento removido: %d\n", valor);
            }
            else
            {
                printf("Fila vazia!\n");
            }
        }
        else if (escolha == 2)
        {
            printf("Digite o valor: ");
            scanf("%d", &valor);

            enqueue(f, valor);
        }
        else if (escolha == 3)
        {
            listar(f);
        }
        else
        {
            printf("Opcao invalida!\n");
        }

        printf("\n1 = Dequeue\t2 = Enqueue\t3 = Listar\t4 = Sair\n");
        scanf("%d", &escolha);
    }
}

int main()
{
    Fila fila;

    inicializa(&fila);
    menu(&fila);
}



