#include <stdio.h>
#include <stdlib.h>

typedef struct estrutura_no {
  int valor;
  struct estrutura_no *prox;
} tipo_no;

tipo_no *alocaNovoNo(int vl);
void insereInicio(tipo_no **lst, int vl);
void insereFim(tipo_no **lst, int vl);
void inserePosicao(tipo_no **lst, int vl, int pos);
int removeInicio(tipo_no **lst);
int removeFim(tipo_no **lst);
void imprimeLista(tipo_no *lst);
int removePosicao(tipo_no **, int pos);

int main() {
    tipo_no *lista;
    lista = NULL;

    insereInicio(&lista, 10);
    insereInicio(&lista, 9);
    insereInicio(&lista, 34);
    insereFim(&lista, 36);
    insereFim(&lista, 47);

    imprimeLista(lista);
    return 1;
}

tipo_no *alocaNovoNo(int vl) {
  tipo_no *novo_no;
  novo_no = (tipo_no *)malloc(sizeof(tipo_no));
  novo_no->valor = vl;
  novo_no->prox = NULL;

  return novo_no;
}

void insereInicio(tipo_no **lst, int vl) {
  tipo_no *novo_no;
  novo_no = alocaNovoNo(vl);

  if ((*lst) == NULL) {
    (*lst) = novo_no;
  } else {
    novo_no->prox = (*lst);
    (*lst) = novo_no;
  }
}

void insereFim(tipo_no **lst, int vl) {
  tipo_no *novo_no;
  novo_no = alocaNovoNo(vl);

  if ((*lst) == NULL) {
    (*lst) = novo_no;
  } else {
    tipo_no *aux;
    aux = (*lst);
    while (aux->prox != NULL) {
      aux = aux->prox;
    }

    aux->prox = novo_no;
  }
}

void inserePosicao(tipo_no **lst, int vl, int pos) {
  tipo_no *novo_no, *aux, *auxSent;
  int contador = 0;
  if (pos == 0) {
    insereInicio(lst, vl);
  } else {
    aux = (*lst);
    while (aux != NULL && contador < pos) {
      auxSent = aux;
      aux = aux->prox;
      contador++;
    }
    if (contador == pos && aux != NULL) {
      novo_no = alocaNovoNo(vl);
      novo_no->prox = aux;
      auxSent->prox = novo_no;
    } else if (contador == pos && aux == NULL) {
      insereFim(lst, vl);
    } else {
      printf("[ERRO] Posicao %d invalida para insercao de valor na lista\n", pos);
    }
  }
}

int removeInicio(tipo_no **lst) {
  tipo_no *aux;
  int vl;
  if (*lst != NULL) {
    vl = (*lst)->valor;
    aux = (*lst);
    (*lst) = (*lst)->prox;
    free(aux);
  } else {
    return -1;
  }

  return vl;
}

int removeFim(tipo_no **lst) {
  tipo_no *aux, *auxSent;
  int vl;
  if ((*lst) != NULL) {
    aux = (*lst);
    while (aux->prox != NULL) {
      auxSent = aux;
      aux = aux->prox;
    }
    vl = aux->valor;
    free(aux);
    auxSent->prox = NULL;
  }
  return vl;
}

int removePosicao(tipo_no **lst, int pos) {
  tipo_no *novo_no, *aux, *auxSent;
  int contador = 0, vl = -1;
  if (pos == 0) {
    removeInicio(lst);
  } else {
    aux = (*lst);
    while (aux != NULL && contador < pos) {
      auxSent = aux;
      aux = aux->prox;
      contador++;
    }
    if (aux != NULL) {
      vl = aux->valor;
      auxSent->prox = aux->prox;
      free(aux);
    } else {
      printf("[ERRO] Posicao %d invalida para remocao de valor na lista\n", pos);
    }
  }
  return vl;
}

void imprimeLista(tipo_no *lst) {
  printf("Lista: [ ");

  while (lst != NULL) {
    printf("%d ", lst->valor);
    lst = lst->prox;
  }

  printf("]\n");
}