#pragma once
#include <algorithm>
#include <cctype>
#include <string>

// string related
std::string to_lower(std::string s);
void print(const std::string &s);

// environment variables related
bool env_var_exists(const std::string &name);