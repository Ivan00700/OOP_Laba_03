#pragma once

#include <iostream>
#include <ostream>
#include "figure.h"

// класс ромба
class Rhomb: public Figure{
    private:
        Point points[4];

    public:
        Rhomb(); 
        Rhomb(const Point &p1, const Point &p2, const Point &p3, const Point &p4); 

        void print(std::ostream& output) const override; 
        void read(std::istream& input) override; 
        /*
        Фигуры должны иметь переопределенные операции копирования (=), перемещения (=) и 
        сравнения (==) 
        */
        Rhomb& operator=(const Rhomb& other);
        Rhomb& operator=(Rhomb&& other) noexcept; 
        bool operator==(const Rhomb& other)const noexcept; 

        double area_of_figure() const override; 
        Point center_of_figure() const override; 

        ~Rhomb() override = default; 
}; 
