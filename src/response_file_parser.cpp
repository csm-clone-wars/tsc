#include "response_file_parser.hpp"
#include "diagnostics.hpp"
#include "utils.hpp"
#include <cstddef>
#include <string>
#include <vector>

auto expand_response_files(std::vector<std::string> &args)
    -> std::vector<Diagnostic> {
  std::vector<Diagnostic> errors = {};

  size_t files_count = 0;

  size_t x = 0;
  while (x < args.size()) {
    if (args[x].starts_with("@")) {
      files_count += 1;
      auto filename = args[x].substr(1);
      if (files_count > 200) {
        // circular reference error in response file
        auto error = create_diagnostic(100000, {filename});
        errors.push_back(error);
        args.erase(args.begin() + x);
        return errors;
      }

      auto [parse_error, temp_args] = parse_response_file(filename);
      if (parse_error.message != "") {
        errors.push_back(parse_error);
        args.erase(args.begin() + x);
        continue;
      } else {
        args.erase(args.begin() + x);
        args.insert(args.begin() + x, temp_args.begin(), temp_args.end());
        continue;
      }
    }
    x += 1;
  }

  return errors;
}

auto parse_response_file(const std::string &filename)
    -> std::pair<Diagnostic, std::vector<std::string>> {
  auto parse_error = Diagnostic{};
  std::vector<std::string> args;

  // read file to string
  auto [read_error, content] = read_file(filename);
  if (read_error.message != "") {
    // cannot read file error
    parse_error = read_error;
    return {parse_error, args};
  }

  size_t x = 0;
  while (x < content.length()) {
    if (content[x] <= 32) {
      // skip ASCII whitespace and control characters
    } else if (content[x] == '"') {
      // parse quoted string
      auto end_quote = false;
      size_t y = x + 1;
      while (y < content.length()) {
        if (content[y] == '"') {
          end_quote = true;
          break;
        }
        y += 1;
      }

      if (end_quote) {
        args.push_back(content.substr(x + 1, y - x - 1));
        x = y + 1;
        continue;
      } else {
        // unterminated quoted string in response file error
        parse_error = create_diagnostic(6045, {filename});
        return {parse_error, args};
      }
    } else {
      // parse unquoted string
      size_t y = x;
      while (y < content.length() && content[y] > 32) {
        y += 1;
      }

      args.push_back(content.substr(x, y - x));
      x = y;
      continue;
    }
    x += 1;
  }

  return {parse_error, args};
}
