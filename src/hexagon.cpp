#include "../include/hexagon.h"
#include <ostream>


Hexagon::Hexagon(){
    for (int i = 0; i < 6; i++){
        points[i] = Point();
    }
}

Hexagon::Hexagon(const Point &p1, const Point &p2, const Point &p3, const Point &p4, const Point &p5, const Point &p6){
    points[0] = p1;
    points[1] = p2;
    points[2] = p3;
    points[3] = p4;
    points[4] = p5;
    points[5] = p6;
}

void Hexagon::read(std::istream& input) {
    for (int i = 0; i < 6; i++) {
        input >> points[i];
    }
}

void Hexagon::print(std::ostream& output)const{
    output << "Hexagon coordinates: ";
    for (int i = 0; i < 6; i++){
        output << points[i];
        if (i == 5){
            break;
        }
        output << " ";
    }
}

Hexagon& Hexagon::operator=(const Hexagon& other){
    if (this != &other){
        for (int i = 0; i < 6; i++){
            points[i] = other.points[i];
        }
    }
    return *this;
}

Hexagon& Hexagon::operator=(const Hexagon&& other) noexcept{
    if (this != &other){
        for (int i = 0; i < 6; i++){
            points[i] = std::move(other.points[i]);
        }
    }
    return *this; 
}

bool Hexagon::operator==(const Hexagon& other)const noexcept{
    const Hexagon* other_rhomb = dynamic_cast<const Hexagon*>(&other);
    if (!other_rhomb) {
        return false;
    }
    
    for (int i = 0; i < 6; i++) {
        if (!(points[i].x == other_rhomb->points[i].x && points[i].y == other_rhomb->points[i].y)) {
            return false;
        }
    }
    return true;
}


double Hexagon::area_of_figure() const{
    double side, result;
    side = sqrt(pow(points[0].x - points[1].x, 2) + pow(points[0].y - points[1].y, 2));
    result = (3 * sqrt(3) * pow(side, 2)) / 2; 
    return result;
}

Point Hexagon::center_of_figure() const{
    return Point((points[0].x + points[3].x)/2, (points[0].y + points[3].y)/2);
}


