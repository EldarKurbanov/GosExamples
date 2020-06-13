//
// Created by eldar on 13.06.2020.
//

#include "Polynom.hpp"

#include <utility>

void Polynom::differentiation() {
    int deg_temp = deg;
    vector<double> new_coeff;
    for (double current_coeff : coeff) {
        new_coeff.push_back(deg_temp * current_coeff);
        if (--deg_temp < 1) break;
    }
    coeff = new_coeff;
    deg--;
}

void Polynom::print() {
    int deg_temp = deg;
    bool first_print = true;
    for (double current_coeff : coeff) {
        if (!first_print) {
            if (current_coeff > 0) cout << "+";
        }
        if (first_print) {
            first_print = false;
        }
        cout << current_coeff;
        if (deg_temp > 0)
             cout << 'x';
        if (deg_temp > 1)
            cout << '^' << deg_temp;
        deg_temp--;
    }
    cout << endl;
}

Polynom::Polynom(vector<double> coeff, int deg) : coeff(move(coeff)), deg(deg) {
    if (this->coeff.size() < deg) {
        cerr << "Размер массива коэффициентов меньше, чем степень многочлена!" << endl;
    }
}
