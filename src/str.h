#include <stdbool.h>
#include <stddef.h>

typedef struct {
  char *data;
  size_t cap;
  size_t len;
} str;

str *str_new(char *s);
void str_free(str *s);

bool str_cmp(str *s1, str *s2);

void print(str *s);