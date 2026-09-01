#include <stdio.h>
#define TOT 10573

struct cliente
{
    int numcliente;
    float saldocliente;
};
typedef struct cliente Tcliente;

int leitura(Tcliente vetor[], float *saldomedio)
{
    int i = 0;
    float soma = 0;
    
    printf("Digite o número da conta (0 para encerrar): ");
    scanf("%d", &vetor[i].numcliente);

    while(vetor[i].numcliente != 0 && i < TOT)
    {
        printf("Digite o saldo do cliente: ");
        scanf("%f", &vetor[i].saldocliente);

        soma += vetor[i].saldocliente;

        i++;

        printf("Digite o número da conta (0 para encerrar): ");
        scanf("%d", &vetor[i].numcliente);
    }

    *saldomedio = soma / i;   // devolve o valor para o main

    return i;  // quantidade de clientes lidos
}

int main()
{
    Tcliente vet[TOT];
    float media; //armezenando o endereço de memória, por isso não vai precisar de um valor
    int qtd, i;

    qtd = leitura(vet, &media); //a quantidade de clientes vai ser armazenada na var qtd

    printf("\nSaldo médio dos clientes: %.2f\n\n", media);

    // exibe para cada cliente
    for(i = 0; i < qtd; i++)
    {
        printf("Conta: %d | Saldo: %.2f --> ", vet[i].numcliente, vet[i].saldocliente);

        if(vet[i].saldocliente > media)
            printf("Acima do saldo médio\n");
        else if(vet[i].saldocliente < media)
            printf("Abaixo do saldo médio\n");
        else
            printf("Igual ao saldo médio\n");
    }

    return 0;
}