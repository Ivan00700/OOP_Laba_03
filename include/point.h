#pragma once

#include <iostream>
#include <istream>


// класс Point для координаты точки по осям X и Y
class Point{
    public:
        Point(double x=0, double y=0);
        double x;
        double y;
        friend std::ostream& operator<<(std::ostream& output, const Point &p);
        friend std::istream& operator>>(std::istream& input, Point &p);
};