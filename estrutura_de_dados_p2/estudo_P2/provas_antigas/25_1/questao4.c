#include <stdlib.h>

typedef struct No
{
    int valor;
    struct No *esq;
    struct No *dir;
}No;

void listarEmOrdem(No *raiz)
{
    if (raiz == NULL)
        return;

    listarEmOrdem(raiz->esq);

    printf("%d ", raiz->valor);

    listarEmOrdem(raiz->dir);
}

//como a listagem de uma árvore BB naturalmente trabalha com o maior e menor, então lista-la naturalmente funcionaria, pois seria esquerda -> raiz -> direita, do maior para o menor

//já se fosse decrescente bastaria mudar a ordem em que chamamos a função recursiva. Ficando: direita -> raiz -> esquerda