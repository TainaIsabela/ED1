#include <stdio.h>
#include <stdlib.h>

typedef struct estrutura_no {
  int valor;
  struct estrutura_no *prox;
} tipo_no;

tipo_no *alocaNovoNo(int vl);
void insereInicio(tipo_no **lst, int vl);
void insereFim(tipo_no **lst, int vl);
void imprimeLista(tipo_no *lst);
void liberarNos(tipo_no **lst);


int main() {
    tipo_no *lista;
    lista = NULL;


    insereInicio(&lista, 10);
    insereInicio(&lista, 9);
    insereInicio(&lista, 34);
    insereFim(&lista, 36);
    insereFim(&lista, 47);
    liberarNos(&lista); //Não entendi exatamente se é liberando nó a nó em uma função que é considerado "de uma vez só"
    //caso for só liberando a cabeça comment a linha acima e descomente a de baixo
    //free(lista); 

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
void liberarNos(tipo_no **lst) {
  tipo_no *aux, *auxSent;
  if ((*lst) != NULL) {
    aux = (*lst);
    while (aux->prox != NULL) {
      auxSent = aux;
      free(auxSent);
      aux = aux->prox;
    }
    free(aux);
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