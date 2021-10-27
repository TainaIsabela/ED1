#include <stdio.h>
#include <stdlib.h>

#include "arvBinaria.c"

int main() {
  tipo_arv_binaria *arvore;
  arvore = criarArvbinaria();

  insereArvbinaria(&arvore, 15);
  insereArvbinaria(&arvore, 5);
  insereArvbinaria(&arvore, 19);
  insereArvbinaria(&arvore, 3);
  insereArvbinaria(&arvore, 9);
  insereArvbinaria(&arvore, 8);

  imprimeEmOrdem(arvore);

  buscarValorArvbinaria(&arvore, 9);
  buscarValorArvbinaria(&arvore, 832);
  removerValorArvbinaria(&arvore, 8);

  imprimeEmOrdem(arvore);
  removerValorArvbinaria(&arvore, 53);
  
  printf("Quantidade: %d\n", quantidadeNosArvbinaria(arvore));
  printf("Altura Arvore: %d\n", calcularAlturaArvbinaria(arvore));
  imprimeNosFolha(arvore);
  imprimeNivel(arvore, 1);
  imprimeNivel(arvore, 2);
  imprimePreOrdem(arvore);
  imprimeEmOrdem(arvore);
  imprimePosOrdem(arvore);
  return 0;
}
