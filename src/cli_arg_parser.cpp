#include "cli_arg_parser.hpp"
#include "response_file_parser.hpp"
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

  std::cout << "args size: " << args.size() << "\n\n";
  auto response_file_errors = expand_response_files(args);
  if (!response_file_errors.empty()) {
    for (auto err : response_file_errors) {
      err.print();
    }
  } else {
    for (auto arg : args) {
      print(arg);
    }
  }

  return {errors, filenames, options, watch_options};
}
