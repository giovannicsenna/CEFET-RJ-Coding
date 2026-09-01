#include <stdio.h>

void vendagol (int vendas [6][12], float preco[6])
{
    int ano = 0;

    while (ano < 6)
    {
        float total = 0;
        int mes = 0;
        while (mes < 12)
        {
            total += vendas[ano][mes] * preco[ano];
            mes ++;
        }
        printf("Ano %d: total vendido = R$ %.2f\n", 2010 + ano, total);
        ano ++;
    }

}