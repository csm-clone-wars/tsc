#include "utils.hpp"
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

bool is_build_command(std::string s);

int main(int argc, char **argv) {
  std::vector<std::string> args;
  for (int i = 1; i < argc; i += 1) {
    args.push_back(argv[i]);
  }

  if (!args.empty() && is_build_command(args[0])) {
    print("Build command not implemented yet!");
    exit(1);
  }

  return 0;
}

bool is_build_command(std::string s) {
  auto name = to_lower(s);
  auto flags = {"-build", "--build", "-b", "--b"};
  for (auto &flag : flags) {
    if (flag == name) {
      return true;
    }
  }

  return false;
}
