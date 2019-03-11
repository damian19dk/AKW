#include <iostream>
#include "Vector.h"
#include "Qubit.h"

using namespace std;

int main()
{
    Complex a = Complex(1, 0);
    Complex b = Complex(0, 1);
    Qubit q;
    cout << q << endl;
    cout << q.measure() << endl;
    return 0;
}
