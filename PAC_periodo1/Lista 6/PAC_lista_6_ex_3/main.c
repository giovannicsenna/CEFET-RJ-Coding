#include <stdio.h>

int calcmedia (float vetor [], int qtd, float media)
{
    int i;
    int contanum = 0;
    
    for (i = 0; i < qtd; i ++)
    {
        if (vetor[i] > media)
        {
            contanum++;
        }
    }
    return contanum;
}