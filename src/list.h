#pragma once

#include "str.h"
#include <stddef.h>

typedef enum { STR } ListType;
typedef union {
  str *s;
} ListItem;

typedef struct {
  ListType type;
  ListItem *items;
  size_t cap;
  size_t len;
} list;

list *list_new(ListType type);