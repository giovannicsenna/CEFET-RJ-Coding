#include <stdio.h>

void umPosto (int qtdsell, float *balc, float *bdies, float *bgas)
{
    char typefuell;
    float sellvalue = 0;
    *balc = 0;
    *bdies = 0;
    *bgas = 0;

    printf("Digite a quantidade de vendas: ");
    scanf("%d", &qtdsell);

    while (qtdsell > 0)
    {
        printf("Digite o Tipo de combustível: ");
        scanf(" %c", &typefuell);
        printf("Digite o valor da venda: ");
        scanf("%f", &sellvalue);

        if (typefuell == 'A'|| typefuell == 'a')
        {
            if (sellvalue > *balc )
            {
                *balc = sellvalue;
            }  

        }

        if (typefuell == 'D'|| typefuell == 'd')
        {   
            if (sellvalue > *bdies )
            {
                *bdies = sellvalue;
            }

        }

        else
        {
            if (sellvalue > *bgas)
            {
                *bgas = sellvalue;
            }

        }
        
        qtdsell --;

    }
    
}


int main ()
{
    int codposto;
    int quantidadevendas;
    float maioralc, maiordies, maiorgas;

    printf("\nDigite o código do seu posto: ");
    scanf("%d", codposto);

    umPosto (quantidadevendas, &maioralc, &maiordies, &maiorgas);

    printf("\nMaior venda de alcool do posto %d foi de: %.2f", codposto, maioralc);
    printf("\nMaior venda de diesel do posto %d foi de: %.2f", codposto, maiordies);
    printf("\nMaior venda de gasolina do posto %d foi de: %.2f", codposto, maiorgas);

    return 0;
}