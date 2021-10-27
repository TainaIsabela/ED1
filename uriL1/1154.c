#include <stdio.h>

int main() {
    int valor = 0, contador = 0, somatoria = 0;

    while(valor >= 0) {
        scanf("%d", &valor);
        if(valor > 0) {
            somatoria += valor;
            contador += 1;
        }
    }
    printf("%.2f\n", (float)somatoria / contador);
    return 0;
}