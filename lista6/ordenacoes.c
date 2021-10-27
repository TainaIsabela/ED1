#ifndef ordenacoes
#define ordenacoes

#include <stdio.h>
#include <stdlib.h>
#include "lista.c"

void bubbleSort(tipo_lista *lst);
void shellSort(tipo_lista *lst);
tipo_lista insertSort(tipo_lista lst);
void mergeSort(tipo_lista *lst);
void mergeSortDiv(int vet[], int tam);
void merge(int vet[], int tam);
void quickSort(tipo_lista *lst);
void quickSortInterno(int vet[], int inicio, int fim);



void bubbleSort(tipo_lista *lst) {
    int flagTroca, aux, idx;

    flagTroca = 1;
    while(flagTroca) {
        flagTroca = 0;
        for (idx = 0; idx < lst->contador-1; idx++) {
            if(lst->lista[idx] > lst->lista[idx+1]){
                aux = lst->lista[idx];
                lst->lista[idx] = lst->lista[idx+1];
                lst->lista[idx+1] = aux;
                flagTroca = 1;
            }
        }
    }
}

void shellSort(tipo_lista *lst) {
    int flagTroca, aux, idx = 0, k;
    k = lst->contador / 2;
    flagTroca = 1;

    while (k > 1) {
        while (idx+k < lst->contador) {
            if(lst->lista[idx] > lst->lista[idx+k]) {
                aux = lst->lista[idx];
                lst->lista[idx] = lst->lista[idx+k];
                lst->lista[idx+k] = aux;
                flagTroca = 1;
            }
            idx++;
        }
        k--;
    }
    if(k == 1) bubbleSort(lst); 
    /*
    Mesmo tendo comentado que não ficaria legal utilizar a chamada do bubbleSort dentro do shellSort, eu optei por utilizar dessa forma
    para evitar duplicidades no codigo, acima ja tem um trecho muito semelhante ao bubble, e teria que adicionar um basicamente igual novamente
    particularmente a duplicidade me incomoda mais do que um metodo de ordenação consultar outro, mas deixarei comentado o shellsort, 
    sem chamadas externas
    */
}

/*
void shellSort(tipo_lista *lst) {
    int flagTroca, aux, idx = 0, k;
    k = lst->contador / 2;
    flagTroca = 1;

    while (k > 1) {
        while (idx+k < lst->contador) {
            if(lst->lista[idx] > lst->lista[idx+k]) {
                aux = lst->lista[idx];
                lst->lista[idx] = lst->lista[idx+k];
                lst->lista[idx+k] = aux;
                flagTroca = 1;
            }
            idx++;
        }
        k--;
    }
    while(flagTroca) {
        flagTroca = 0;
        idx = 0;
        while (idx < lst->contador-1) {
            if(lst->lista[idx] > lst->lista[idx+1]) {
                aux = lst->lista[idx];
                lst->lista[idx] = lst->lista[idx+1];
                lst->lista[idx+1] = aux;
                flagTroca = 1;
            }
            idx++;
        }
    }
}
*/

tipo_lista insertSort(tipo_lista lst) {
    int idxLst, idx;
    tipo_lista lstOrdenada;
    lstOrdenada.contador = 0;

    for (idxLst = 0; idxLst < lst.contador; idxLst++) {
        if(lstOrdenada.contador == 0) {
            insereNoFimDaLista(&lstOrdenada, lst.lista[idxLst]);
        } else {
            idx = lstOrdenada.contador - 1;
            while (idx >= 0 && lst.lista[idxLst] < lstOrdenada.lista[idx]) {
                idx--;
            }
        }
        insereEmPosicaoEspecificaDaLista(&lstOrdenada, lst.lista[idxLst], idx+1);
    }
    return lstOrdenada;
}

void mergeSort(tipo_lista *lst) {
    mergeSortDiv(lst->lista, lst->contador);
}

void mergeSortDiv(int vet[], int tam) {
    int meio;
    if( tam > 1) {
        meio = tam / 2;
        mergeSortDiv(vet, meio);
        mergeSortDiv(&vet[meio], tam - meio);
        merge(vet, tam);
    }
}

void merge(int vet[], int tam) {
    int *vetAux, meio, i = 0, j, idxAux = 0;
    meio = tam / 2;
    j = meio;
    vetAux = (int*) malloc(sizeof(int)*tam);

    while (i < meio && j < tam) {
        if(vet[i] < vet[j]) {
            vetAux[idxAux++] = vet[i++];
        } else {
            vetAux[idxAux++] = vet[j++];
        }
    }
    while (i < meio) {
        vetAux[idxAux++] = vet[i++];
    }
    while (j < tam) {
        vetAux[idxAux++] = vet[j++];
    }

    for (i = 0; i < tam; i++) {
        vet[i] = vetAux[i];
    }
    free(vetAux);
}

void quickSort(tipo_lista *lst) {
    quickSortInterno(lst->lista, 0, lst->contador -1);
}

void quickSortInterno(int vet[], int inicio, int fim) {
    int pivo, meio, i, j, aux;
    meio = ((fim - inicio) / 2) + inicio;
    pivo = vet[meio];
    i = inicio;
    j = fim;

    while (i <= j) {
        while (vet[i] < pivo && i < fim) i++;
        while(vet[j] > pivo && j > inicio) j--;
        if(i <= j) {
            aux = vet[i];
            vet[i] = vet[j];
            vet[j] = aux;
            i++;
            j--;
        }
    }
    if( j > inicio) quickSortInterno(vet, inicio, j);
    if( i < fim) quickSortInterno(vet, i, fim);
    
}

#endif