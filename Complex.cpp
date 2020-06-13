//
// Created by eldar on 13.06.2020.
//

#include "Complex.hpp"

Complex::Complex() {
    re = im = 0;
}

Complex::Complex(double R, double I) : re(R), im(I) {
}

Complex operator/(Complex C, double R) {
    Complex temp;
    double r = R * R;
    temp.re = C.re * R / r;
    temp.im = C.im * R / r;
    return temp;
}

Complex operator/(double R, Complex C) {
    Complex temp;
    double r = C.re * C.re + C.im * C.im;
    temp.re = R * C.re / r;
    temp.im = - R * C.im / r;
    return temp;
}

ostream &operator<<(ostream &os, const Complex &c)  {
    return os << c.re << " + " << c.im << 'i';
}