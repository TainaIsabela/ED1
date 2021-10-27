/*
UFMT - Ciência da Computação
Estrutura de Dados I
Tainá Isabela Monteiro da Silva - 202011722019

Ex1 - Prova de Estrutura de Dados -> insereOrdenado
Ex2 - Prova de Estrutura de Dados -> removeMaiores
*/


#include <stdio.h>
#include <stdlib.h>

typedef struct estrutura_no {
  int valor;
  struct estrutura_no *prox;
} tipo_no;

tipo_no *alocaNovoNo(int valor);
void insereFinal(tipo_no **fl, int valor);
void imprimeLista(tipo_no *fl);
int removeMaiores(tipo_no **fl, int valor);
void insereOrdenado(tipo_no **lst, int valor);

int main() {
    tipo_no *lista;
    tipo_no *listaOrdenada;
    lista = NULL;
    listaOrdenada = NULL;

    // Ex2 - Remover os números maiores que um valor
    insereFinal(&lista, 8);
    insereFinal(&lista, 15);
    insereFinal(&lista, 20);
    insereFinal(&lista, 21);
    insereFinal(&lista, 25);
    insereFinal(&lista, 30);
    insereFinal(&lista, 35);
    insereFinal(&lista, 40);
    insereFinal(&lista, 45);
    insereFinal(&lista, 50);

    printf("\nLista antes de remover números maiores:\n");
    imprimeLista(lista);

    removeMaiores(&lista, 30);

    printf("\nLista depois de remover números maiores que 30:\n");
    imprimeLista(lista);
    
    // Ex1 - Inserir números em ordem crescente em uma lista
    printf("\nCriando Lista Ordenada de forma crescente...\n"); 
    printf("\nLista Ordenada criada:\n"); 

    insereOrdenado(&listaOrdenada, 8);
    insereOrdenado(&listaOrdenada, 47);
    insereOrdenado(&listaOrdenada, 5);
    insereOrdenado(&listaOrdenada, 20);
    insereOrdenado(&listaOrdenada, 21);
    insereOrdenado(&listaOrdenada, 2);
    insereOrdenado(&listaOrdenada, 0);
    insereOrdenado(&listaOrdenada, 39);
    insereOrdenado(&listaOrdenada, 41);
    
    imprimeLista(listaOrdenada);

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

void imprimeLista(tipo_no *fl) {
  printf("\nLista: [ ");
  while(fl != NULL) {
    printf("%d ",fl->valor);
    fl = fl->prox;
  }
  printf("]\n");
}

// Implementação de função que remove elementos da lista maiores que o valor passado por parametro
int removeMaiores(tipo_no **lst, int valor) {
  if ((*lst) != NULL) { 
    tipo_no *aux = (*lst);
    aux = (*lst);
    while(aux->prox != NULL) { 
      if (aux->prox->valor > valor) { // Nesta condição, se o valor do proximo elemento for maior que o valor passado por parametro, remove o proximo elemento
        tipo_no *aux2 = aux->prox; // Guarda o endereço do proximo elemento
        aux->prox = aux->prox->prox; // O proximo elemento do elemento atual passa a ser o proximo elemento do proximo elemento
        free(aux2);
      } else {
        aux = aux->prox; // senão, apenas avança para o proximo elemento
      }
    }
     } else printf("[ERRO]: Essa lista está vazia");

// Complexidade do algoritmo: O(n²))
}


// Implementação de função que insere um elemento na lista ordenada
void insereOrdenado(tipo_no **lst, int valor) {
  if (valor >= 0) {
    tipo_no *novo_no, *aux;

    novo_no = alocaNovoNo(valor); // Cria um novo nó com o valor passado por parametro

    if ((*lst) == NULL) {  // Se a lista estiver vazia, o novo nó é o primeiro da lista
      novo_no->prox = NULL;
      (*lst) = novo_no;

    } else if (novo_no->valor < (*lst)->valor) { // Se o valor do novo nó for menor que o valor do primeiro elemento da lista, o novo nó é o primeiro da lista
      novo_no->prox = (*lst);
      (*lst) = novo_no;

    } else { // Senão, o novo nó é inserido na lista ordenada
      aux = (*lst);

      while (aux->prox != NULL && novo_no->valor > aux->prox->valor) { // Enquanto o valor do proximo elemento for maior que o valor do novo nó, o novo nó é inserido na lista
        aux = aux->prox;
      }

      novo_no->prox = aux->prox; // O novo nó passa a ser o proximo elemento do elemento atual
      aux->prox = novo_no;
    }
  }
// Complexidade do algoritmo: O(n²))
}