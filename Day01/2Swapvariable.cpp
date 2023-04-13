#include <iostream>
using namespace std;

int main()
{
    // swap number without using third variable
    int a = 0;
    int b = 0;
    cout << "Enter the value of a: ";
    cin >> a;
    cout << "Enter the value of b: ";
    cin >> b;
    cout << "Befor Swap "
         << " a:" << a << " b:" << b << endl;
    a = a + b;
    b = a - b;
    a = a - b;
    cout << "After Swap "
         << " a:" << a << " b:" << b << endl;
    return 0;
}