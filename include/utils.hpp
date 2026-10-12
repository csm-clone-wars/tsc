#pragma once
#include <algorithm>
#include <cctype>
#include <string>

// strings
std::string to_lower(std::string s);
void print(const std::string &s);

// environment variables
bool env_var_exists(const std::string &name);