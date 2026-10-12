#include "utils.hpp"
#include <cstdlib>
#include <iostream>

// string related
std::string to_lower(std::string s) {
  std::transform(s.begin(), s.end(), s.begin(),
                 [](unsigned char c) { return std::tolower(c); });
  return s;
}
void print(const std::string &s) { std::cout << s << "\n"; }

// environment variables related
bool env_var_exists(const std::string &name) {
  if (std::getenv(name.c_str()) != nullptr) {
    return true;
  }
  return false;
}
