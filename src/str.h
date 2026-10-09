#include <stddef.h>

typedef struct {
  char *data;
  size_t cap;
  size_t len;
} str;

str *str_new(char *s);
void str_free(str *s);

void print(str *s);