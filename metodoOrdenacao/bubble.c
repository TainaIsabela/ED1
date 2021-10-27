#ifndef bubble
#define bubble

#include <stdio.h>

void bubbleSort(tipo_lista *lst);

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

#endif