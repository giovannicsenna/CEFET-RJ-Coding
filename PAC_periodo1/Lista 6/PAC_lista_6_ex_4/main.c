#include <stdio.h>
#define TOT 30

struct depto
{

int qtd;
float soma;

    
};
typedef struct depto Tdepto;

void calcsalariomed (Tdepto vetor [])
{
    int i;
    float salariomedio = 0;
    
    for (i = 0; i < TOT; i++)
    {
        salariomedio = vetor[i].soma / vetor[i].qtd;
        printf("Código do DP: %d\nSalário médio: %.2f\n", i + 1, salariomedio);
        //i + 1 pois um vetor começa em 0, e o código pede de 1 a 30
    }                                                           
}