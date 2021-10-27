#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct estrutura_no {
  int valor;
  struct estrutura_no *prox;
} tipo_no;

tipo_no *alocaNovoNo(int vl);
void insereInicio(tipo_no **lst, int vl);
void insereFim(tipo_no **lst, int vl);
void inserePosicao(tipo_no **lst, int vl, int pos);
void imprimeLista(tipo_no *lst);
tipo_no *encontraValor(tipo_no *lst, int vl);


int main() {
    tipo_no *lista, *valorInfo;
    lista = NULL;
    valorInfo = NULL;

    insereInicio(&lista, 10);
    insereInicio(&lista, 9);
    insereInicio(&lista, 34);
    insereFim(&lista, 36);
    insereFim(&lista, 47);
    inserePosicao(&lista, 99, 3);
    inserePosicao(&lista, 0, 0);

    valorInfo = encontraValor(lista, 929);
    valorInfo = encontraValor(lista, 99);

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

tipo_no *encontraValor(tipo_no *lst, int vl){
  if(lst != NULL) {
    tipo_no *aux;
    aux = lst;
    int cont = 0;
    bool achou = false;
    while (aux != NULL) {
      if(aux->valor == vl) {
        achou = true;
        break;
      }
      aux = aux->prox;
    }
    if(achou == false){
      printf("Valor nao encontrado na lista\n");
    } else {
        printf("Valor encontrato: %d\n", aux->valor);
        return aux;
      }
  } else {
    printf("[Erro] Lista vazia\n");
  }
}

void imprimeLista(tipo_no *lst) {
  printf("Lista: [ ");

  while (lst != NULL) {
    printf("%d ", lst->valor);
    lst = lst->prox;
  }

  printf("]\n");
}