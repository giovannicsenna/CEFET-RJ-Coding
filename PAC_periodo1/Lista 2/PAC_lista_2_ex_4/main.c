#include <stdio.h>

float leCalcAumento(float a, float b){
    float salariototal = a * (1 + b/100);
    return salariototal;
}

int main(){
    float salario, aumento;
    float novosalario;

    printf("Digite o salário atual: ");
    scanf("%f", &salario);

    printf("Digite o aumento: ");
    scanf("%f", &aumento);

    novosalario = leCalcAumento(salario, aumento);
    printf("Seu novo salário é de R$ %.2f", novosalario);

    return 0; 
}