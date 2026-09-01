#include <stdio.h>
#include <stdlib.h>

typedef struct pneu{
    int num; //numero do pneu
    struct pneu *prox;
}Pneu;

void inicializa (Pneu **topo){
    *topo = NULL;
}

void empilha(Pneu **topo, int num){
    Pneu *novo = (Pneu*) malloc(sizeof(Pneu));

    novo -> num = num;
    novo -> prox = *topo;

    *topo = novo;
}

int desempilhar(Pneu **topo, int *num){
    if(*topo == NULL){
        return 0;
    }
    
    Pneu *temp = *topo;

    *num = temp -> num;
    *topo = temp -> prox;
    free(temp);
    
    return 1;
}

void retirarTodos (Pneu **topo){
    Pneu *temp;

    while(*topo != NULL){
        temp = *topo;
        *topo =(*topo) -> prox;

        free(temp);
    }
}