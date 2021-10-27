#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#include "lista.c"
#include "ordenacoes.c"

int main() {
    srand(time(NULL));
    clock_t comeco, fim;
    double tempoSegundos;
    tipo_lista listaOriginal, bubble, shell, insert, merge, quick;
    inicializaLista(&listaOriginal);
    bubble = listaOriginal;
    shell = listaOriginal;
    insert = listaOriginal;
    merge = listaOriginal;
    quick = listaOriginal;

    // imprimelista(listaOriginal);
    

    //Tempo bubbleSort
    comeco = clock();
    bubbleSort(&bubble);
    fim = clock();
    tempoSegundos = ( (double) ((fim - comeco))) / CLOCKS_PER_SEC;
    printf("\nO tempo de execucao do metodo de ordenacao BubbleSort foi de: %f se\gundos, com %d elementos na lista\n",tempoSegundos, N);


    //Tempo ShellSort
    comeco = clock();
    shellSort(&shell);
    fim = clock();
    tempoSegundos = ( (double) ((fim - comeco))) / CLOCKS_PER_SEC;
    printf("\nO tempo de execucao do metodo de ordenacao ShellSort foi de: %f segundos, com %d elementos na lista\n",tempoSegundos, N);


    //Tempo InsertSort
    comeco = clock();
    insert = insertSort(insert);
    fim = clock();
    tempoSegundos = ( (double) ((fim - comeco))) / CLOCKS_PER_SEC;
    printf("\nO tempo de execucao do metodo de ordenacao InsertSort foi de: %f segundos, com %d elementos na lista\n",tempoSegundos, N);


    //Tempo MergeSort
    comeco = clock();
    mergeSort(&merge);
    fim = clock();
    tempoSegundos = ( (double) ((fim - comeco))) / CLOCKS_PER_SEC;
    printf("\nO tempo de execucao do metodo de ordenacao InsertSort foi de: %f segundos, com %d elementos na lista\n",tempoSegundos, N);


    //Tempo Quicksort
    comeco = clock();
    quickSort(&quick);
    fim = clock();
    tempoSegundos = ( (double) ((fim - comeco))) / CLOCKS_PER_SEC;
    printf("\nO tempo de execucao do metodo de ordenacao InsertSort foi de: %f segundos, com %d elementos na lista\n",tempoSegundos, N);

    // imprimelista(listaOriginal);

    return 0;
}