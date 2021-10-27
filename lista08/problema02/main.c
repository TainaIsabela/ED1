#include <stdio.h>
#include <stdlib.h>

#include "arvmMultiplosFilhos.c"

int main() {
  tipo_arv_multFilhos *arvore;
  arvore = NULL;

  insereArvMultFilhos(&arvore, 5);
  insereArvMultFilhos(&arvore, 8);
  insereArvMultFilhos(&arvore, 4);
  insereArvMultFilhos(&arvore, 17);
  insereArvMultFilhos(&arvore, 28);
  insereArvMultFilhos(&arvore, 4);
  insereArvMultFilhos(&arvore, 1);
  insereArvMultFilhos(&arvore, 3);
  insereArvMultFilhos(&arvore, 2);
  insereArvMultFilhos(&arvore, 5);

  buscarValorArvMultFilhos(arvore, 17);
  buscarValorArvMultFilhos(arvore, 1);
  buscarValorArvMultFilhos(arvore, 1874);

  printf("Quantidade: %d\n", quantidadeArvMultFilhos(arvore));
  printf("Altura arvore: %d\n", calcularAlturaArvMultFilhos(arvore));
  imprimePreOrdem(arvore);
  imprimeEmOrdem(arvore);
  imprimeEmPosOrdem(arvore);
  return 0;
}
