#ifndef COMPLEX_H_INCLUDED
#define COMPLEX_H_INCLUDED

#include<iostream>
#include<cmath>

typedef double real;
typedef unsigned int ui;

using namespace std;

#define PI 3.14159265

class Complex {
public:
    real a, b;

    Complex():a(0), b(0) {}
    Complex(real arg1, real arg2, bool isTrygonometric = false):a(arg1), b(arg2)
    {
        if(isTrygonometric) {
            a = arg1*cos(arg2);
            b = arg1*sin(arg2);
        }
     }

    ~Complex() {}

    real re() { return a; }
    real im() { return b; }
    real arg() { return atan2(b,a); }
    real modulus() { return sqrt(a*a + b*b); }
    Complex conjugate() { return Complex(a, -b); }

    Complex operator+(Complex arg1) {
        return Complex(a + arg1.a, b + arg1.b);
    }

    void operator+=(Complex arg1) {
        a += arg1.a;
        b += arg1.b;
    }

    Complex operator-(Complex arg1) {
        return Complex(a - arg1.a, b - arg1.b);
    }

    Complex operator*(Complex arg1) {
        return Complex(a*arg1.a - b*arg1.b, a*arg1.b + b*arg1.a);
    }

    Complex operator*(real arg1) {
        return Complex(a*arg1, b*arg1);
    }

    Complex operator/(Complex arg1) {
        return Complex((a*arg1.a + b*arg1.b)/(arg1.a*arg1.a + arg1.b*arg1.b), (b*arg1.a - a*arg1.b)/(arg1.a*arg1.a + arg1.b*arg1.b));
    }

    Complex operator^(int k) {
        return Complex(cos(k*arg()), sin(k*arg()))*pow(modulus(), k);
    }

    friend ostream & operator<< (ostream &out, const Complex &c) {
        return out << "(" << c.a << "," << c.b << ")";
        }
};

#endif // COMPLEX_H_INCLUDED
