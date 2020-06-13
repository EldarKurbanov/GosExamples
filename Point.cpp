//
// Created by eldar on 13.06.2020.
//

#include "Point.hpp"

Point::Point() {
    x = y = 0;
}

Point::Point(double X, double Y) : x(X), y(Y) {
}

bool operator==(Point P, double R) {
    return P.x == R && P.y == R;
}

bool operator==(double R, Point P) {
    return P.x == R && P.y == R;
}