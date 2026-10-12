#include "utils.hpp"
#include "diagnostics.hpp"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

// strings
std::string to_lower(std::string s) {
  std::transform(s.begin(), s.end(), s.begin(),
                 [](unsigned char c) { return std::tolower(c); });
  return s;
}
void print(const std::string &s) { std::cout << s << "\n"; }

// environment variables
bool env_var_exists(const std::string &name) {
  if (std::getenv(name.c_str()) != nullptr) {
    return true;
  }
  return false;
}

// file io
std::pair<Diagnostic, std::string> read_file(const std::string &filename) {
  auto error = Diagnostic{};
  std::string content = "";
  std::ifstream file(filename);

  if (!file) {
    error = create_diagnostic(5083, {filename});
    return {error, content};
  }

  std::stringstream buffer;
  buffer << file.rdbuf();
  content = buffer.str();

  return {error, content};
}
