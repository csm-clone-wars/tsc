#include "str.h"
#include <stdio.h>

int main(void) {
  str *name1 = str_new("Rudra");
  str *name2 = str_new("");

  if (str_cmp(name1, name2))
    puts("yep they are equal!");
  return 0;
}