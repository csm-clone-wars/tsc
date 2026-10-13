#include "diagnostics.hpp"
#include <string>
#include <utility>
#include <vector>

std::vector<Diagnostic> expand_response_files(std::vector<std::string> &args);

std::pair<Diagnostic, std::vector<std::string>>
parse_response_file(const std::string &filename);