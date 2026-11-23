#include <no_strings_attached/string_trim.h>

namespace no_strings_attached {

std::string Trim(const std::string& str, char char_to_trim, Side side) {
  std::string result = str;

  switch (side) {
    case Side::kLeft:
      result.erase(0, result.find_first_not_of(char_to_trim));
      break;
    case Side::kRight:
      // If everything is char_to_trim, this returns npos, and npos + 1 wraps
      // round to 0, so erase(0) correctly clears the whole string.
      result.erase(result.find_last_not_of(char_to_trim) + 1);
      break;
    case Side::kBoth:
      result.erase(0, result.find_first_not_of(char_to_trim));
      result.erase(result.find_last_not_of(char_to_trim) + 1);
      break;
  }

  return result;
}

std::string Trim(const std::string& str) { return Trim(str, ' ', Side::kBoth); }

}  // namespace no_strings_attached
