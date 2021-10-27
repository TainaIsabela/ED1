/*
UFMT - Ciência da Computação
Estrutura de Dados I
Tainá Isabela Monteiro da Silva - 202011722019

Ex3 - Prova de Estrutura de Dados -> quickSort
Ex4 - Prova de Estrutura de Dados -> Arvore MultiplosFilhos
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#include "lista.c"
#include "ordenacoes.c"
#include "arvmMultiplosFilhos.c"


int main() {

    // Ex3 - quickSort
    srand(time(NULL));
    tipo_lista  quick;
    inicializaLista(&quick);    
    quickSort(&quick);
    imprimelista(quick);


    // Ex4 - Arvore MultiplosFilhos
    tipo_arv_multFilhos *arvore;
    arvore = NULL;

    insereArvMultFilhos(&arvore, 1);
    insereArvMultFilhos(&arvore, 2);
    insereArvMultFilhos(&arvore, 4);
    insereArvMultFilhos(&arvore, 8);
    insereArvMultFilhos(&arvore, 16);
    insereArvMultFilhos(&arvore, 32);
    insereArvMultFilhos(&arvore, 100);

    // A soma deve ser igual à 163

    somaArvMultFilhos(arvore);
    return 0;
}