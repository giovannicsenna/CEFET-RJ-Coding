#include <stdio.h>

int numerospares (int vetor [], int qtd)
{
    int produto = 1;
    int i;
    for (i = 0; i < qtd; i++)
    {
        if (vetor[i] % 2 == 0)
        {
            produto *= vetor [i];
        }
    }
    return produto;
}