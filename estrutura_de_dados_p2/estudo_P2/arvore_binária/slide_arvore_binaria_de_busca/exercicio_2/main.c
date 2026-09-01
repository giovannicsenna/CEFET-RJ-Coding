#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct No {
    char nome[50];
    struct No *esq;
    struct No *dir;
} No;

No* inserir(No *raiz, char nome[]) {

    if (raiz == NULL) {
        No *novo = malloc(sizeof(No));

        strcpy(novo->nome, nome);
        novo->esq = NULL;
        novo->dir = NULL;

        return novo;
    }

    if (strcmp(nome, raiz->nome) < 0)
        raiz->esq = inserir(raiz->esq, nome);

    else if (strcmp(nome, raiz->nome) > 0)
        raiz->dir = inserir(raiz->dir, nome);

    return raiz;
}

void listarEmOrdem(No *raiz) {

    if (raiz == NULL)
        return;

    listarEmOrdem(raiz->esq);

    printf("%s\n", raiz->nome);

    listarEmOrdem(raiz->dir);
}