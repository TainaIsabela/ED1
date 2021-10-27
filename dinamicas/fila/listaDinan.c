#include <stdio.h>
#include <stdlib.h>

typedef struct estrutura_no {
  int valor;
  struct estrutura_no *prox;
} tipo_no;

tipo_no *alocaNovoNo(int valor);
void insereFinal(tipo_no **fl, int valor);
tipo_no *insereFinal2(tipo_no *fl, int valor);
void imprimeFila(tipo_no *fl);
int removeInicio(tipo_no **fl);

int main() {
    tipo_no *fila;
    fila = NULL;
    insereFinal(&fila, 8);
    insereFinal(&fila, 15);
    insereFinal(&fila, 20);
    insereFinal(&fila, 21);

    fila = insereFinal2(fila, 39);
    fila = insereFinal2(fila, 41);

    printf("valor removido: %d\n", removeInicio(&fila));
    printf("valor removido: %d\n", removeInicio(&fila));


    imprimeFila(fila);

    return 0;
}

tipo_no *alocaNovoNo(int valor) {
  tipo_no *novo_no;
  novo_no = (tipo_no*) malloc(sizeof(tipo_no));
  novo_no->valor = valor;
  novo_no->prox = NULL;

  return novo_no;
}

void insereFinal( tipo_no **fl, int valor) {
  tipo_no *novo_no;
  novo_no = alocaNovoNo(valor);

  if ( (*fl) == NULL) {
    (*fl) = novo_no;
  } else {
    tipo_no *aux;
    aux = (*fl);
    while( aux->prox != NULL) {
      aux = aux->prox;
    }
    aux->prox = novo_no;
  }
}

tipo_no *insereFinal2(tipo_no *fl, int valor) {
  tipo_no *novo_no, *aux;
  novo_no = alocaNovoNo(valor);
  if( fl == NULL) {
    return novo_no;
  } else {
    aux = fl;
    while(aux->prox != NULL) {
      aux = aux->prox;
    }
    aux->prox = novo_no;
    return fl;
  }
}

void imprimeFila(tipo_no *fl) {
  printf("fila: [ ");
  while(fl != NULL) {
    printf("%d ",fl->valor);
    fl = fl->prox;
  }
  printf("]\n");
}

int removeInicio(tipo_no **fl) {
    if( (*fl) != NULL){
        tipo_no *aux;
        int valor;

        valor = (*fl)->valor;
        aux = *fl;
        (*fl) = (*fl)->prox;
        free(aux);

        return valor;
    } else {
        return -1;
    }
    
}