#pragma once

#include <cstddef>
#include <iostream>
#include <cmath>
#include <istream>
#include <ostream>
#include "point.h"


// класс Figure, от которого уже потом будут наследоваться классы ромба, пятиугольника и шестиугольника
class Figure{
    public:
        Figure() = default;

        virtual void print(std::ostream& output) const = 0;
        virtual void read(std::istream& input) = 0; 
        friend std::ostream& operator<<(std::ostream& output, Figure &figure);
        friend std::istream& operator>>(std::istream& input, Figure &figure);

        virtual double area_of_figure() const = 0; 
        virtual Point center_of_figure() const = 0; 

        virtual ~Figure() = default;
};