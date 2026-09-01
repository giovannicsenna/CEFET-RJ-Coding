#include <stdio.h>

void verificaVogal(char a)
{
    if (a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U')
    {
        printf("Vogal maiúscula");
    }
    else
    {  
        printf("Não é vogal maiúscula");
    }
}

int main()
{
    char caractere;
    printf("Digite char ");
    scanf("%c", &caractere);

    verificaVogal(caractere);
    
    return 0;
}