#include <no_strings_attached/string_split.h>

namespace no_strings_attached {

std::vector<std::string> Split(const std::string& str,
                               const std::string& delimiter) {
    std::vector<std::string> parts;
    std::size_t start = 0;

    if (delimiter.empty()) {
        return {str};  
    }

    while (true) {
        size_t end = str.find(delimiter, start);
        if (end == std::string::npos) {
            parts.push_back(str.substr(start));
            break;
        }
        parts.push_back(str.substr(start, end - start));
        start = end + delimiter.length();
    }
    return parts;
}

std::vector<std::string> Split(const std::string& str, 
                               const std::string& delimiter, 
                               int number_of_chunks_to_keep){

    if (number_of_chunks_to_keep < 0) {
        return {};  
    }

    auto parts = Split(str, delimiter);

    const auto keep = std::min(number_of_chunks_to_keep, static_cast<int>(parts.size()));
    return {parts.begin(), parts.begin() + keep};
}

} // namespace no_strings_attached