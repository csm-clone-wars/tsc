#include "diagnostics.hpp"
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>

auto parse(std::vector<std::string> &args)
    -> std::tuple<std::vector<Diagnostic>, std::vector<std::string>,
                  std::unordered_map<std::string, std::string>,
                  std::unordered_map<std::string, std::string>>;