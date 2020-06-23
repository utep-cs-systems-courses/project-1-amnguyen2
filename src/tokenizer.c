#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int main() {
  char str[200];
  printf("> Enter a word.\n");
  printf("< ");
  fgets(str, sizeof(str), stdin);
  printf("\n> You entered: %s\n", str);
  
  return 0;
}
