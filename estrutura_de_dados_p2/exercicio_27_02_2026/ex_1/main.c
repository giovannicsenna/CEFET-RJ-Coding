//TAREFA 1: Preencher um vetor com 10 elementos ou usar um algoritmo de ordenação para organiza-lo.

#include <stdio.h>
#define MAX 3

void preencher (char v[])
{
    int i;
    for (i = 0; i <MAX; i++)
    {
        printf("Digite uma letra ");
        scanf(" %c", &v[i]);
    }
}

void exibe(char v[])
{
    int i;

    for (i = 0; i < MAX; i++)
    {
        printf("\nletra da posição %d: %c", i, v[i]);
    }
}

int main()
{
    char vetor[MAX];
    
    preencher(vetor);
    exibe(vetor);

}


