#include <stdio.h>

int main() {
    int i, j, contador = 0;
    char acao;
    float m[12][12], soma = 0;

    scanf("%c", &acao);

    for(i = 0; i < 12; i++) {
        for(j = 0; j < 12; j++) {
            scanf("%f", &m[i][j]);
            if(j > i && j != 0) {
                soma += m[i][j];
                contador += 1;
            }
        }
    }

    if(acao == 'S')
        printf("%f\n", soma);
    else
        printf("%.1f\n", soma / contador);

    return 0;
}