#include <stdio.h>

void tabuada (int n)
{
    int cont = 0;
    int produto;

    while (cont <= 10)
    {
        produto = n * cont;
        
        printf("\n%d * %d = %d ", n, cont, produto);
        
        cont ++;
    }

}

int main ()
{
    int tab = 0;
    
    while (tab <= 10)
    {
        tabuada (tab);
        tab ++;
    }
    return 0;
}
