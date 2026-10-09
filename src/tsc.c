#include "str.h"
#include <stdio.h>

int main(void) {
  str *name = str_new("Rudra");

  str_lower(name);
  print(name);
  return 0;
}