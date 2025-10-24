#include "../include/figure.h"
#include <ostream>


std::ostream& operator<<(std::ostream& output, Figure &figure){
    figure.print(output);
    return  output;
}

std::istream& operator>>(std::istream& input, Figure &figure){
    figure.read(input);
    return input;
}

