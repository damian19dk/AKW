#include <iostream>
#include "Complex.h"
#include "Vector.h"

using namespace std;

int main()
{
    Vector<Complex, 3> v1, v2, v3;
    Complex w1[3] = {Complex(1,1), Complex(2,2), Complex(3,3)};
    v1 = Vector<Complex, 3>(w1);
    v2 = Vector<Complex, 3>(w1);


    v3 = v1 + v2;
    cout << v1 << " + " << v2 << " = " << v3 << endl;


    v3 = v1*5;
    cout << v1 << " * " << 5 << " = " << v3 << endl;

    Complex scalar = v1.scalar(v2);
    cout << "<" << v1 << "|" << v2 << "> = " << scalar << endl;

    scalar = v1.norma();
    cout << "||" << v1 << "|| = " << scalar << endl;

    return 0;
}
