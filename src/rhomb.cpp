#include "../include/rhomb.h"
#include <ostream>


Rhomb::Rhomb(){
    for (int i = 0; i < 4; i++){
        points[i] = Point();
    }
}

Rhomb::Rhomb(const Point &p1, const Point &p2, const Point &p3, const Point &p4){
    points[0] = p1;
    points[1] = p2;
    points[2] = p3;
    points[3] = p4;
}

void Rhomb::read(std::istream& input) {
    for (int i = 0; i < 4; i++) {
        input >> points[i];
    }
}

void Rhomb::print(std::ostream& output)const{
    output << "Rhomb coordinates: ";
    for (int i = 0; i < 4; i++){
        output << points[i];
        if (i == 3){
            break;
        }
        output << " ";
    }
}

Rhomb& Rhomb::operator=(const Rhomb& other){
    if (this != &other){
        for (int i = 0; i < 4; i++){
            points[i] = other.points[i];
        }
    }
    return *this;
}

Rhomb& Rhomb::operator=(Rhomb&& other) noexcept{
    if (this != &other){
        for (int i = 0; i < 4; i++){
            points[i] = std::move(other.points[i]);
        }
    }
    return *this; 
}

bool Rhomb::operator==(const Rhomb& other) const noexcept{
    const Rhomb* other_rhomb = dynamic_cast<const Rhomb*>(&other);
    if (!other_rhomb) {
        return false;
    }
    
    for (int i = 0; i < 4; i++) {
        if (!(points[i].x == other_rhomb->points[i].x && points[i].y == other_rhomb->points[i].y)) {
            return false;
        }
    }
    return true;
}


double Rhomb::area_of_figure() const{
    double diag1, diag2, result_area;
    diag1 = sqrt(pow(points[0].x - points[2].x, 2) + pow(points[0].y - points[2].y, 2));
    diag2 = sqrt(pow(points[1].x - points[3].x, 2) + pow(points[1].y - points[3].y, 2));
    result_area = 0.5 * diag1 * diag2;
    return result_area;
}

Point Rhomb::center_of_figure() const{
    return Point((points[0].x + points[2].x)/2, (points[0].y + points[2].y)/2);
}


