#include <stdio.h>
#include <stdlib.h>

#include "heap.c"
#include "lista.c"

//Contem as respostas da 1 até a 6 e a questão 8

int main() {
    tipoHeap heap;
    inicializaHeap(&heap);

    insereHeap(&heap, 10);
    insereHeap(&heap, 5);
    insereHeap(&heap, 15);
    insereHeap(&heap, 20);
    insereHeap(&heap, 17);
    insereHeap(&heap, 8);
    insereHeap(&heap, 25);

    imprimeHeap(heap);
    consultaRaiz(heap);
    buscaValor(heap, 8);

    printf("O valor %d foi removido do heap\n",removeHeap(&heap));
    imprimeHeap(heap);
    buscaValor(heap, 77);

    printf("O valor %d foi removido do heap\n",removeHeap(&heap));
    imprimeHeap(heap);
    printf("O valor %d foi removido do heap\n",removeHeap(&heap));
    imprimeHeap(heap);
    printf("O valor %d foi removido do heap\n",removeHeap(&heap));
    imprimeHeap(heap);
    printf("O valor %d foi removido do heap\n",removeHeap(&heap));
    imprimeHeap(heap);
    printf("O valor %d foi removido do heap\n",removeHeap(&heap));
    imprimeHeap(heap);

    printf("\n HeapSort \n\n\n");

    tipo_lista lista;
    inicializaLista(&lista);

    insereNoFimDaLista(&lista, 10);
    insereNoFimDaLista(&lista, 1);
    insereNoFimDaLista(&lista, 7);
    insereNoFimDaLista(&lista, 4);
    insereNoFimDaLista(&lista, 8);
    insereNoFimDaLista(&lista, 3);
    insereNoFimDaLista(&lista, 6);

    imprimelista(lista);

    heapSort(&lista);
    imprimelista(lista);


    return 0;
}