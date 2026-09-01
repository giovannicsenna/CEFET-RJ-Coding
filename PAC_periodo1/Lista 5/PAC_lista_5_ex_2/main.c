#include <stdio.h>

void leprecoLitComb (float pricealc, float pricegas)
{
    printf("\nDigite o preço do álcool: ");
    scanf("%f", &pricealc);
    printf("\nDigite o preço da gasolina: ");
    scanf("%f", &pricegas);
}

void cont2000 (float sellvalue, float *moreth2000, float *lessth2000)
{
    *lessth2000 = 0;
    *moreth2000 = 0;
    if (sellvalue >= 2000)
    {
        *moreth2000 = *moreth2000 + sellvalue;
    }
    else
    {
        *lessth2000 = *lessth2000 + sellvalue;
    }
}

int main()
{
    int cont;
    char escolha;
    float pgas, palc, quantlit, maiorq2k, menorq2k;
    float vendagas, vendaalc;

    leprecoLitComb (palc, pgas);

    printf("\nDigite o tipo de combustível A ou G");
    scanf(" %c", &escolha);
    printf("\nQuantos litros?: ");
    scanf("%f", &quantlit);
    if (escolha == 'A'|| 'a')
    {
        vendaalc = quantlit * palc;
        
    }
    else
    {
        vendagas = quantlit * pgas;
    }

    //Não entendi o que é pra fazer com a função
    
    printf("\nValor total da venda de gás foi de: %.2f", vendagas);
    printf("\nValor total da venda de álcool foi de: %.2f", vendaalc);

    return 0;
}