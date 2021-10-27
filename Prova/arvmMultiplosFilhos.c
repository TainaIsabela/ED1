/*
UFMT - Ciência da Computação
Estrutura de Dados I
Tainá Isabela Monteiro da Silva - 202011722019
*/

#include <stdio.h>
#include <stdlib.h>

#ifndef ARVMULTIPLOSFILHOS_C
#define ARVMULTIPLOSFILHOS_C

#define T 3

typedef struct str_arv_multfilhos {
  int valores[T];
  struct str_arv_multfilhos *filhos[T + 1];
  int contador;
} tipo_arv_multFilhos;

void imprimeEmPosOrdem(tipo_arv_multFilhos *arv);
tipo_arv_multFilhos *alocaNovoNoArvMultFilhos(int vl);
void insereArvMultFilhos(tipo_arv_multFilhos **arv, int vl);
int somaArvMultFilhos(tipo_arv_multFilhos *arv);


tipo_arv_multFilhos *alocaNovoNoArvMultFilhos(int vl) {
  tipo_arv_multFilhos *novoNo;
  int i;
  novoNo = (tipo_arv_multFilhos *)malloc(sizeof(tipo_arv_multFilhos));
  novoNo->valores[0] = vl;
  novoNo->contador = 1;
  for (i = 0; i < T + 1; i++) {
    novoNo->filhos[i] = NULL;
  }
  return novoNo;
}

void insereArvMultFilhos(tipo_arv_multFilhos **arv, int valor) {
  int i;

  if ((*arv) == NULL) {
    (*arv) = alocaNovoNoArvMultFilhos(valor);
  } else {
    if ((*arv)->contador < T) {
      i = (*arv)->contador - 1;

      while ((i >= 0) && ((*arv)->valores[i] > valor)) {
        (*arv)->valores[i + 1] = (*arv)->valores[i];
        i--;
      }
      (*arv)->valores[i + 1] = valor;
      (*arv)->contador++;

    } else {
      i = 0;
      while ((i < T) && ((*arv)->valores[i] < valor)) {
        i++;
      }
      insereArvMultFilhos(&(*arv)->filhos[i], valor);
    }
  }
}


// somaArvMultFilhos printf("Soma: %d\n", soma);
// Somar todos os valores da árvore
int somaArvMultFilhos(tipo_arv_multFilhos *arv) {
  int soma = 0;
  if (arv != NULL) {
    int i;
    for (i = 0; i < arv->contador; i++) { // percorre os valores
      soma = soma + arv->valores[i]; // soma recebe o valor atual + a soma anterior
    }
    if (arv->contador == T) { // se o contador for igual ao tamanho do vetor
      for (i = 0; i <= arv->contador; i++) { // percorre os filhos
        soma = soma + somaArvMultFilhos(arv->filhos[i]); // soma recebe o valor atual + a soma anterior
      }
    }
  }
  printf("Soma: %d\n", soma); // imprime a soma, porém até percorrer todos os valores vai printar a soma anterior
  return soma;
  // Complexidade do algoritmo: O(n log (n))
}
#endif