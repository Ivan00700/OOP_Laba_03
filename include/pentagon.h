#pragma once

#include <iostream>
#include "figure.h"


// класс пятиугольника
class Pentagon: public Figure{ 
    private:
        Point points[5];

    public:
        Pentagon(); 
        Pentagon(const Point &p1, const Point &p2, const Point &p3, const Point &p4, const Point &p5); 

        void print(std::ostream& output) const override; 
        void read(std::istream& input) override; 

        Pentagon& operator=(const Pentagon& other); 
        Pentagon& operator=(const Pentagon&& other) noexcept; 
        bool operator==(const Pentagon& other)const  noexcept; 

        double area_of_figure() const override;  
        Point center_of_figure() const override; 

        ~Pentagon() override = default;
}; 
