#include <stdio.h>
#define MAX 10000
struct biblioteca
{
    int codlivro;
    int qtdexist;
    int qtdemprest;
};
typedef struct biblioteca Tbiblioteca;

void ordena (Tbiblioteca vetor[], int qtd)
{
    int k, i, min, aux;
    for(k = 0; k < qtd -1; k++)
    {
        min = k;
        for(i = k + 1; i < qtd; i++)
        {
            if (vetor[i].codlivro < vetor[min].codlivro)
                min = i;
        }
        if (min != k)
        {
            aux = vetor[min].codlivro;
            vetor[min].codlivro = vetor[k].codlivro;
            vetor[k].codlivro = aux;
        }
    }
}

int busca_binaria (Tbiblioteca vetor[],int qtd, int codprocura)
{
    int ini, fim, med, posicao;
    ini = 0;
    fim = qtd - 1;
    posicao = - 1;
    while (posicao == -1 && ini <= fim)
    {
        med = (ini + fim) / 2;
        if (vetor[med].codlivro == codprocura)
            posicao = med;
        else
            if(vetor[med].codlivro < codprocura)
                ini = med + 1;
            else
                fim = med -1;
    }
    return posicao;
}

void leitura (Tbiblioteca vetor[])
{
    int i = 0;
    while (i < MAX)
    {
        printf("Digite Código do Livro: \n");
        scanf("%d", &vetor[i].codlivro);

        printf("Digite Quantos livros existem: \n");
        scanf("%d", &vetor[i].qtdexist);

        printf("Digite quantos livros emprestados: \n");
        scanf("%d", &vetor[i].qtdemprest);

        i++;
    }
}

int main()
{
    Tbiblioteca vet[MAX];

    leitura (vet);
    ordena(vet, MAX);

    int escolha = 1;
    int pesquisa, qtd, posicao;
    while (escolha = 1)
    {
        printf("Deseja consultar? (0 pra sair)");
        scanf("%d", &escolha);

        if (escolha = 0)
        {
            printf("Consulta encerrada");
            break;
        }

        else
        {
            printf("Digite código a pesquisar");
            scanf("%d", &pesquisa);
            posicao = busca_binaria(vet, pesquisa, qtd);

            if (pesquisa = -1)
                printf("Livro não encontrado");
            else if (vet[pesquisa].qtdexist == vet[pesquisa].qtdemprest)
                printf("Livro não disponível para empréstimo");
            else
                printf("Disponível para empréstimo");
        }
    }
    return 0;
}