#include "list.h"
#include "str.h"
#include <stdio.h>

int main(void) {
  list *args = list_new(STR);

  printf("%zu\n", args->len);
  return 0;
}