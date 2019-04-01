#include <iostream>
#include "Vector.h"
#include "Qubit.h"

using namespace std;

int main()
{
    Complex a = Complex(1, 0);
    Complex b = Complex(0, 1);
    Qubit q;
    int measure;
    int positive = 0, negative = 0;
    const int MAX_COUNTER = 1000;


    cout << q << " => " << q.alphaPropability() << endl;
    for(int i = 0; i < MAX_COUNTER; i++) {
        measure = q.measure();
        cout << "#" << i << " => " << measure << endl;
        if(measure == 1)
            positive++;
        else
            negative++;
    }

    cout << "1 => " << positive/static_cast<real>(MAX_COUNTER) << endl;
    cout << "0 => " << negative/static_cast<real>(MAX_COUNTER) << endl;
    return 0;
}
