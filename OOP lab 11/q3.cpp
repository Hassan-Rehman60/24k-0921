#include <iostream>
#include <exception>
using namespace std;

class AbsoluteZeroError : public exception {};

template <typename T>
T convertToFahrenheit(T celsius) {
    if (celsius < static_cast<T>(-273.15)) {
        throw AbsoluteZeroError();
    }
    return (celsius * static_cast<T>(1.8)) + static_cast<T>(32);
}

int main() {
    try {
        cout << "Trying to convert -300°C...\n";
        double temp = convertToFahrenheit(-300.0);
        cout << "Fahrenheit: " << temp << "°F\n";
    } catch (AbsoluteZeroError& err) {
        cout << "Error: temperature below absolute zero!\n";
        cout << "Details: " << err.what() << endl;
    }

    return 0;
}
