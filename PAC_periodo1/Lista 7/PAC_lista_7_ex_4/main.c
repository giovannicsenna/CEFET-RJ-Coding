#include <stdio.h>
#define MAX 1000

struct produto
{
    int codprod;
    float preco;
    int qtdprod;
};
typedef struct produto Tproduto;


void leitura (Tproduto vetor[])
{
    int i;
    for (i = 0; i < MAX; i ++)
    {
        printf("Digite o código do produto: \n");
        scanf("%d", &vetor[i].codprod);

        printf("Digite o preço do produto: \n");
        scanf("%f", &vetor[i].preco);

        printf("Digite a qtd do produto: \n");
        scanf("%d", &vetor[i].qtdprod);
    }
    
}

int busca (Tproduto vetor[], int elemproc)
{
    int i;
    for (i = 0; i < MAX; i ++)
    {
        if(vetor[i].codprod == elemproc)
            return i;
    }
    
    return -1;
}

int main()
{
    Tproduto vet[MAX];
    int codigo, posicao;

    leitura(vet);

    while (codigo != 0)
    {
        printf ("Digite o código do produto: \n");
        scanf ("%d", &codigo);

        posicao = busca(vet, codigo);

        if (posicao == -1)
        {
            printf("Produto Inexistente");
        }
        else
        {
            printf("Preço do produto: %.2f\n Quantidade em estoque: %d\n", vet[posicao].preco, vet[posicao].qtdprod);
        }
        printf("Digite código do produto: ");
        scanf("%d", &codigo);
    }
    return 0;
}