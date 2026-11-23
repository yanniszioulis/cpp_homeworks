#include <no_strings_attached/string_trim.h>

#include <iostream>

int main() {
    std::cout << "Example program that trims strings." << std::endl;

    std::string str;
    std::cout << "Please enter a string:" << std::endl;
    std::getline(std::cin, str);

    const auto trimmed = no_strings_attached::Trim(str);

    std::cout << "Your trimmed string: '" << trimmed << "'" <<std::endl;
    
    return 0;
}