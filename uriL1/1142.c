#include <stdio.h>

int main() {
    int valor, i;

    scanf("%d", &valor);
 
    for(i = 1;i <= valor*4;i += 4) {
        printf("%d ", i);
        printf("%d ", i+1);
        printf("%d ",i+2);
        printf("PUM\n");
    }

    return 0;
}