#include "cli_arg_parser.hpp"
#include "utils.hpp"
#include <iostream>

std::tuple<std::vector<Diagnostic>, std::vector<std::string>,
           std::unordered_map<std::string, std::string>,
           std::unordered_map<std::string, std::string>>
parse(std::vector<std::string> &args) {
  std::vector<std::string> filenames;
  std::vector<Diagnostic> errors;
  std::unordered_map<std::string, std::string> options;
  std::unordered_map<std::string, std::string> watch_options;

  std::cout << "args size: " << args.size() << "\n";
  auto [error, content] = read_file("hello.txt");
  if (error.message != "") {
    error.print();
  } else {
    print(content);
  }
  return {errors, filenames, options, watch_options};
}
