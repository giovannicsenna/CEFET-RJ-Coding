#include <stdio.h>

void calculaIdade (int a)
{
    if (a < 16)
    {
        printf("Não eleitor");
    }
    
    else if ((a >= 16 && a < 18) || a > 70)
    {
        printf("Eleitor Facultativo");
    }
    
    else
    {
        printf("Eleitor Obrigatório");
    }
}

int main()
{   int idade;
    
    printf("Digite idade ");
    scanf("%d", &idade);

    calculaIdade(idade);

    return 0;
}