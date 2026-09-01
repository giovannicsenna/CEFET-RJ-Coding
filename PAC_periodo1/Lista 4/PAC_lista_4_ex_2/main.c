#include <stdio.h>

int contaPar (int nrep)
{   
    int quantp = 0;
    int b;
    while (nrep != 0)
    {
        printf("\nDigite numero: ");
        scanf("%d", &b);
        
        if (b % 2 == 0)
        {
            quantp = quantp + 1;
        }
        nrep--;
    }
    
    return quantp;
}

int main()
{
    int rep, resultado;
    printf("Quantidade de números a ser lida: ");
    scanf("%d", &rep);

    resultado = contaPar(rep);

    printf("A quantidade de pares é: %d", resultado);

    return 0;   
}
