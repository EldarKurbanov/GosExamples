//
// Created by eldar on 13.06.2020.
//

#ifndef GOSEXAMPLES_POINT_HPP
#define GOSEXAMPLES_POINT_HPP


class Point {
    double x, y;
public:
    Point();
    Point(double X, double Y);
    friend bool operator==(Point P, double R);
    friend bool operator==(double R, Point P);
};


#endif //GOSEXAMPLES_POINT_HPP
