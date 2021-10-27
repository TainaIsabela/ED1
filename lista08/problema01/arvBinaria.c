#ifndef ARVBINARIA_C
#define ARVBINARIA_C

#include <stdio.h>

typedef struct str_arv {
  struct str_arv *esq;
  struct str_arv *dir;
  int valor;
} tipo_arv_binaria;

void imprimeNivel(tipo_arv_binaria *arv, int nivel);
void ImprimeNivelArvbinaria(tipo_arv_binaria *arv, int nivel, int proxNivel);
void insereArvbinaria(tipo_arv_binaria **arv, int valor);
void removerValorArvbinaria(tipo_arv_binaria **arv, int valor);
void buscarValorArvbinaria(tipo_arv_binaria **arv, int valor);
int quantidadeNosArvbinaria(tipo_arv_binaria *arv);
void percursoPosOrdem(tipo_arv_binaria *arv);
void imprimeNosFolha(tipo_arv_binaria *arv);
void imprimeNosFolhasArvbinaria(tipo_arv_binaria *arv);
void imprimePreOrdem(tipo_arv_binaria *arv);
void percursoPreOrdem(tipo_arv_binaria *arv);
int calcularAlturaArvbinaria(tipo_arv_binaria *arv);
tipo_arv_binaria *alocaNovoVoArvbinaria(int valor);
tipo_arv_binaria *criarArvbinaria();
void imprimeEmOrdem(tipo_arv_binaria *arv);
void percursoEmOrdem(tipo_arv_binaria *arv);
void imprimePosOrdem(tipo_arv_binaria *arv);

tipo_arv_binaria *alocaNovoVoArvbinaria(int valor) {
  tipo_arv_binaria *novoNo;
  novoNo = (tipo_arv_binaria *)malloc(sizeof(tipo_arv_binaria));
  novoNo->valor = valor;
  novoNo->esq = NULL;
  novoNo->dir = NULL;
  return novoNo;
}

tipo_arv_binaria *criarArvbinaria() {
  tipo_arv_binaria *arvore;
  arvore = NULL;

  return arvore;
}

void insereArvbinaria(tipo_arv_binaria **arv, int valor) {
  if ((*arv) == NULL) {
    (*arv) = alocaNovoVoArvbinaria(valor);
  } else {
    if (valor < (*arv)->valor) {
      insereArvbinaria(&(*arv)->esq, valor);
    } else {
      insereArvbinaria(&(*arv)->dir, valor);
    }
  }
}

void removerValorArvbinaria(tipo_arv_binaria **arv, int valor) {
  if ((*arv) == NULL) {
    printf("O valor %d nao existe na arvore\n", valor);
    return;
  }
  if (valor < (*arv)->valor) {
    removerValorArvbinaria(&(*arv)->esq, valor);
  } else if (valor > (*arv)->valor) {
    removerValorArvbinaria(&(*arv)->dir, valor);
  } else {
    tipo_arv_binaria *aux = (*arv);
    if (((*arv)->esq == NULL) && ((*arv)->dir == NULL)) {
      free(aux);
      (*arv) = NULL;
      printf("Valor %d removido com sucesso\n", valor);
    } else {
      if ((*arv)->esq == NULL) {
        (*arv) = (*arv)->dir;
        aux->dir = NULL;
        free(aux);
        aux = NULL;
        printf("Valor %d removido com sucesso\n", valor);
      } else {
        if ((*arv)->dir == NULL) {
          (*arv) = (*arv)->esq;
          aux->esq = NULL;
          free(aux);
          aux = NULL;
          printf("Valor %d removido com sucesso\n", valor);
        }
      }
    }
  }
}

void buscarValorArvbinaria(tipo_arv_binaria **arv, int valor) {
  if ((*arv) == NULL) {
    printf("Valor %d nao existe na arvore\n", valor);
    return;
  }
  if (valor < (*arv)->valor) {
    buscarValorArvbinaria(&(*arv)->esq, valor);
  } else if (valor > (*arv)->valor) {
    buscarValorArvbinaria(&(*arv)->dir, valor);
  } else {
    printf("Valor %d encontrado\n", valor);
  }
}

int quantidadeNosArvbinaria(tipo_arv_binaria *arv) {
  if (arv == NULL) {
    return 0;
  } else {
    int qtd = 1;
    qtd += quantidadeNosArvbinaria(arv->esq) + quantidadeNosArvbinaria(arv->dir);
    return qtd;
  }
}

int calcularAlturaArvbinaria(tipo_arv_binaria *arv) {
  int alturaE, alturaD;

  if (arv == NULL) {
    return 0;
  } else {
    alturaE = calcularAlturaArvbinaria(arv->esq);
    alturaD = calcularAlturaArvbinaria(arv->dir);
    if (alturaE > alturaD)
      return (alturaE + 1);
    else
      return (alturaD + 1);
  }
}

void imprimeNosFolhasArvbinaria(tipo_arv_binaria *arv) {
  if ((arv) != NULL) {
    imprimeNosFolhasArvbinaria((arv)->esq);
    imprimeNosFolhasArvbinaria((arv)->dir);
    if ((arv)->esq == NULL && (arv)->dir == NULL) {
      printf("%d ", (arv)->valor);
    }
  }
}

void ImprimeNivelArvbinaria(tipo_arv_binaria *arv, int nivel, int proxNivel) {
  if (arv != NULL) {
    ImprimeNivelArvbinaria(arv->esq, nivel, proxNivel + 1);
    ImprimeNivelArvbinaria(arv->dir, nivel, proxNivel + 1);
    if (nivel == proxNivel) {
      printf("%d ", arv->valor);
    }
  }
}

void imprimeNivel(tipo_arv_binaria *arv, int nivel) {
  printf("Dados do nivel %d: [ ", nivel);
  ImprimeNivelArvbinaria(arv, nivel, 0);
  printf("]\n");
}

void imprimeNosFolha(tipo_arv_binaria *arv) {
  printf("Nos Folha: [ ");
  imprimeNosFolhasArvbinaria(arv);
  printf("]\n");
}

void imprimePreOrdem(tipo_arv_binaria *arv) {
  printf("Pre Ordem: [ ");
  percursoPreOrdem(arv);
  printf("]\n");
}

void imprimeEmOrdem(tipo_arv_binaria *arv) {
  printf("Em Ordem: [ ");
  percursoEmOrdem(arv);
  printf("]\n");
}

void imprimePosOrdem(tipo_arv_binaria *arv) {
  printf("Pos Ordem: [ ");
  percursoPosOrdem(arv);
  printf("]\n");
}

void percursoPreOrdem(tipo_arv_binaria *arv) {
  if (arv != NULL) {
    printf("%d ", arv->valor);
    percursoPreOrdem(arv->esq);
    percursoPreOrdem(arv->dir);
  }
}

void percursoEmOrdem(tipo_arv_binaria *arv) {
  if (arv != NULL) {
    percursoEmOrdem(arv->esq);
    printf("%d ", arv->valor);
    percursoEmOrdem(arv->dir);
  }
}

void percursoPosOrdem(tipo_arv_binaria *arv) {
  if (arv != NULL) {
    percursoPosOrdem(arv->esq);
    percursoPosOrdem(arv->dir);
    printf("%d ", arv->valor);
  }
}
#endif