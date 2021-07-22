//
// Created by User on 2021/5/3.
//

#ifndef OOP_HW4_POINT_H
#define OOP_HW4_POINT_H


class Point {
public:
    Point();
    Point(double ix, double iy);
    Point(const Point &p);
    bool operator==(const Point &p);
    const double getX() const;
    const double getY() const;
private:
    double x;
    double y;
};


#endif //OOP_HW4_POINT_H
