#include <stdio.h>

char leValidaTipo (char a)
{
    printf("\nDigite o tipo do cliente: ");
    scanf(" %c", &a);

    return a;
}

void descobrePercentuais (char tipo, float *descn, float *desci)
{
    if (tipo == 'V' || 'v')
    {
        *descn = 25.5;
        *desci = 20.0;
    }
    if (tipo == 'E' || 'e')
    {
        *descn = 15.9;
        *desci = 11.5;
    }
    else
    {
        *descn = 5.0;
        *desci = 2.5;
    }   
}

int main()
{
    int cont = 1;
    int codigo;
    char tipocliente;
    float descontonacional, descontoimport;
    while (cont <= 1000)
    {
        printf("\nInforme código do cliente: ");
        scanf("%d", &codigo);

       tipocliente = leValidaTipo(tipocliente);
       descobrePercentuais(tipocliente, &descontonacional, &descontoimport);
       
       cont ++;
    }
    return 0;
}