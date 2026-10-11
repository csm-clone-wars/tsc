#include "arg_parser.h"
#include "list.h"
#include "str.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool is_build_command(str *s);

int main(int argc, char **argv) {
  // command-line arguments: convert 'argv' into list of 'str'
  list *args = list_new(STR);
  for (int i = 1; i < argc; i += 1) {
    list_append(args, str_new(argv[i]));
  }

  if (args->len != 0 && is_build_command(args->items[0].s)) {
    // build mode
    puts("Build command is not implemented yet!");
    exit(1);
  }

  parse(args);

  list_free(args);
  return 0;
}

bool is_build_command(str *s) {
  str *name = str_copy(s);
  str_lower(name);

  const char *flags[] = {"-build", "--build", "-b", "--b"};
  int flags_len = 4;
  for (int i = 0; i < flags_len; i += 1) {
    if (strcmp(name->data, flags[i]) == 0) {
      str_free(name);
      return true;
    }
  }

  str_free(name);
  return false;
}