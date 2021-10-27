#include <stdio.h>
#define N 10


typedef struct estrutura_fila {
    int fila[N];
    int contador;
} tipo_fila;

void inicializaFila(tipo_fila *fl);
void insereFila(tipo_fila *fl, int valor);
int removeFila(tipo_fila *fl);
void imprimeFila(tipo_fila fl);

int main() {

    tipo_fila fila;
    inicializaFila(&fila);

    insereFila(&fila, 6);
    insereFila(&fila, 7);
    insereFila(&fila, 9);
    insereFila(&fila, 10);
    insereFila(&fila, 15);

    imprimeFila(fila);

    printf("Removendo valor da fila: %d\n", removeFila(&fila));
    printf("Removendo valor da fila: %d\n", removeFila(&fila));
    printf("Removendo valor da fila: %d\n", removeFila(&fila));
    printf("Removendo valor da fila: %d\n", removeFila(&fila));

    imprimeFila(fila);
    return 0;
}

void inicializaFila(tipo_fila *fl) {
    fl->contador = 0;
}

//Procedimento ( porque não retorna nada ) que insere valores na fila
void insereFila(tipo_fila *fl, int valor) {
    if(fl->contador < N) { //Verifica se há espaõ na fila para poder inserir o valor
        fl->fila[fl->contador++] = valor; //primeiro utiliza o valor do contador, e após utilizar esse valor insere +1
    } else {
        printf("Não foi possivel inserir mais valores porque a fila está cheia\n");
    }
}

//função que remove o primeiro elemento da fila
int removeFila(tipo_fila *fl) {
    if(fl->contador > 0) {
        int aux, i;
        aux = fl->fila[0];

        //atualiza o posicionadomento dos valores no vetor
        for (i = 0; i < fl->contador - 1; i++) {
            fl->fila[i] = fl->fila[i+1];
        }
        fl->contador--;
        return aux;
    } else {
        printf("Não é possivel remover mais nenhum elemento a fila já está vazia\n");
        return -1;
    }
    
}

void imprimeFila(tipo_fila fl) {
    int i;
    
    printf("Fila: [ ");
    for (i = 0; i < fl.contador; i++) {
        printf("%d ", fl.fila[i]);
    }

    printf("]\n");
    
}