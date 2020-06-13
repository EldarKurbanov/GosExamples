// Created by eldar on 13.06.2020.
//

#ifndef GOSEXAMPLES_COMPLEX_HPP
#define GOSEXAMPLES_COMPLEX_HPP

#include "ostream"

using namespace std;

class Complex {
    double re, im;
public:
    Complex();
    Complex(double R, double Im);

    friend Complex operator/(Complex C, double R);
    friend Complex operator/(double R, Complex C);

    friend ostream& operator<<(ostream &os, Complex const &c);
};


#endif //GOSEXAMPLES_COMPLEX_HPP
