#include <stdio.h>

int main() {
  int i, contador = 0;
  float valor, soma = 0;
  
  for(i=1; i <= 6; i++) {
    scanf("%f", &valor);
    if(valor > 0) {
      soma += valor;
      contador += 1;
    }
  }
  printf("%d valores positivos\n", contador);
  printf("%.1f\n", soma / contador);
  return 0;
}
