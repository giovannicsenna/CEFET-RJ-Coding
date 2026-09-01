#include <stdio.h>

float calculaMedia(float n1, float n2) {
    return (n1 + n2) / 2;
}

int main() {
    float notap1, notap2, notat1, notat2;
    float mediap, mediat, mediageral;
    int matricula;

    printf("Digite matrícula: ");
    scanf("%d", &matricula);

    printf("Nota P1: ");
    scanf("%f", &notap1);

    printf("Nota P2: ");
    scanf("%f", &notap2);

    printf("Nota T1: ");
    scanf("%f", &notat1);

    printf("Nota T2: ");
    scanf("%f", &notat2);

    mediap = calculaMedia(notap1, notap2);
    mediat = calculaMedia(notat1, notat2);
    mediageral = calculaMedia(mediap, mediat);

    printf("\nMatrícula: %d\n", matricula);
    printf("Média das provas: %.2f\n", mediap);
    printf("Média dos trabalhos: %.2f\n", mediat);
    printf("Média geral: %.2f\n", mediageral);

    return 0;
}