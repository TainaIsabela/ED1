/*
UFMT - Ciência da Computação
Estrutura de Dados I
Tainá Isabela Monteiro da Silva - 202011722019
*/
#ifndef LISTA_C
#define LISTA_C

#include <stdio.h>
#include <stdlib.h>

#define N 30

typedef struct estrutura_lista {
    int lista[N];
    int contador;
} tipo_lista;

void inicializaLista(tipo_lista *lst);
void insereNoFimDaLista(tipo_lista *lst, int valor);
void insereNoInicioDaLista(tipo_lista *lst, int valor);
void insereEmPosicaoEspecificaDaLista(tipo_lista *lst, int valor, int posicao);
void imprimelista(tipo_lista lst);

void inicializaLista(tipo_lista *lst) {
    int i = 0;
    for (i = 0; i < N; i++) {
        lst->lista[i] = rand() % 100;
    }
    lst->contador = N;
}
void insereNoInicioDaLista(tipo_lista *lst, int valor) {
    if(lst->contador < N) {
        int i;
        
        for (i = lst->contador; i > 0; i--) {
            lst->lista[i] = lst->lista[i - 1];
        }
        lst->lista[0] = valor;
        lst->contador++;
    }
}

void insereNoFimDaLista(tipo_lista *lst, int valor) {
    if(lst->contador < N) {
        lst->lista[lst->contador++] = valor;
    }
}

void insereEmPosicaoEspecificaDaLista(tipo_lista *lst, int valor, int posicao) {
    if(lst->contador < N) {
        if(posicao >= 0 && posicao <= lst->contador) {
            int i;
            for (i = lst->contador - 1; i >= posicao; i--) {
                lst->lista[i+1] = lst->lista[i];
            }
            lst->lista[i + 1] = valor;
            lst->contador++;
        }
    }
}

void imprimelista(tipo_lista lst) {
    int i;
    printf("Lista: [ ");
    for (i = 0; i < lst.contador; i++) {
        printf("%d ", lst.lista[i]);
    }
    printf("]\nContador = %d\n", lst.contador);
}

#endif