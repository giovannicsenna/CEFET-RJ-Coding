#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int num;
    struct no *prox;
}No;

int listaVazia (No *topo){
    return topo == NULL; //se tiver alguma coisa, retorna 1, se não tiver nada, vai retornar 0
}

void listar(No *lista){
    No *atual = lista;

    while (atual != NULL)
    {
        printf("%d -> ", atual -> num); //acesse o campo num do nó apontado por atual
        atual = atual -> prox;
    }
    printf("NULL\n");
}

void empilhar (No **topo, int valor){
     No *novo = malloc(sizeof(No));

    if (novo == NULL)
    {
        printf("Erro de memoria\n");
        return;
    }

    novo->num = valor;
    novo->prox = *topo;

    *topo = novo;
}

void desempilhar(No **topo){

    if (listaVazia(*topo))
    {
        printf("Pilha vazia!\n");
        return;
    }

    No *remover = *topo;

    printf("Elemento removido: %d\n", remover->num);

    *topo = remover->prox;

    free(remover);
}

int main(){

    menu();

    return 0;
}

void menu (){
    
    No *topo = NULL; //Guarda o endereço do primeiro nó

    int funcao, valor;

    do{
        printf("1 - Empilhar\n2 - Desempilhar\n3 - Listar\n0 - Sair");
        scanf("%d", &funcao);

        if (funcao == 1)
        {
            printf("Digite um valor: ");
                scanf("%d", &valor);

                empilhar(&topo, valor);
        }
        else if (funcao == 2)
        {
            desempilhar(&topo);
        }
        else if (funcao == 3)
        {
            listar(topo);
        }
        else if (funcao == 0)
        {
            break;
        }
        else
        {
            printf("Escolha invalida\n");
        }
    
    }while (funcao != 0);
 
}

int main(){
    menu();

    return 0;
}