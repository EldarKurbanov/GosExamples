//
// Created by eldar on 13.06.2020.
//

#ifndef GOSEXAMPLES_POLYNOM_HPP
#define GOSEXAMPLES_POLYNOM_HPP

#include <vector>
#include <iostream>

using namespace std;

class Polynom {
public:
    vector<double> coeff;

    Polynom(vector<double> coeff, int deg);

    int deg;

    void differentiation();
    void print();
};


#endif //GOSEXAMPLES_POLYNOM_HPP
