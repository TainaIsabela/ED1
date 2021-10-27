#include <stdio.h>
#include <stdlib.h>

typedef struct estrutura_no {
  int valor;
  struct estrutura_no *prox;
} tipo_no;

tipo_no *alocaNovoNo(int valor);
void insereInicio( tipo_no **lst, int vl);
void insereFim( tipo_no **lst, int vl);
int removeInicio( tipo_no **lst);
int removeFim( tipo_no **lst);
void imprimeLista(tipo_no *lst);


int main() {
    tipo_no *lista;
    lista = NULL;

    insereInicio(&lista, 10);
    insereInicio(&lista, 9);
    insereInicio(&lista, 34);
    insereFim(&lista, 36);
    insereFim(&lista, 47);

    printf("valor removido: %d\n", removeInicio(&lista));
    printf("valor removido: %d\n", removeInicio(&lista));
    printf("valor removido: %d\n", removeFim(&lista));
    printf("valor removido: %d\n", removeFim(&lista));
    imprimeLista(lista);
    return 1;
}

//alocando um novo no
tipo_no *alocaNovoNo(int valor) {
  tipo_no *novo_no;
  novo_no = (tipo_no*) malloc(sizeof(tipo_no));
  novo_no->valor = valor;
  novo_no->prox = NULL;

  return novo_no;
}

//insere no iciio da Lista
void insereInicio( tipo_no **lst, int vl) {
    tipo_no *novo_no;
    novo_no = alocaNovoNo(vl);
    novo_no->prox = (*lst);
    (*lst) = novo_no;
}

void insereFim( tipo_no **lst, int valor) {
  tipo_no *novo_no;
  novo_no = alocaNovoNo(valor);

  if ( (*lst) == NULL) {
    (*lst) = novo_no;
  } else {
    tipo_no *aux;
    aux = (*lst);
    while( aux->prox != NULL) {
      aux = aux->prox;
    }
    aux->prox = novo_no;
  }
}

int removeInicio( tipo_no **lst) {
    if( (*lst) != NULL){
        tipo_no *aux;
        int valor;

        aux = (*lst);
        valor = (*lst)->valor;
        (*lst) = (*lst)->prox;
        free(aux);

        return valor;
    } else {
        return -1;
    }
}

int removeFim( tipo_no **lst) {
    tipo_no *aux, *auxSent;
    int vl;

    if((*lst) != NULL) {
        aux = (*lst);
        while (aux->prox != NULL) {
            auxSent = aux;
            aux = aux->prox;
        }
        vl = aux->valor;
        free(aux);
        auxSent->prox = NULL;
        return vl;
    } else { 
        return -1;
    }
}

void imprimeLista(tipo_no *lst) {
    printf("Lista: [ ");
    while(lst != NULL) {
        printf("%d ",lst->valor);
        lst = lst->prox;
    }
    printf("]\n");
}