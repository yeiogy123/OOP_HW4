//
// Created by User on 2021/5/3.
//

#include "Point.h"
Point::Point():x(0),y(0){};
Point::Point(double ix, double iy):x(ix), y(iy){}
Point::Point(const Point &p):x(p.x),y(p.y){}
bool Point::operator==(const Point &p){
    return (x == p.x) && (y == p.y);
}
const double Point::getX() const{
    return this->x;
}
const double Point::getY() const{
    return (*this).y;
}
