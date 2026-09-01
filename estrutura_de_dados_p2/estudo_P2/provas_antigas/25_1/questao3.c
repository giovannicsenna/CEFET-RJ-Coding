#include <stdlib.h>
#include <stdio.h>

typedef struct No
{
    int valor;
    struct No *esq;
    struct No *dir;
}No;


void mostrarNosGrau2(No *raiz) {

    if (raiz == NULL)
        return;

    if (raiz->esq != NULL && raiz->dir != NULL)
        printf("%d ", raiz->valor);

    mostrarNosGrau2(raiz->esq);
    mostrarNosGrau2(raiz->dir);
}

//complexidade O(n), pois a função percorre todos os nós para determinar a quantidade se são de grau 2