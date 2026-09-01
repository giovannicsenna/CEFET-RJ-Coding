#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX 52
#define COL 8
#define FREE 4
#define FUND 4

typedef struct {
    int valor;
    char naipe;
} Carta;

typedef struct {
    Carta cartas[MAX];
    int topo;
} Pilha;

//pilha
void init(Pilha *p) { p->topo = -1; }

int vazia(Pilha *p) { return p->topo == -1; }

Carta topo(Pilha *p) {
    if (!vazia(p)) return p->cartas[p->topo];
    Carta c = {0, 'X'};
    return c;
}

void push(Pilha *p, Carta c) {
    if (p->topo < MAX - 1)
        p->cartas[++p->topo] = c;
}

Carta pop(Pilha *p) {
    if (!vazia(p))
        return p->cartas[p->topo--];
    Carta c = {0, 'X'};
    return c;
}

//cor
int cor(Carta c) {
    if (c.naipe == 'E' || c.naipe == 'P')
        return 0; // preto
    return 1; // vermelho
}

//layout
void printCartaLinha(Carta c, int linha) {
    char *valores[] = {"", "A","2","3","4","5","6","7","8","9","10","J","Q","K"};
    char corLetra = (cor(c) == 0) ? 'P' : 'V';

    if (c.valor == 0) {
        printf("        ");
        return;
    }

    char valorStr[3];
    sprintf(valorStr, "%s", valores[c.valor]);

    switch (linha) {
        case 0: printf("+-----+ "); break;
        case 1: printf("|  %-2s | ", valorStr); break;
        case 2: printf("|  %c  | ", c.naipe); break;
        case 3: printf("|  %c  | ", corLetra); break;
        case 4: printf("+-----+ "); break;
    }
}

//baralho completo
void criarBaralho(Carta baralho[]) {
    char naipes[] = {'C','O','E','P'};
    int k = 0;

    for (int i = 0; i < 4; i++)
        for (int v = 1; v <= 13; v++)
            baralho[k++] = (Carta){v, naipes[i]};
}

void embaralhar(Carta b[]) {
    for (int i = 0; i < 52; i++) {
        int j = rand() % 52;
        Carta t = b[i];
        b[i] = b[j];
        b[j] = t;
    }
}

// regras gerais
int podeMoverColuna(Carta a, Carta b) {
    return (cor(a) != cor(b)) && (a.valor == b.valor - 1);
}

int podeFundacao(Pilha *f, Carta c) {
    if (vazia(f)) return c.valor == 1;
    Carta t = topo(f);
    return (c.naipe == t.naipe && c.valor == t.valor + 1);
}

// regra de mover bloco
int contarFreeVazias(Pilha free[]) {
    int count = 0;
    for (int i = 0; i < FREE; i++)
        if (vazia(&free[i]))
            count++;
    return count;
}

int contarColunasVazias(Pilha col[]) {
    int count = 0;
    for (int i = 0; i < COL; i++)
        if (vazia(&col[i]))
            count++;
    return count;
}

int maxMovimentos(Pilha col[], Pilha free[]) {
    int livres = contarFreeVazias(free);
    int vazias = contarColunasVazias(col);

    int max = livres + 1;

    for (int i = 0; i < vazias; i++)
        max *= 2;

    return max;
}

int tamanhoSequenciaValida(Pilha *p) {
    if (vazia(p)) return 0;

    int count = 1;

    for (int i = p->topo; i > 0; i--) {
        Carta a = p->cartas[i];
        Carta b = p->cartas[i - 1];

        if (cor(a) != cor(b) && a.valor == b.valor - 1)
            count++;
        else
            break;
    }

    return count;
}

//movimentações e invalidez
void moverColuna(Pilha col[], Pilha free[], int o, int d) {

    if (o < 0 || o >= COL || d < 0 || d >= COL) {
        printf("Indice invalido!\n");
        return;
    }

    if (vazia(&col[o])) {
        printf("Coluna vazia!\n");
        return;
    }

    int seq = tamanhoSequenciaValida(&col[o]);
    int max = maxMovimentos(col, free);

    if (seq > max) {
        printf("Movimento invalido! Limite de %d cartas.\n", max);
        return;
    }

    Carta base = col[o].cartas[col[o].topo - (seq - 1)];

    if (!vazia(&col[d]) && !podeMoverColuna(base, topo(&col[d]))) {
        printf("Movimento invalido!\n");
        return;
    }

    Carta temp[MAX];
    int i;

    for (i = 0; i < seq; i++)
        temp[i] = pop(&col[o]);

    for (i = seq - 1; i >= 0; i--)
        push(&col[d], temp[i]);
}

