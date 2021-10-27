#include <stdio.h>

int main() {
    int qtd, valor, i;

    scanf("%d", &qtd);

    for(i = 1; i <= qtd; i++) {
        scanf("%d", &valor);
        if(valor % 2 == 0 && valor != 0) {
            if(valor > 0)
                printf("EVEN POSITIVE\n");
            else
                printf("EVEN NEGATIVE\n");
        } else if ( valor == 0)
            printf("NULL\n");
        else
            if(valor > 0)
                printf("ODD POSITIVE\n");
            else
                printf("ODD NEGATIVE\n");
    }

    return 0;
}