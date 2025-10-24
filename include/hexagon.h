#pragma once

#include <iostream>
#include "figure.h"


// класс шестиугольника
class Hexagon: public Figure{
    private:
        Point points[6];

    public:
        Hexagon(); // переделано
        Hexagon(const Point &p1, const Point &p2, const Point &p3, const Point &p4, const Point &p5, const Point &p6); // переделано

        void print(std::ostream& output) const override; // переделано
        void read(std::istream& input) override; // переделано
        
        Hexagon& operator=(const Hexagon& other); // переделано
        Hexagon& operator=(const Hexagon&& other) noexcept; // переделано
        bool operator==(const Hexagon& other)const  noexcept;  // переделано

        double area_of_figure() const override;  // переделано
        Point center_of_figure() const override;  // переделано

        ~Hexagon() override = default; // так как точка у нас не динамический объект, то дефолтный деструктор полностью почистит ромб, без утечки памяти
}; 
