#include <stdlib.h>
#include <stdio.h>

int main(){
  int i = 1;
  for(; i <= 100; i++) {
    if(i % 2 == 0) {
      printf("%d\n", i);
    }
  }
  return 0;
}
