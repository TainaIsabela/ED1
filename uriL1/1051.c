#include <stdlib.h>
#include <stdio.h>

int main(void){
    float valor, montante = 0, resto = 0;

    scanf("%f", &valor);

    if (valor >= 0 && valor <= 2000) {
      printf("Isento\n");
    } else if (valor > 2000 && valor <= 3000) {
        resto = valor - 2000;
        if (resto > 1000)
          resto = valor - 1000;
        montante += resto *.08;
        printf("R$ %.2f\n", montante);
    } else if (valor > 3000 && valor <= 4500) {
        resto = valor - 3000;
        montante += 1000 * .08;
        if (resto > 1500)
          resto -= 1500;
        montante += resto * .18;
        printf("R$ %.2f\n", montante);
    } else {
        resto = valor - 3000;
        montante += 1000 * .08;
        resto -= 1500;
        montante += 1500 * .18;
        montante += resto * .28;
        printf("R$ %.2f\n", montante);
    }
    return 0;
}
