#ifndef COMPLEX_H_INCLUDED
#define COMPLEX_H_INCLUDED

#include<iostream>
#include<cmath>

typedef double real;

using namespace std;

class Complex {
public:
    real a, b;

    Complex():a(0), b(0) {}
    Complex(real arg1, real arg2):a(arg1), b(arg2) {}
    ~Complex() {}

    real re() {
        return a;
    }

    real im() {
        return b;
    }

    real modulus() {
        return sqrt(a*a + b*b);
    }

    Complex conjugate() {
        return Complex(a, -b);
    }

    Complex power(Complex k) {

    }

    // Adding

    Complex operator+(Complex arg1) {
        return Complex(a + arg1.a, b + arg1.b);
    }

    // Substrating

    Complex operator-(Complex arg1) {
        return Complex(a - arg1.a, b - arg1.b);
    }

    // Multiplying

    Complex operator*(Complex arg1) {
        return Complex(a*arg1.a - b*arg1.b, a*arg1.b + b*arg1.a);
    }

    // Dividing

    Complex operator/(Complex arg1) {
        return Complex((a*arg1.a + b*arg1.b)/(arg1.a*arg1.a + arg1.b*arg1.b), (b*arg1.a - a*arg1.b)/(arg1.a*arg1.a + arg1.b*arg1.b));
    }

    // Cout operator
    friend ostream & operator<< (ostream &out, const Complex &c) {
        return out << c.a << " + " << c.b << "i";
        }
};



#endif // COMPLEX_H_INCLUDED
