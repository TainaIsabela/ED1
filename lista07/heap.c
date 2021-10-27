#ifndef HEAP_C
#define HEAP_c

#include <stdio.h>
#include <stdlib.h>
#include "lista.c"

// elemento pai = ( i - 1) / 2
// elemento filho esquerda 2 * i + 1
// elemento filho direta 2 * i + 2

#define N_heap 20

typedef struct heap {
    int heap[N_heap];
    int cont;
} tipoHeap;

//prototipação
int posPai(int);
int posFEsq(int);
int posFDir(int);
void inicializaHeap(tipoHeap *hp);
void insereHeap(tipoHeap *hp, int valor);
void sobeValor(tipoHeap *hp, int pos);
int desceValor(tipoHeap *hp, int pos);
void imprimeHeap(tipoHeap hp);
int consultaRaiz(tipoHeap hp);
int removeHeap(tipoHeap *hp);
void buscaValor(tipoHeap hp, int valor);
void heapSort(tipo_lista *lst);

int posPai(int i) {
    return (int)(i - 1) / 2;
}

int posFEsq(int i) {
    return (int) 2 * i + 1;
}

int posFDir(int i) {
    return (int) 2 * i + 2;
}

int removeHeap( tipoHeap *hp) {
    int valor;
    if(hp->cont > 0) {
        valor = hp->heap[0];
        hp->heap[0] = hp->heap[--hp->cont];
        desceValor(hp, 0);
        return valor;
    } else {
        return -1;
    }
}

void buscaValor(tipoHeap hp, int valor) {
    int i, flag = -1;
    for (i = 0; i < hp.cont; i++) {
        if(hp.heap[i] == valor)
            flag = 1;
    }
    if(flag == 1)
        printf("O valor %d foi encontrato no heap\n", valor);
    else
        printf("O valor %d não está presente no Heap\n", valor);
}

int consultaRaiz(tipoHeap hp) {
    if(hp.cont > 0) {
        printf("O heap max é: %d\n", hp.heap[0]);
        return hp.heap[0];
    } else {
        printf("Heap sem elementos\n");
    }
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

int desceValor(tipoHeap *hp, int pos) {
    int novaPos, aux;
    novaPos = -1;
    if(posFEsq(pos) < hp->cont) {
        if(posFDir(pos) < hp->cont) {
            if(hp->heap[posFEsq(pos)] > hp->heap[posFDir(pos)]) {
                if(hp->heap[pos] < hp->heap[posFEsq(pos)])
                    novaPos = posFEsq(pos);
            } else {
                if(hp->heap[pos] < hp->heap[posFDir(pos)])
                    novaPos = posFDir(pos);
            }
        } else {
            if(hp->heap[pos] < hp->heap[posFEsq(pos)])
                novaPos = posFEsq(pos);
        }
        if(novaPos > -1) {
            aux = hp->heap[pos];
            hp->heap[pos] = hp->heap[novaPos];
            hp->heap[novaPos] = aux;
            desceValor(hp, novaPos);
        }
    }
    return hp->heap[novaPos];
}

void imprimeHeap(tipoHeap hp) {
    int i;
    printf("Heap: [ ");
    for (i = 0; i < hp.cont; i++) {
        printf("%d ", hp.heap[i]);
    }
    printf("]\nContador = %d\n\n", hp.cont);
}

void heapSort(tipo_lista *lst) {
    tipoHeap heap;
    int i;
    inicializaHeap(&heap);
    for(i=0; i < lst->contador; i++) {
        insereHeap(&heap, lst->lista[i]);
    }

    for(i=lst->contador-1; i >= 0; i--) {
        lst->lista[i] = removeHeap(&heap);
    }

}



#endif //fim heap C