#include <stdio.h>
#define N 10

typedef struct estruturaPilha {
    int pilha[N];
    int contador;
} tipo_pilha;

void inicializaPilha(tipo_pilha *pl);
void empilha(tipo_pilha *pl, int valor);
int desempilha(tipo_pilha *pl);
int topo(tipo_pilha pl);
void imprimepilha(tipo_pilha pl);

int main() {
    tipo_pilha pilha;
    inicializaPilha(&pilha);

    empilha(&pilha, 6);
    empilha(&pilha, 7);
    empilha(&pilha, 9);
    printf("%d desempilhando\n", desempilha(&pilha));
    empilha(&pilha, 10);
    empilha(&pilha, 15);
    printf("%d desempilhando\n", desempilha(&pilha));
    imprimepilha(pilha);

    printf("%d elemento do topo da pilha\n", topo(pilha));

    return 0;
}

void inicializaPilha(tipo_pilha *pl) {
    pl->contador = 0;
}

void empilha(tipo_pilha *pl, int valor) {
    if(pl->contador < N) {
        pl->pilha[pl->contador++] = valor;
    } else {
        printf("Não foi possivel inserir mais valores porque a pilha está cheia\n");
    }
}

int desempilha(tipo_pilha *pl) {
    if(pl->contador > 0) {
        return pl->pilha[--pl->contador];
    } else {
        printf("Não é possivel desempilhar mais nenhum elemento a pilha já está vazia\n");
        return -1;
    }
}

int topo(tipo_pilha pl) {
    if(pl.contador > 0) {
        return pl.pilha[pl.contador - 1];
    } else {
        printf("A pilha está vazia\n");
        return -1;
    }
}

void imprimepilha(tipo_pilha pl) {
    int i;
    printf("[ ");

    for (i = 0; i < pl.contador; i++) {
        printf("%d ", pl.pilha[i]);
    }
    printf("] <- Topo\nContador = %d\n", pl.contador);
}