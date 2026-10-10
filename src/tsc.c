#include "list.h"
#include "str.h"
#include <stddef.h>
#include <stdio.h>

int main(int argc, char **argv) {
  list *args = list_new(STR);
  for (int i = 0; i < argc; i += 1) {
    list_append(args, str_new(argv[i]));
  }

  for (size_t i = 0; i < args->len; i += 1) {
    print(args->items[i].s);
  }

  list_free(args);
  return 0;
}