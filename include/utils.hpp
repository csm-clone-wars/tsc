#pragma once
#include "diagnostics.hpp"
#include <algorithm>
#include <cctype>
#include <string>
#include <utility>

// strings
std::string to_lower(std::string s);
void print(const std::string &s);

// environment variables
bool env_var_exists(const std::string &name);

// file io
std::pair<Diagnostic, std::string> read_file(const std::string &filename);