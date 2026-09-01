#include <stdio.h>

void parImpar (int a)
{
    if (a % 2 == 0)
    {
        printf("Número ímpar\n");
    }
    else
    {
        printf("Número par\n");
    }
}

int main()
{
    int quantrep, quant, num, soma;
    float media;

    printf("Digite quantos números serão digitados ");
    scanf("%d", &quantrep, &quant);

    while (quantrep != 0)
    {   
        printf("\nDigite o número a checar\n");
        scanf("%d", &num);
        
        parImpar(num);
        quantrep = quantrep - 1;
        soma += num;
    }
    
    media = soma/quant;
    printf("\nMedia igual a: %.2f", media);
    
    return 0;
}