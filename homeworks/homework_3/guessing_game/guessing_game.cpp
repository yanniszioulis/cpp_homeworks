#include <iostream>
#include <string>
#include <array>
#include <map>
#include <random>
using std::cout;
using std::cin;
using std::string_literals::operator""s;

int main() {
    cout << "Welcome to the GUESSING GAME!\nI will generate a number and you will guess it!"s << std::endl;

    int smallest_number{};
    cout << "Please provide the smallest number:"s << std::endl;
    cin >> smallest_number;

    int largest_number{};
    cout << "Please provide the largest number:"s << std::endl;
    cin >> largest_number;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(smallest_number, largest_number);
    int secret_number = dis(gen);

    cout << "I've generated a number. Try to guess it!"s << std::endl;

    bool guessed_correctly = false;
    int no_of_guesses = 0;
    while (!guessed_correctly) {
        int guess{};
        cout << "Please provide the next guess:"s;
        cin >> guess;
        no_of_guesses++;
        if (guess > secret_number) {
            cout << "Your number is too big. Try again!"s << std::endl;
        } else if (guess < secret_number) {
            cout << "Your number is too small. Try again!"s << std::endl;
        } else {
            guessed_correctly = true;
            cout << "You've done it! You guessed the number "s << secret_number << " in "s << no_of_guesses << " guesses!"s << std::endl;
        }
    }
}
