#include <stdio.h>
#define TOT 20
struct funcionario
{
    int matricula;
    int coddepart;
    char sexo;
    int idade;
};
typedef struct funcionario Tfuncionario;

void inicializa(Tfuncionario vet[], int qtd)
{
    for(int i = 0; i < qtd; i++)
    {
        vet[i].matricula = 0;
        vet[i].coddepart = 0;
        vet[i].idade = 0;
        vet[i].sexo = ' ';
    }
}

void exibe(Tfuncionario vet[], int qtd)
{
    int dept;
    for(dept = 10; dept <= 20; dept++)
    {
        int soma = 0, cont = 0;

        // percorre todos os funcionários
        for(int i = 0; i < qtd; i++)
        {
            if(vet[i].coddepart == dept && vet[i].sexo == 'F')
            {
                soma += vet[i].idade;
                cont++;
            }
        }

        if(cont > 0)
            printf("Departamento %d - Idade média das funcionárias: %.2f\n",
                   dept, (float)soma / cont);
        else
            printf("Departamento %d - Nenhuma funcionária cadastrada\n", dept);
    }
}

int main()
{   
    Tfuncionario vetor[TOT];
    int qtdfunc;
    int i;
    char sexo;
    printf("Digite quantidade de Funcionários");
    scanf("%d", &qtdfunc);

    inicializa(vetor, qtdfunc);

    for (i = 0; i < qtdfunc; i ++)
    {
        printf("Digite matrícula: ");
        scanf("%d", &vetor[i].matricula);
        printf("Digite o código do dept: ");
        scanf("%d", &vetor[i].coddepart);
        printf("Digite a idade: ");
        scanf("%d", &vetor[i].idade);
        printf("Digite o sexo (M ou F)");
        scanf(" %c", &vetor[i].sexo); // Sempre lembrando do ler como caractere com espaço
    }

    
    exibe(vetor, qtdfunc);
    return 0;
}