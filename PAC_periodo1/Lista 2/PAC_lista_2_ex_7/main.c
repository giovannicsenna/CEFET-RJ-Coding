#include <stdio.h>
#include <math.h>

float calcDistancia(float x1, float y1, float x2, float y2) {
    float dist = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    return dist;
}

float calcPerimetro(float a, float b, float c){
    float perim = a + b + c;
    return perim;
}

int main () {
    float l1, l2, l3;
    float perimetro;
    float p1x, p2x, p1y, p2y;
    float distanciapontos;

    printf("Digite o lado 1: ");
    scanf("%f", &l1);

    printf("Digite o lado 2: ");
    scanf("%f", &l2);

    printf("Digite o lado 3: ");
    scanf("%f", &l3);

    perimetro = calcPerimetro(l1, l2, l3);
    printf("Perímetro: %.2f\n", perimetro);

    printf("Digite x1: ");
    scanf("%f", &p1x);
    printf("Digite x2: ");
    scanf("%f", &p2x);
    
    printf("Digite y1: ");
    scanf("%f", &p1y);
    printf("Digite y2: ");
    scanf("%f", &p2y);

    distanciapontos = calcDistancia(p1x, p1y, p2x, p2y);
    printf("Distância: %.2f", distanciapontos);

    return 0;    
}

