#include "diagnostics.hpp"
#include "utils.hpp"
#include <cstddef>
#include <string>
#include <vector>

bool CSM_FUNNY_COMMENTS = env_var_exists("CSM_FUNNY_COMMENTS");

const std::vector<Diagnostic> DIAGNOSTICS = {
    Diagnostic{5083, "Cannot read file '{}'.", "error",
               "Oye, file kitthe hai? 😂"},
    Diagnostic{
        6045, "Unterminated quoted string in response file '{}'.", "error",
        "String close karna nahi aata… aur TypeScript developer ban gaya? "
        "Gajab! 😂"},
    Diagnostic{100000,
               "Too many response files provided. Circular reference suspected "
               "in file '{}'.",
               "error",
               "Bhai, teri file khulte-khulte toh main budha ho jaunga. 😂"},
};

auto create_diagnostic(int code, std::vector<std::string> args) -> Diagnostic {
  for (auto d : DIAGNOSTICS) {
    if (d.code == code) {
      auto msg = d.message;
      size_t pos = 0;
      for (const auto &arg : args) {
        pos = msg.find("{}", pos);
        if (pos == std::string::npos) {
          break;
        }
        msg.replace(pos, 2, arg);
        pos += arg.length();
      }
      d.message = msg;
      return d;
    }
  }
  return Diagnostic{};
}