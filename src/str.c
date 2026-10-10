#include "str.h"
#include <ctype.h>
#include <stdbool.h>
#include <stddef.h>
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

void str_free(str *s) {
  if (s == NULL) {
    return;
  }

  if (s->data == NULL) {
    free(s);
    return;
  }

  free(s->data);
  free(s);
}

bool str_cmp(str *s1, str *s2) {
  if (strcmp(s1->data, s2->data) == 0) {
    return true;
  }
  return false;
}
void str_lower(str *s) {
  for (size_t i = 0; i < s->len; i += 1) {
    s->data[i] = (char)tolower((unsigned char)s->data[i]);
  }
}

str *str_copy(str *s) {
  if (s == NULL) {
    printf("internal error: str copy failed!");
    exit(1);
  }
  str *copy = str_new(s->data);
  return copy;
}

void print(str *s) { puts(s->data); }
