#include "list.h"
#include "str.h"
#include <stdio.h>

int main(void) {
  list *args = list_new(STR);

  list_free(args);
  args = NULL;
  if (args == NULL) {
    printf("freed\n");
  }
  return 0;
}