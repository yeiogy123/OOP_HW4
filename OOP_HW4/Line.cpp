//
// Created by User on 2021/5/3.
//

#include "Line.h"
Line::Line():a(0),b(0),c(0){}
Line::Line(double ia, double ib, double ic):a(ia),b(ib),c(ic){}
Line::Line(const Line &p):a(p.a),b(p.b),c(p.c){}
bool Line::operator==(const Line &p){
    return (a == p.a) && (b == p.b) && (c == p.c);
}
const double Line::calculate(const Point &p) {
    double value;
    value = p.getX()*(this->a)+p.getY()*(this->b)+(this->c);
    return value;
}
const double Line::getA() const{
    return this->a;
}
const double Line::getB() const{
    return this->b;
}
const double Line::getC() const{
    return this->c;
}