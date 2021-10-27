#ifndef HEAP_C
#define HEAP_c

#include <stdio.h>
#include <stdlib.h>

// elemento pai = ( i - 1) / 2
// elemento filho esquerda 2 * i + 1
// elemento filho direta 2 * i + 2

#define N 20

typedef struct heap {
    int heap[N];
    int cont;
} tipoHeap;

//prototipação
int posPai(int i);
int posFEsq(int i);
int posFDir(int i);
void inicializaHeap(tipoHeap *hp);
void insereHeap(tipoHeap *hp, int valor);
void sobeValor(tipoHeap *hp, int pos);
void imprimeHeap(tipoHeap hp);

int posPai(int i) {
    return (int)(i - 1) / 2;
}

int posFEsq(int i) {
    return (int) 2 * i + 1;
}

int posFDir(int i) {
    return (int) 2 * i + 2;
}


void inicializaHeap(tipoHeap *hp) {
    hp->cont = 0;
}

void insereHeap(tipoHeap *hp, int valor) {
    hp->heap[hp->cont++] = valor;
    sobeValor(hp, hp->cont-1);
}

void sobeValor(tipoHeap *hp, int pos) {
    int aux;
    if( hp->heap[pos] > hp->heap[posPai(pos)]) {
        aux = hp->heap[pos];
        hp->heap[pos] = hp->heap[posPai(pos)];
        hp->heap[posPai(pos)] = aux;

        if(posPai(pos) > 0)
            sobeValor(hp, posPai(pos));
    }
}

void imprimeHeap(tipoHeap hp) {
    int i;
    printf("Heap: [ ");
    for (i = 0; i < hp.cont; i++) {
        printf("%d ", hp.heap[i]);
    }
    printf("]\nContador = %d\n", hp.cont);
}



#endif //fim heap C