#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *esq;
    struct No *dir;
} No;

No* criarNo(int valor) {
    No *novo = (No*) malloc(sizeof(No));

    if (novo != NULL) {
        novo->valor = valor;
        novo->esq = NULL;
        novo->dir = NULL;
    }

    return novo;
}

No* inserir(No *raiz, int valor) {
    if (raiz == NULL)
        return criarNo(valor);

    if (valor < raiz->valor)
        raiz->esq = inserir(raiz->esq, valor);

    else if (valor > raiz->valor)
        raiz->dir = inserir(raiz->dir, valor);

    // Não insere valores duplicados

    return raiz;
}

void listarNos(No *raiz) {

    if (raiz == NULL){
        return;
    }

    listarNos(raiz->esq);

    printf("%d ", raiz->valor);

    listarNos(raiz->dir);
}

int somatorioNos (No *raiz){
    if (raiz == NULL)
        return 0;

    return raiz->valor
         + somatorioNos(raiz->esq)
         + somatorioNos(raiz->dir);
}
//Encontra o maior elemento de uma subárvore
No* encontrarMaior(No *raiz) {

    if (raiz == NULL){
        return NULL;
    }
    while (raiz->dir != NULL){
        raiz = raiz->dir;
    }

    return raiz;
}

// Encontra o menor elemento de uma subárvore
No* encontrarMinimo(No *raiz) {

    if (raiz == NULL){
        return NULL;
    }

    while (raiz->esq != NULL){
        raiz = raiz->esq;
    }

    return raiz;
}

int nosGrau1(No *raiz) {

    if (raiz == NULL)
        return 0;

    int atual = 0;

    if ((raiz->esq == NULL && raiz->dir != NULL) || (raiz->esq != NULL && raiz->dir == NULL))
    {
        atual = 1;
    }

    return atual
         + nosGrau1(raiz->esq)
         + nosGrau1(raiz->dir);
}

void listarFolhas (No *raiz){
    if (raiz == NULL)
    {
        return;
    }

    if (raiz->esq == NULL && raiz->dir == NULL)
    {
        printf("%d ", raiz->valor);
    }

    listarFolhas(raiz->esq);
    listarFolhas(raiz->dir);
    
}

int main(){
    No *raiz = NULL;

    raiz = inserir(raiz, 35);
    raiz = inserir(raiz, 25);
    raiz = inserir(raiz, 50);
    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 30);
    raiz = inserir(raiz, 40);
    raiz = inserir(raiz, 65);
    raiz = inserir(raiz, 28);

}