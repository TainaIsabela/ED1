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

void percursoPreOrdemArvMultFilhos(tipo_arv_multFilhos *arv);
void percursoPosOrdemArvMultFilhos(tipo_arv_multFilhos *arv);
void imprimePreOrdem(tipo_arv_multFilhos *arv);
void imprimeEmOrdem(tipo_arv_multFilhos *arv);
void imprimeEmPosOrdem(tipo_arv_multFilhos *arv);
tipo_arv_multFilhos *alocaNovoNoArvMultFilhos(int vl);
void insereArvMultFilhos(tipo_arv_multFilhos **arv, int vl);
void percursoPreOrdemMultFilhos(tipo_arv_multFilhos *arv);
void buscarValorArvMultFilhos(tipo_arv_multFilhos *arv, int valor);
int quantidadeArvMultFilhos(tipo_arv_multFilhos *arv);
int calcularAlturaArvMultFilhos(tipo_arv_multFilhos *arv);
void percursoEmOrdemArvMultFilhos(tipo_arv_multFilhos *arv);


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

void buscarValorArvMultFilhos(tipo_arv_multFilhos *arv, int valor) {
  if (arv == NULL) {
    printf("Valor %d nao existe na arvore\n", valor);
    return;
  }
  int i = 0;
  for (i = 0; i < (arv)->contador; i++) {
    if (valor <= (arv)->valores[i]) {
      if (arv->valores[i] == valor) {
        printf("Valor %d encontrado\n", valor);
      } else {
        buscarValorArvMultFilhos((arv)->filhos[i], valor);
      }
      return;
    }
  }
  buscarValorArvMultFilhos((arv)->filhos[i], valor);
}

int quantidadeArvMultFilhos(tipo_arv_multFilhos *arv) {
  int cont = 0;

  if (arv == NULL) {
    return cont;
  } else {
    int i;
    
    cont = arv->contador;
    for (i = 0; i <= arv->contador; i++) {
      cont = cont + quantidadeArvMultFilhos(arv->filhos[i]);
    }
    return cont;
  }
}

int calcularAlturaArvMultFilhos(tipo_arv_multFilhos *arv) {
  int alturaA, alturaB;
  if (arv == NULL) {
    return 0;
  } else {
    int i;
    alturaA = 0;
    for (i = 0; i <= arv->contador; i++) {
      alturaB = calcularAlturaArvMultFilhos(arv->filhos[i]);
    }
    if (alturaB > alturaA) {
      alturaA = alturaB;
    }
  }
  return alturaA + 1;
}

void imprimePreOrdem(tipo_arv_multFilhos *arv) {
  printf("Pre Ordem: [ ");
  percursoPreOrdemArvMultFilhos(arv);
  printf("]\n");
}

void imprimeEmOrdem(tipo_arv_multFilhos *arv) {
  printf("Em Ordem: [ ");
  percursoEmOrdemArvMultFilhos(arv);
  printf("]\n");
}

void imprimeEmPosOrdem(tipo_arv_multFilhos *arv) {
  printf("Pos Ordem: [ ");
  percursoPosOrdemArvMultFilhos(arv);
  printf("]\n");
}

void percursoPreOrdemArvMultFilhos(tipo_arv_multFilhos *arv) {
  if (arv != NULL) {
    int i;
    for (i = 0; i < arv->contador; i++) {
      printf("%d ", arv->valores[i]);
    }
    if (arv->contador == T) {
      for (i = 0; i <= arv->contador; i++)
        percursoPreOrdemArvMultFilhos(arv->filhos[i]);
    }
  }
}

void percursoEmOrdemArvMultFilhos(tipo_arv_multFilhos *arv) {
  int i;
  if (arv != NULL) {
    for (i = 0; i < arv->contador; i++) {
      percursoEmOrdemArvMultFilhos(arv->filhos[i]);
      printf("%d ", arv->valores[i]);
    }
    percursoEmOrdemArvMultFilhos(arv->filhos[i]);
  }
}

void percursoPosOrdemArvMultFilhos(tipo_arv_multFilhos *arv) {
  int i;
  if (arv != NULL) {
    for (i = 0; i < arv->contador + 1; i++) {
      percursoPosOrdemArvMultFilhos(arv->filhos[i]);
    }
    for (i = 0; i < arv->contador; i++) {
      printf("%d ", arv->valores[i]);
    }
  }
}
#endif