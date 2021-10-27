#include <stdio.h>
#define N 10

typedef struct estrutura_lista {
    int lista[N];
    int contador;
} tipo_lista;

void inicializaLista(tipo_lista *lst);
void insereNoFimDaLista(tipo_lista *lst, int valor);
void insereNoInicioDaLista(tipo_lista *lst, int valor);
void insereEmPosicaoEspecificaDaLista(tipo_lista *lst, int valor, int posicao);
void imprimelista(tipo_lista lst);
int removeNoFimDaLista(tipo_lista *lst);
int removeNoInicioDaLista(tipo_lista *lst);
int removeEmPosicaoEspecificaDaLista(tipo_lista *lst, int posicao);


int main() {
    tipo_lista lista;
    inicializaLista(&lista);

    insereNoFimDaLista(&lista, 7);
    insereNoFimDaLista(&lista, 10);

    insereNoInicioDaLista(&lista, 2);
    insereNoInicioDaLista(&lista, 1);

    insereEmPosicaoEspecificaDaLista(&lista, 4, 2);
    insereEmPosicaoEspecificaDaLista(&lista, 12, 5);

    insereNoFimDaLista(&lista, 13);

    insereEmPosicaoEspecificaDaLista(&lista, 0, 0);

    imprimelista(lista);

    printf("Valor [ %d ] removido\n", removeNoFimDaLista(&lista));
    imprimelista(lista);
    printf("Valor [ %d ] removido\n", removeNoInicioDaLista(&lista));
    imprimelista(lista);
    printf("Valor [ %d ] removido\n", removeEmPosicaoEspecificaDaLista(&lista, 4));
    imprimelista(lista);
    printf("Valor [ %d ] removido\n", removeEmPosicaoEspecificaDaLista(&lista, 2));
    printf("Valor [ %d ] removido\n", removeEmPosicaoEspecificaDaLista(&lista, 2));
    printf("Valor [ %d ] removido\n", removeEmPosicaoEspecificaDaLista(&lista, 2));

    imprimelista(lista);
    return 0;
}


void inicializaLista(tipo_lista *lst) {
    lst->contador = 0;
}

void insereNoInicioDaLista(tipo_lista *lst, int valor) {
    if(lst->contador < N) {
        int i;
        
        for (i = lst->contador; i > 0; i--) {
            lst->lista[i] = lst->lista[i - 1];
        }
        lst->lista[0] = valor;
        lst->contador++;
    } else {
        printf("Não foi possivel inserir mais valores porque a lista está cheia\n");
    }
}

//insere No fim da lista
void insereNoFimDaLista(tipo_lista *lst, int valor) {
    if(lst->contador < N) {
        lst->lista[lst->contador++] = valor;
    } else {
        printf("Não foi possivel inserir mais valores porque a lista está cheia\n");
    }
}

void insereEmPosicaoEspecificaDaLista(tipo_lista *lst, int valor, int posicao) {
    if(lst->contador < N) {
        if(posicao >= 0 && posicao <= lst->contador) {
            int i;
            for (i = lst->contador - 1; i >= posicao; i--) {
                lst->lista[i+1] = lst->lista[i];
            }
            lst->lista[i + 1] = valor;
            lst->contador++;
        } else {
            printf("Não foi possivel inserir o valor [ %d ], por que ocasionaria espaços em branco\n", valor);
        }
    } else {
        printf("Não foi possivel inserir mais valores porque a lista está cheia\n");
    }
}

void imprimelista(tipo_lista lst) {
    int i;
    
    printf("Lista: [ ");
    for (i = 0; i < lst.contador; i++) {
        printf("%d ", lst.lista[i]);
    }

    printf("]\nContador = %d\n", lst.contador);
    
}

int removeNoFimDaLista(tipo_lista *lst) {
    if(lst->contador > 0) {
        return lst->lista[--lst->contador];
    } else {
        printf("Não é possivel remover mais nenhum elemento a lista já está vazia\n");
        return -1;
    }
}

int removeNoInicioDaLista(tipo_lista *lst) {
    if(lst->contador > 0) {
        int aux, i;
        aux = lst->lista[0];

        //atualiza o posicionadomento dos valores no vetor
        for (i = 0; i < lst->contador - 1; i++) {
            lst->lista[i] = lst->lista[i+1];
        }
        lst->contador--;
        return aux;
    } else {
        printf("Não é possivel remover mais nenhum elemento a lista já está vazia\n");
        return -1;
    }
}

int removeEmPosicaoEspecificaDaLista(tipo_lista *lst, int posicao) {
    if(lst->contador > 0) {
        if(posicao >= 0 && posicao < lst->contador){
            int aux, i;
            aux = lst->lista[posicao];

            //atualiza o posicionadomento dos valores no vetor
            for (i = posicao; i < lst->contador - 1; i++) {
                lst->lista[i] = lst->lista[i+1];
            }
            lst->contador--;
            return aux;
        } else {
            printf("Posição invalida para remoção\n");
            return -1;
        }
    } else {
        printf("Não é possivel remover mais nenhum elemento a lista já está vazia\n");
        return -1;
    }
}