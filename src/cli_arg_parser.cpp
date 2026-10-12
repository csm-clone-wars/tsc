#include "cli_arg_parser.hpp"
#include "diagnostics.hpp"
#include <iostream>
#include <string>
#include <vector>

void parse(std::vector<std::string> &args) {
  // std::vector<std::string> filenames;
  std::cout << "args size: " << args.size() << "\n";
  auto error = create_diagnostic(5083, {"hello.txt"});
  error.print();
}
