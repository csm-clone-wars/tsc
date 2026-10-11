#include <iostream>
#include <string>
#include <vector>

int main(int argc, char **argv) {
  std::vector<std::string> args;
  for (int i = 1; i < argc; i += 1) {
    args.push_back(argv[i]);
  }

  for (auto arg : args) {
    std::cout << arg << "\n";
  }
  return 0;
}
