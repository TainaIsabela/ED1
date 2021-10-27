/*
UFMT - Ciência da Computação
Estrutura de Dados I
Tainá Isabela Monteiro da Silva- 202011722019

Ex3 - Prova de Estrutura de Dados -> quickSort
*/

#ifndef ordenacoes
#define ordenacoes

#include <stdio.h>
#include <stdlib.h>
#include "lista.c"

void quickSort(tipo_lista *lst);
void quickSortInterno(int vet[], int inicio, int fim);

void quickSort(tipo_lista *lst) {
    quickSortInterno(lst->lista, 0, lst->contador -1);
}

// Reutilzando o quickSort para ordenar a lista, mudando apenas as condicionais dos whiles foi possível fazer a ordenação decrescente
void quickSortInterno(int vet[], int inicio, int fim) {
    int pivo, meio, i, j, aux;
    meio = ((fim - inicio) / 2) + inicio;
    pivo = vet[meio];
    i = inicio;
    j = fim;

    while (i <= j) {
        while (vet[i] > pivo && i < fim) i++; // Neste while troquei a ultima condição para i < fim
        while(vet[j] < pivo && j > inicio) j--; // Neste while troquei a ultima condição para j > inicio
        if(i <= j) {
            aux = vet[j]; // Fiz trocas aqui também, onde era i foi substituido por j
            vet[j] = vet[i];
            vet[i] = aux;
            i++;
            j--;
        }
    }
    if( j > inicio) quickSortInterno(vet, inicio, j);
    if( i < fim) quickSortInterno(vet, i, fim);

    
// Complexidade do algoritmo: O(n log (n))   
}


#endif