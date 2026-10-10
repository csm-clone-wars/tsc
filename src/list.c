#include "list.h"
#include <stdio.h>
#include <stdlib.h>

list *list_new(ListType type) {
  list *l = malloc(sizeof(list));
  if (l == NULL) {
    puts("internal error: dynamic list allocation failed!");
    exit(1);
  }

  l->type = type;
  l->cap = 0;
  l->len = 0;
  l->items = NULL;

  return l;
}
