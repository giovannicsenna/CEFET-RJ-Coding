#include <stdio.h>

typedef struct pneu {
    int num; //número do pneu
    struct pneu* prox;
}Pneu;

void empilhar(Pneu **topo, int num) {
    Pneu *novo = (Pneu *) malloc(sizeof(Pneu));
    
    novo->num = num;
    novo->prox = *topo;
    
    *topo = novo;
}

void retirarTodos(Pneu **topo) {
    Pneu *temp;

    while (*topo != NULL) {
        temp = *topo;
        printf("Retirando pneu %d\n", temp->num);

        *topo = (*topo)->prox;
        free(temp);
    }
}

void exibe(Pneu *topo) {
    while (topo != NULL) {
        printf("%d -> ", topo->num);
        topo = topo->prox;
    }
    printf("NULL\n");
}

int main() {
    Pneu *topo = NULL;

    empilhar(&topo, 1);
    empilhar(&topo, 2);
    empilhar(&topo, 3);

    exibe(topo);

    retirarTodos(&topo);

    return 0;
}