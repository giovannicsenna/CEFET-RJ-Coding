#include <stdio.h>

void calcnumeros (int vetor [], int qtd, int *numneg, int *numpos, int *zero)
{
    *numneg = 0;
    *numpos = 0;
    *zero = 0;
    int i;
    for(i = 0; i < qtd; i++)
    {
        if (vetor [i] > 0)
        {
            (*numpos) ++;
        }
        else if (vetor [i] < 0)
        {
            (*numneg) ++;
        }
        else 
            (*zero) ++;
    
    }
}