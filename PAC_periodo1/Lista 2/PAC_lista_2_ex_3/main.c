#include <stdio.h>

float calculaValorGarcom(float a){
    float valorgarcom = a * 0.1;
    return valorgarcom;
}

float calculavalortotal(float b){
    float valortotal = b * 1.1;
    return valortotal;
}

int main(){
    float valorconsumo, bonusgarcom;
    float valorconta;

    printf("Digite o valor do consumo do cliente: ");
    scanf("%f", &valorconsumo);

    
    printf("Valor a ser pago pelo consumo: %.2f\n", valorconsumo);
    
    bonusgarcom = calculaValorGarcom(valorconsumo);
    printf("Valor a ser pago ao garçom: %.2f\n", bonusgarcom);

    valorconta = calculavalortotal(valorconsumo);
    printf("Total: %.2f", valorconta);

    return 0;
}