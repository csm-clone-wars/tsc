#include "str.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

str *str_new(char *text) {
  if (text == NULL) {
    text = "";
  }
  str *s = malloc(sizeof(str));
  if (s == NULL) {
    printf("internal error: heap memory allocation failed!");
    exit(1);
  }

  s->len = strlen(text);
  s->cap = (s->len * 2) + 1;
  s->data = malloc(s->cap * sizeof(char));
  if (s->data == NULL) {
    free(s);
    printf("internal error: heap memory allocation failed!");
    exit(1);
  }
  strcpy(s->data, text);

  return s;
}

void print(str *s) { puts(s->data); }
