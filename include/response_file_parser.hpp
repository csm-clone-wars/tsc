#include "diagnostics.hpp"
#include <string>
#include <utility>
#include <vector>

std::pair<Diagnostic, std::vector<std::string>>
parse_response_file(const std::string &filename);