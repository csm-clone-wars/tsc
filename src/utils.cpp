#include "utils.hpp"
#include <iostream>

// string related
std::string to_lower(std::string s) {
  std::transform(s.begin(), s.end(), s.begin(),
                 [](unsigned char c) { return std::tolower(c); });
  return s;
}
void print(const std::string &s) { std::cout << s << "\n"; }