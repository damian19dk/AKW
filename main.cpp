#include <iostream>
#include "Complex.h"

using namespace std;

int main()
{
    Complex a = Complex(1,2);
    Complex b = Complex(2,3);

    cout << "a = " << a << "   |   b = " << b << endl;
    cout << "a + b = " << a + b << endl;
    cout << "a - b = " << a - b << endl;
    cout << "a * b = " << a * b << endl;
    cout << "a / b = " << a / b << endl;

    cout << "Arg(a) = " << a.arg() << endl;
    cout << "Arg(b) = " << b.arg() << endl;

    cout << "a^3 = " << (a^3) << endl;
    cout << "a*a*a = " << a*a*a << endl;
    return 0;
}
