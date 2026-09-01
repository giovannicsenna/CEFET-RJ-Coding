#include <stdio.h>

// Função que processa os funcionários e retorna o gasto extra
float processaFuncionarios(float percentual)
{
    int matricula;
    float salario, novoSalario, aumento, gastoExtra = 0;

    printf("\nDigite a matrícula do funcionário (0 para sair): ");
    scanf("%d", &matricula);

    while (matricula != 0)
    {
        printf("Digite o salário atual do funcionário: ");
        scanf("%f", &salario);

        aumento = salario * (percentual / 100);   // valor do aumento
        novoSalario = salario + aumento;          // novo salário

        printf("Matrícula %d - Novo salário: %.2f\n", matricula, novoSalario);

        gastoExtra += aumento;  //acumula gasto

        printf("\nDigite a matrícula do próximo funcionário (0 para sair): ");
        scanf("%d", &matricula);
    }

    return gastoExtra;
}

int main()
{
    float percentual, totalGasto;

    printf("Digite o percentual de aumento: ");
    scanf("%f", &percentual);

    totalGasto = processaFuncionarios(percentual);

    printf("\nO gasto extra total com os aumentos será: %.2f\n", totalGasto);

    return 0;
}
