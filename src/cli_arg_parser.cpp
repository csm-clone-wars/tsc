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

  auto response_file_errors = expand_response_files(args);
  auto circular_reference_error = false;
  if (!response_file_errors.empty()) {
    for (auto err : response_file_errors) {
      if (err.code == 100000) {
        circular_reference_error = true;
        break;
      }
    }
  }
  errors.insert(errors.end(), response_file_errors.begin(),
                response_file_errors.end());
  if (circular_reference_error) {
    return {errors, filenames, options, watch_options};
  }

  print("hello!");

  return {errors, filenames, options, watch_options};
}
