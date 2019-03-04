#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#include <string.h>
#include "Complex.h"


using namespace std;

template <ui SIZE>
class Vector {
public:
    ui length;
    Complex vec_array[SIZE];

    Vector():length(SIZE) {}
    Vector(Complex* vec):length(SIZE) {
        memcpy(vec_array,vec, sizeof(Complex)*SIZE);
    }

    Vector(const Vector& vec):length(vec.length) {
        for(unsigned int i = 0; i < length; i++)
            vec_array[i] = vec.vec_array[i];
    }

    ~Vector() {}

    Vector operator+(Vector arg1) {
        Vector vec;
        for(unsigned int i = 0; i < this->length; i++)
            vec.vec_array[i] = vec_array[i] + arg1.vec_array[i];
        return vec;
    }

    Vector operator*(real arg1) {
        Vector vec(vec_array);
        for(unsigned int i = 0; i < length; i++)
            vec.vec_array[i] = vec.vec_array[i]*arg1;
        return vec;
    }

    Complex scalar (Vector arg1) {
        Complex sum;
        for(unsigned int i = 0; i < length; i++)
            sum += vec_array[i]*arg1.vec_array[i].conjugate();
        return sum;
    }

    Complex norma() {
        return Complex(sqrt(this->scalar(*this).re()),0);
    }

    // Cout operator
    friend ostream & operator<< (ostream &out, const Vector &c) {
        out << "[ ";
        for(unsigned int i = 0; i < c.length; i++)
            out << c.vec_array[i] << " ";
        return out << "]";
        }
};

#endif // VECTOR_H_INCLUDED
