#include <stdio.h>
#include <stdlib.h>

#include "listaEstatica.c"
#include "bubble.c"

int main() {
    tipo_lista lista;
    inicializaLista(&lista);

    insereNoFimDaLista(&lista, 2);
    insereNoFimDaLista(&lista, 5);
    insereNoFimDaLista(&lista, 10);
    insereNoFimDaLista(&lista, 7);
    insereNoFimDaLista(&lista, 8);
    insereNoFimDaLista(&lista, 0);
    insereNoFimDaLista(&lista, 1);
    insereNoFimDaLista(&lista, 1);
    insereNoFimDaLista(&lista, 8);

    imprimelista(lista);
    bubbleSort(&lista);
    imprimelista(lista);
    return 0;
}