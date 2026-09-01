#include <stdio.h>

int processanumero (int qtdn)
{
    int n;
    int maiorn = 0;
    while (qtdn > 0)
    {
        printf("Digite o número: ");
        scanf("%d", &n);

        if (n >= maiorn)
        {
            maiorn = n;
        }

        qtdn --;
    } 

    return maiorn; 
}

int main()
{
    int quantidadenum, maiornumero;
    
    printf("Digite a quantidade de números: ");
    scanf("%d", &quantidadenum);

    maiornumero = processanumero(quantidadenum);

    printf("O maior número é: %d", maiornumero);
}

