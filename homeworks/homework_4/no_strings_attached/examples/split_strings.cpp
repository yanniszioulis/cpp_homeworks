#include <no_strings_attached/string_split.h>

#include <iostream>

int main() {
  std::cout << "Example program that splits strings." << std::endl;

  std::string str;
  std::cout << "Please enter a string:" << std::endl;
  std::getline(std::cin, str);

  const auto parts = no_strings_attached::Split(str, " ");

  std::cout << "Your split string:";
  for (const auto& part : parts) { std::cout << " '" << part << "'"; }
  std::cout << std::endl;

  return 0;
}