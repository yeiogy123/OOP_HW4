//
// Created by User on 2021/5/3.
//

#ifndef OOP_HW4_LINE_H
#define OOP_HW4_LINE_H
#include "Point.h"

class Line {
public:
    Line();
    Line(double ia, double ib, double ic);
    Line(const Line &p);
    bool operator==(const Line &p);
    const double calculate(const Point &p);
    const double getA() const;
    const double getB() const;
    const double getC() const;

private:
    double a;
    double b;
    double c;
};


#endif //OOP_HW4_LINE_H
