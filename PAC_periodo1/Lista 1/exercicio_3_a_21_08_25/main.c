#include <stdio.h>

int calculaSoma (int n1, int n2, int n3) {
    int soma = n1 + n2 + n3;
}

int main() {
    int n1, n2, n3;

    printf("Primeiro número: ");
    scanf("%d", &n1);

    printf("Segundo número: ");
    scanf("%d", &n2);

    printf("Terceiro número: ");
    scanf("%d", &n3);

    int resultado = calculaSoma(n1, n2, n3);

    printf("Resultado: %d", resultado);
}