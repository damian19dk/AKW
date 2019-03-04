#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#include <iostream>

using namespace std;

typedef double real;


template <typename T, int SIZE>
class Vector {
public:
    T vec_array[SIZE];
    unsigned int length;

    Vector():length(SIZE) {}
    Vector(T* vec):length(SIZE) {
        for(unsigned int i = 0; i < length; i++) {
            vec_array[i] = vec[i];
        }
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

    T scalar (Vector arg1) {
        T sum;
        for(unsigned int i = 0; i < length; i++)
            sum += vec_array[i]*arg1.vec_array[i].conjugate();
        return sum;
    }

    T norma() {
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
