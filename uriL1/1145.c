#include <stdio.h>

int main() {
    int repeticao, valor, i, contador = 0;

    scanf("%d %d", &repeticao, &valor);
 
    for(i = 1; i <= valor; i++) {
        printf("%d", i);
        contador += 1;
        if (contador == repeticao) {
            printf("\n");
            contador = 0;
        } else 
            printf(" ");
        
    }
    return 0;
}