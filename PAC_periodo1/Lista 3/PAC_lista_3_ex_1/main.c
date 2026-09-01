#include <stdio.h>

float calculaSalario (float a)
{    
    float inss = a * 0.11;        
    
        if (inss > 951.62)
        {
            inss = 951.62;
        }

    printf("Valor a ser pago deverá ser: %.2f", inss);
    return inss;    
}

int main()
{
    float salario, descontoinss;
    
    printf("Digite salário ");
    scanf("%f", &salario);

    descontoinss = calculaSalario(salario);

    printf("Desconto a ser pago é de: %.2f", descontoinss);
    
    return 0;
}