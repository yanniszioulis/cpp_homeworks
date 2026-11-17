#include <iostream>
#include <string>
#include <array>
#include <map>
using std::cout;
using std::cin;
using std::string_literals::operator""s;

const std::map noun_map{
    std::pair{"spring"s, "STL guru"s},
    std::pair{"summer"s, "C++ expert"s},
    std::pair{"autumn"s, "coding beast"s},
    std::pair{"winter"s, "software design hero"s}
};

const std::array endings{"eats UB for breakfast"s, "finds errors quicker than the compiler"s, "is not afraid of C++ error messages"s};

int main() {
    cout << "Welcome to the fortune teller program!"s << std::endl;

    cout << "Please enter your name:"s << std::endl;
    std::string name{};
    cin >> name;

    cout << "Please enter the time of year when you were born:"s << std::endl;
    cout << "(pick from 'spring', 'summer', 'autumn', 'winter')"s << std::endl;
    std::string born_season{};
    cin >> born_season;

    cout << "Please enter an adjective:"s << std::endl;
    std::string adjective_1{};
    cin >> adjective_1;

    cout << "Please enter another adjective:"s << std::endl;
    std::string adjective_2{};
    cin >> adjective_2;

    const std::array adjectives{adjective_1, adjective_2};
    
    cout << "\nHere is your description:"s << std::endl;
    cout << name << ", the "s << adjectives.at(name.size() % 2) << " "s << noun_map.at(born_season) << " that "s << endings.at(name.size() % 3) << std::endl;
}