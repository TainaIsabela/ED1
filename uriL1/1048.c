#include <stdlib.h>
#include <stdio.h>

int main(void){
    float salario, salarioReajustado;

    scanf("%f", &salario);

    if (salario >= 0 && salario <= 400) {
      salarioReajustado = salario*1.15;
      printf("Novo salario: %.2f\n", salarioReajustado);
      printf("Reajuste ganho: %.2f\n", salarioReajustado - salario);
      printf("Em percentual: 15 %%\n");
    } else if (salario > 400 && salario <= 800) {
      salarioReajustado = salario*1.12;
      printf("Novo salario: %.2f\n", salarioReajustado);
      printf("Reajuste ganho: %.2f\n", salarioReajustado - salario);
      printf("Em percentual: 12 %%\n");
    } else if (salario > 800 && salario <= 1200) {
      salarioReajustado = salario*1.10;
      printf("Novo salario: %.2f\n", salarioReajustado);
      printf("Reajuste ganho: %.2f\n", salarioReajustado - salario);
      printf("Em percentual: 10 %%\n");
    } else if (salario > 1200 && salario <= 2000) {
      salarioReajustado = salario*1.07;
      printf("Novo salario: %.2f\n", salarioReajustado);
      printf("Reajuste ganho: %.2f\n", salarioReajustado - salario);
      printf("Em percentual: 7 %%\n");
    } else {
      salarioReajustado = salario*1.04;
      printf("Novo salario: %.2f\n", salarioReajustado);
      printf("Reajuste ganho: %.2f\n", salarioReajustado - salario);
      printf("Em percentual: 4 %%\n");
    }

    return 0;
}
