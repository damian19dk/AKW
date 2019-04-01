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
        int val[4];

        val[0] = rand()%(BASE+1);
        val[1] = rand()%(val[0] + 1);
        val[2] = rand()%(BASE - (val[0] + val[1]) + 1);
        val[3] = rand()%(BASE - (val[0] + val[1] + val[2]) + 1);

        int r[4] = {-1, -2, -3 ,-4};
        int i = 0;
        bool withoutRepeat = true;
        while(i < 4) {
            r[i] = rand()%4;

            for(int j = 0; j < i; j++) {
                if(r[j] == r[i]) {
                    withoutRepeat = false;
                    break;
                }
                else
                    withoutRepeat = true;
            }
            if(withoutRepeat) {
                i++;
                withoutRepeat = false;
            }
        }

        values[0].a = sqrt(val[r[0]]/static_cast<real>(BASE));
        values[0].b = sqrt(val[r[1]]/static_cast<real>(BASE));
        values[1].a = sqrt(val[r[2]]/static_cast<real>(BASE));
        values[1].b = sqrt(val[r[3]]/static_cast<real>(BASE));

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
        real alpha = values[0].modulus()*values[0].modulus();
        int BASE = 10000000;
        if(alpha >= (rand()%(BASE + 1))/static_cast<real>(BASE))
            return 1;
        else
            return 0;
    }

    real alphaPropability() {
        return values[0].modulus()*values[0].modulus();
    }

    friend ostream & operator<< (ostream &out, const Qubit &q) {
        return out << "[ " << q.values[0] << " " << q.values[1] << " ]" << endl;
        }
};


#endif // QUBIT_H_INCLUDED
