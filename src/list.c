#include "list.h"
#include "str.h"
#include <stddef.h>
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

void list_free(list *l) {
  if (l == NULL) {
    return;
  }

  if (l->len == 0) {
    free(l);
    return;
  }

  for (size_t i = 0; i < l->len; i += 1) {
    if (l->type == STR) {
      str_free(l->items[i].s);
    }
  }

  free(l->items);
  free(l);
}

// void list_append(list *l, void *value) {
//   if (l == NULL || value == NULL) {
//     puts("internal error: dynamic list append failed!");
//     exit(1);
//   }

//   ListItem item;
//   if (l->type == STR) {
//     item.s = (str *)value;
//   }

//   l->len += 1;
//   if (l->cap < l->len) {
//     l->cap = l->len * 2;
//   }
//   l->items = realloc(l->items, l->cap * sizeof(ListItem));
//   if (l->items == NULL) {
//   }
// }
