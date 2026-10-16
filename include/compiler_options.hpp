#include <string>
#include <unordered_map>
#include <vector>
struct CompilerOption {
  std::string name;
  std::string short_name;
  bool is_tsconfig_only;
  std::string
      value_type; // string,number,boolean("true","false","null"),list(strings-vector)
  std::vector<std::string> accepted_values;
  std::vector<std::string>
      default_values; // one or more depends on the value_type
  std::unordered_map<std::string, std::string> meta_info;
  std::vector<std::string> option_type; // build,watch,command-line,compile
};

extern const std::vector<CompilerOption> compiler_options;