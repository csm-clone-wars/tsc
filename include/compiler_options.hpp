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
};

extern const std::vector<CompilerOption> normal_options;
extern const std::vector<CompilerOption> compile_related_options;
extern const std::vector<CompilerOption> build_related_options;
extern const std::vector<CompilerOption> watch_related_options;