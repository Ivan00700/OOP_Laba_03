#include <iostream>
#include "../include/point.h"


Point::Point(double x, double y){
    this->x = x;
    this->y = y;
}

std::ostream& operator<<(std::ostream& output, const Point &p) {
    output << "[" << p.x << ", " << p.y << "]";
    return output;
}
        
std::istream& operator>>(std::istream& input, Point &p) {
    input >> p.x >> p.y;
    return input;
}