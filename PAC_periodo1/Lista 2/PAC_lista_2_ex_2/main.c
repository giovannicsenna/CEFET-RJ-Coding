#include <stdio.h>
#include <math.h>

float hipotenusa(int a, int b){
    float h = sqrt(a * a + b * b);
    return h;
}

int main (){
    int cateto1, cateto2;
    float resultadohipotenusa;

    printf("Digite lado 1: ");
    scanf("%d", &cateto1);

    printf("Digite lado 2: ");
    scanf("%d", &cateto2);

    resultadohipotenusa = hipotenusa(cateto1, cateto2);
    
    

    printf("A hipotenusa é igual a aproximadamente: %.2f", resultadohipotenusa);

    return 0;

}
