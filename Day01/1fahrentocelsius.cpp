#include <iostream>
using namespace std;

int main()
{
    // fahrenheit to celsius
    double fahrenheit = 0.0;
    double celsius = 0.0;
    cout << "Enter the temperature in fahrenheit: ";
    cin >> fahrenheit;
    celsius = (fahrenheit - 32) * 5 / 9;
    cout << "The temperature in celsius is: " << celsius << endl;
    return 0;
}
