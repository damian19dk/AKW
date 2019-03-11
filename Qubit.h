#ifndef QUBIT_H_INCLUDED
#define QUBIT_H_INCLUDED

#include "Complex.h"

class Qubit {
private:
public:

    Complex values[2][2];

    Qubit() {}
    ~Qubit() {}


    friend ostream & operator<< (ostream &out, const Qubit &q) {
        out << "[ " << q.values[0][0] << " " << q.values[0][1] << " ]" << endl;
        return out << "[ " << q.values[1][0] << " " << q.values[1][1] << " ]" << endl;
        }
};


#endif // QUBIT_H_INCLUDED
