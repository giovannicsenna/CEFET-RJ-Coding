#include <stdio.h>

void cria_vetores (int A[10], int B[10]){
    for (int i = 0; i < 10; i++)
    {
        A[i] = i;
    }
    for (int j = 0; j < 10; j++)
    {
        B[j] = j + 10;
    }
}

void intercala (int A[10], int B[10], int C[20]){
    
    for (int i = 0; i < 10; i++)
    {
        C[2*i] = A[i];
        C[2*i + 1] = B[i];
    }
}

int busca (int C[20], int chave){
    for (int i = 0; i < 20; i++)
    {
        if (C[i] == chave)
        {
            printf ("Elemento Encontrado!!!\nElemento: %d\nPosicao: %d\n", C[i], i);
            return i;
        }
    }
    
    printf("Elemento nao encontrado T-T\n");
    
    return -1;
}

void remove_elementos_A(int A[10]){
    for (int i = 0; i < 8; i++)
    {
        A[i] = A[i + 2];
    }
}

void exibe_vetores (int A[10], int B[10], int C[20]){
    char escolha;
    printf ("Escolha o vetor para exibir\nA\tB\tC\n");
    scanf(" %c", &escolha);

    if (escolha == 'a' || escolha == 'A')
    {
        printf("Vetor A:\n");
        for (int i = 0; i < 8; i++)
        {
            printf("Posicao: %d\nElemento: %d\n\n", i, A[i]);
        }
        
    }

    else if (escolha == 'b' || escolha == 'B')
    {
        printf("Vetor B:\n");
        for (int i = 0; i < 10; i++)
        {
            printf("Posicao: %d\nElemento: %d\n\n", i, B[i]);
        }
        
    }

    else
    {
        printf("Vetor C:\n");
        for (int i = 0; i < 20; i++)
        {
            printf("Posicao: %d\nElemento: %d\n\n", i, C[i]);
        }
    }

}

int main(){
    int A[10], B[10], C[20];
    int key;

    cria_vetores(A, B);
    intercala (A, B, C);

    printf("Digite elemento a buscar: ");
    scanf("%d", &key);

    busca(C, key);

    remove_elementos_A(A);

    exibe_vetores(A,B,C);

    return 0;
}
