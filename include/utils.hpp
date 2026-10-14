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
auto env_var_exists(const std::string &name) -> bool;

// file io
auto read_file(const std::string &filename)
    -> std::pair<Diagnostic, std::string>;