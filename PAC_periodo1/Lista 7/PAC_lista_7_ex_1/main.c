#include <stdio.h>
#define TOT 50

void inicializa(int v[])
{
    int i = 0;
    while(i < TOT)
    {
        v[i] = 0;
        i++;
    }
}
void exibe (int v[])
{
    int i = 0;
    printf("\nQuarto\tQuantidade");
    while(i < TOT)
    {
        printf("\n%d\t\t%d", i+1, v[i]);
        i++;
    }
}
int main()
{
    int vqtd [TOT];
    int quarto;
    
    inicializa (vqtd);
    printf("Digite o quarto ou 0 ");
    scanf("%d", &quarto);
    while(quarto != 0)
    {
        vqtd[quarto - 1]++;
        printf("Digite o quarto ou 0");
        scanf("%d", &quarto);
    }
    exibe(vqtd);
    return 0;
}