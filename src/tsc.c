#include "str.h"
#include <stdio.h>

int main(void) {
  str *name = str_new("Rudra");
  print(name);
  str_free(name);
  return 0;
}