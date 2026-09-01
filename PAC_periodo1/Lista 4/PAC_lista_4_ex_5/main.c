#include <stdio.h>

void mensagens (float med)
{
    if (med >= 7)
    {
        printf("\nAprovado");
        if (med >= 9.5)
        {
            printf("\nParabéns");
        }
    }
   else if (med < 5 )
    {
        printf("\nProva final");
    }
    else if (med < 3)
    {
        printf("\nReprovado");
    }
}

int alunos (int qtdaluno)
{
    int matric;
    float nt1, nt2;

    printf("\nDigite matrícula: ");
    scanf("%d", &matric);

    printf("\nDigite nota 1: ");
    scanf("%d", &nt1);
    printf("\nDigite nota 2: ");
    scanf("%d", &nt2);
}