void moverFree(Pilha col[], Pilha free[], int o, int f) {

    if (o < 0 || o >= COL || f < 0 || f >= FREE) {
        printf("Indice invalido!\n");
        return;
    }

    if (vazia(&col[o])) {
        printf("Coluna vazia!\n");
        return;
    }

    if (!vazia(&free[f])) {
        printf("Freecell ocupada!\n");
        return;
    }

    push(&free[f], pop(&col[o]));
}

void freeParaCol(Pilha free[], Pilha col[], int f, int d) {

    if (f < 0 || f >= FREE || d < 0 || d >= COL) {
        printf("Indice invalido!\n");
        return;
    }

    if (vazia(&free[f])) {
        printf("Freecell vazia!\n");
        return;
    }

    Carta c = topo(&free[f]);

    if (vazia(&col[d]) || podeMoverColuna(c, topo(&col[d]))) {
        push(&col[d], pop(&free[f]));
    } else {
        printf("Movimento invalido!\n");
    }
}

void moverFund(Pilha col[], Pilha fund[], int o, int f) {
    if (vazia(&col[o])) return;

    Carta c = topo(&col[o]);

    if (podeFundacao(&fund[f], c))
        push(&fund[f], pop(&col[o]));
}

//distribui
void distribuir(Pilha col[], Carta baralho[]) {
    int k = 0;
    for (int i = 0; i < 52; i++)
        push(&col[i % COL], baralho[k++]);
}

void mostrar(Pilha col[], Pilha free[], Pilha fund[]) {

    printf("\n=========== FREECELL ===========\n");

    printf("\nFREECELLS:\n");
    for (int i = 0; i < FREE; i++) {
        Carta c = topo(&free[i]);
        if (c.valor == 0)
            printf("[ ] ");
        else
            printf("[%d%c] ", c.valor, c.naipe);
    }

    printf("\n\nFUNDACAO:\n");
    for (int i = 0; i < FUND; i++) {
        Carta c = topo(&fund[i]);
        if (c.valor == 0)
            printf("[ ] ");
        else
            printf("[%d%c] ", c.valor, c.naipe);
    }

    printf("\n\nCOLUNAS:\n");

    for (int i = 0; i < COL; i++) {
        printf("%d: ", i);
        for (int j = 0; j <= col[i].topo; j++) {
            printf("[%d%c] ", col[i].cartas[j].valor, col[i].cartas[j].naipe);
        }
        printf("\n");
    }

    printf("\n================================\n");
}


int main() {
    srand(time(NULL));

    Carta baralho[52];
    Pilha col[COL], free[FREE], fund[FUND];

    for (int i = 0; i < COL; i++) init(&col[i]);
    for (int i = 0; i < FREE; i++) init(&free[i]);
    for (int i = 0; i < FUND; i++) init(&fund[i]);

    criarBaralho(baralho);
    embaralhar(baralho);
    distribuir(col, baralho);

    char linha[50];

    while (1) {
        mostrar(col, free, fund);

        printf("\nComandos:\n");
        printf("move A B\n");
        printf("free A F\n");
        printf("back F A\n");
        printf("stack A F\n");
        printf("sair\n> ");

        fgets(linha, sizeof(linha), stdin);

        char cmd[20];
        int a, b;

        int lidos = sscanf(linha, "%s %d %d", cmd, &a, &b);

        if (lidos >= 1 && strcmp(cmd, "sair") == 0)
            break;

        if (lidos < 3) {
            printf("Entrada invalida!\n");
            continue;
        }

        if (strcmp(cmd, "move") == 0)
            moverColuna(col, free, a, b);
        else if (strcmp(cmd, "free") == 0)
            moverFree(col, free, a, b);
        else if (strcmp(cmd, "back") == 0)
            freeParaCol(free, col, a, b);
        else if (strcmp(cmd, "stack") == 0)
            moverFund(col, fund, a, b);
        else
            printf("Comando desconhecido!\n");
    }

    return 0;
}

//como jogar:

//compile o código pra gerar o executável usando uma máquina virtual e o comando "gcc freecell.c -o freecell" no terminal

//a formatação das colunas está deitada, então as colunas são da esquerda pra direita e vão de 0 a 7, os demais comandos estão no próprio código

//a movimentação de blocos já está automática, quando um movimento de blocos é possível ele já faz automaticamente