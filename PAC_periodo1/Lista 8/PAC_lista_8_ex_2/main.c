#include <stdio.h>

void totalmes(int matriz[6][12])
{
    int mes = 0;

    // LOOP EXTERNO → percorre colunas (meses)
    while (mes < 12)
    {
        int ano = 0;     // reinicia o ano aqui
        int total = 0;   // total deve zerar a cada mês

        // LOOP INTERNO → percorre linhas (anos)
        while (ano < 6)
        {
            total += matriz[ano][mes]; // soma aquele mês em todos os anos
            ano++;
        }

        printf("Mês %d: total de %d carros\n", mes + 1, total);
        mes++;  // vai para o próximo mês
    }
}