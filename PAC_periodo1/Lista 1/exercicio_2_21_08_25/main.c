#include <stdio.h>

int calculoNum(int n1, int soma1, int mult1) {
    int calculo = (n1 + soma1) * mult1;
}

int main() {
    int n1, soma1, mult1;

    printf("Escreva o número 1: ");
    scanf ("%d", &n1);

    printf("Escreva o número a ser somado: ");
    scanf ("%d", &soma1);

    printf("Escreva o número a ser multiplicado: ");
    scanf ("%d", &mult1);

    int resultado = calculoNum (n1, soma1, mult1);

    printf("o resultado é: %d", resultado);

}