#include "diagnostics.hpp"
#include <string>
#include <utility>
#include <vector>

auto expand_response_files(std::vector<std::string> &args)
    -> std::vector<Diagnostic>;

auto parse_response_file(const std::string &filename)
    -> std::pair<Diagnostic, std::vector<std::string>>;