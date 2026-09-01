#include <stdio.h>
#include <stdlib.h>

typedef struct peca{
    
    int num; //numero peca
    struct peca *prox;

}Peca;

void inicializa(Peca **inicio, Peca **fim){
    *inicio = NULL;
    *fim = NULL;
}

void enqueue (Peca **inicio, Peca **fim, int num){
    Peca *novo = (Peca*) malloc(sizeof (Peca));

    novo->num = num;
    novo->prox = NULL;

    if(*inicio == NULL){
        *inicio = novo;
        *fim = novo;
    }else{
        (*fim)->prox = novo;
        *fim = novo;
    }
}

int dequeue(Peca **inicio, Peca **fim, int *num){
    if (*inicio == NULL){
        return 0;
    }

    Peca *temp = *inicio;
    
    *num = temp->num;
    *inicio = temp->prox;
    
    if(*inicio != NULL){
        *fim = NULL;
    }
    
    free(temp);
    return 1;
}   