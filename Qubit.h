#ifndef QUBIT_H_INCLUDED
#define QUBIT_H_INCLUDED

#include "Complex.h"
#include <cstdlib>
#include <ctime>

class Qubit {
public:

    Complex values[2];

    Qubit() {
        int BASE = 10000000;
        srand(time(NULL));
        int a,b,c,d;

        a = rand()%(BASE+1);
        b = rand()%(a + 1);
        c = rand()%(BASE - (a + b) + 1);
        d = rand()%(BASE - (a + b + c) + 1);

        values[0].a = sqrt(a/static_cast<real>(BASE));
        values[0].b = sqrt(b/static_cast<real>(BASE));
        values[1].a = sqrt(c/static_cast<real>(BASE));
        values[1].b = sqrt(d/static_cast<real>(BASE));

    }
    Qubit(Complex a, Complex b) {
        values[0] = a;
        values[1] = b;
    }
    ~Qubit() {}

    Qubit X() {
        Qubit q;
        q.values[0] = values[1];
        q.values[1] = values[0];
        return q;
    }

    Qubit Y() {
        Qubit q;
        q.values[0] = values[1]*(-1);
        q.values[1] = values[0];
        return q;
    }

    Qubit Z() {
        Qubit q;
        q.values[0] = values[0];
        q.values[1] = values[1]*(-1);
        return q;
    }

    Qubit T() {
        Qubit q;
        q.values[0] = values[0];
        q.values[1] = Complex(0, -PI/4, true);
        return q;
    }

    Qubit TT() {
        Qubit q;
        q.values[0] = values[0];
        q.values[1] = Complex(0, PI/4, true);
        return q;
    }

    Qubit S() {
        Qubit q;
        q.values[0] = values[0];
        q.values[1] = values[1]*Complex(0, 1);
        return q;
    }

    Qubit ST() {
        Qubit q;
        q.values[0] = values[0];
        q.values[1] = values[1]*Complex(0, -1);
        return q;
    }

    Qubit H() {
        Qubit q;
        q.values[0] = (values[0] + values[1])*(1/sqrt(2));
        q.values[1] = (values[0] + values[1]*Complex(0, -1))*(1/sqrt(2));
        return q;
    }

    real measure() {
        real p = values[0].modulus()*values[0].modulus();
        int BASE = 10000000;
        if( p >= (rand()%(BASE + 1))/static_cast<real>(BASE))
            return 1;
        else
            return 0;
    }

    real measureNeumann() {
        return 1;
    }

    friend ostream & operator<< (ostream &out, const Qubit &q) {
        return out << "[ " << q.values[0] << " " << q.values[1] << " ]" << endl;
        }
};


#endif // QUBIT_H_INCLUDED
