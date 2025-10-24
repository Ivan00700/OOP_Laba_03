#include "../include/pentagon.h"
#include <math.h>
#include <ostream>
#include <sys/types.h>


Pentagon::Pentagon(){
    for (int i = 0; i < 5; i++){
        points[i] = Point();
    }
}

Pentagon::Pentagon(const Point &p1, const Point &p2, const Point &p3, const Point &p4, const Point &p5){
    points[0] = p1;
    points[1] = p2;
    points[2] = p3;
    points[3] = p4;
    points[4] = p5;
}

void Pentagon::read(std::istream& input) {
    for (int i = 0; i < 5; i++) {
        input >> points[i];
    }
}

void Pentagon::print(std::ostream& output)const{
    output << "Pentagon coordinates: ";
    for (int i = 0; i < 5; i++){
        output << points[i];
        if (i == 4){
            break;
        }
        output << " ";
    }
}

Pentagon& Pentagon::operator=(const Pentagon& other){
    if (this != &other){
        for (int i = 0; i < 5; i++){
            points[i] = other.points[i];
        }
    }
    return *this;
}

Pentagon& Pentagon::operator=(const Pentagon&& other) noexcept{
    if (this != &other){
        for (int i = 0; i < 5; i++){
            points[i] = std::move(other.points[i]);
        }
    }
    return *this; 
}

bool Pentagon::operator==(const Pentagon& other)const noexcept{
    const Pentagon* other_rhomb = dynamic_cast<const Pentagon*>(&other);
    if (!other_rhomb) {
        return false;
    }
    
    for (int i = 0; i < 5; i++) {
        if (!(points[i].x == other_rhomb->points[i].x && points[i].y == other_rhomb->points[i].y)) {
            return false;
        }
    }
    return true;
}


double Pentagon::area_of_figure() const{
    double side, result;
    side = sqrt(pow(points[0].x - points[1].x, 2) + pow(points[0].y - points[1].y, 2));
    result = 5 * 0.5 * side* (side * sqrt(3)/2);
    return result;
}

Point Pentagon::center_of_figure() const{
    double x_sum = 0.0, y_sum = 0.0;
    for (int i = 0; i < 5; i++){
        x_sum += points[i].x;
        y_sum += points[i].y;
    }
    return Point((x_sum)/5, (y_sum)/5);
}


