#include "../include/figures_array.h"
#include <cstddef>
#include <new>


Array_of_figures::Array_of_figures(){
    this->array_capacity = 5;
    this->number_of_figures = 0;
    this->figures = new Figure*[array_capacity];
    for (size_t i = 0; i < array_capacity; i++){
        figures[i] = nullptr;
    }
}

Array_of_figures::Array_of_figures(Figure* figure){
    this->array_capacity = 5;
    this->number_of_figures = 1;
    figures = new Figure*[array_capacity];
    for (size_t i = 0; i < array_capacity; i++){
        if (i == 0){
            figures[i] = figure;
        } else {
            figures[i] = nullptr;
        }   
    }
}

Array_of_figures::~Array_of_figures(){
    for (size_t i = 0; i < array_capacity; i++){
        delete figures[i];
        figures[i] = nullptr;
    }
    delete[] figures;
    this->array_capacity = 0;
    this->number_of_figures = 0;
    figures = nullptr;
}


void Array_of_figures::add_figure(Figure *figure){
    if (figures[array_capacity - 1] != nullptr){
        resize_capacity();
    }

    figures[number_of_figures] = figure;
    number_of_figures++;
}

bool Array_of_figures::delete_figure_by_index(size_t index){

    // for (size_t i = index; i < (array_capacity - 1); i++){
    //     figures[i] = figures[i+1];
    // }
    // number_of_figures--;
    // return true;
    
    if (index >= number_of_figures){
        return false;
    }
    delete figures[index];
    
    for (size_t i = index; i < number_of_figures - 1; i++){
        figures[i] = figures[i + 1];
    }
    
    figures[number_of_figures - 1] = nullptr;
    number_of_figures--;
    
    return true;
}

void Array_of_figures::resize_capacity(){
    size_t new_capacity = (this->array_capacity) * 2;
    Figure **new_figures = new Figure*[new_capacity];

    for (size_t i = 0; i < array_capacity; i++){
        new_figures[i] = figures[i]; 
    }
    for (size_t j = array_capacity; j < new_capacity; j++){
        new_figures[j] = nullptr; 
    }
    
    delete[] figures;
    figures = new_figures;
    array_capacity = new_capacity;
}


size_t Array_of_figures::capacity_value() const {
    return this->array_capacity;
}

size_t Array_of_figures::number_of_figures_value() const {
    return this->number_of_figures;
}

Figure* Array_of_figures::operator[](size_t index){
    if (index > (number_of_figures - 1)){
        return nullptr;
    }
    return figures[index];
}

double Array_of_figures::area_sum_of_all_figures()const{
    double area_sum = 0.0;
    for (int i = 0; i < (number_of_figures); i++){
        area_sum += figures[i]->area_of_figure();
    }
    return area_sum;
}


void Array_of_figures::area_of_all_figures()const{
    for (int i = 0; i < number_of_figures; i++){
        const char* figure = "";
        if (dynamic_cast<Rhomb*>(figures[i])){
            figure = "Rhomb";
        } else if (dynamic_cast<Pentagon*>(figures[i])){
            figure = "Pentagon";
        } else if (dynamic_cast<Hexagon*>(figures[i])){
            figure = "Hexagon";
        }
        std::cout << "Figure: " << figure << std::endl;
        std::cout << "Area: " << figures[i]->area_of_figure() << std::endl;
    }
}

void Array_of_figures::center_of_all_figures()const{
    for (int i = 0; i < number_of_figures; i++){
        const char* figure = "";
        if (dynamic_cast<Rhomb*>(figures[i])){
            figure = "Rhomb";
        } else if (dynamic_cast<Pentagon*>(figures[i])){
            figure = "Pentagon";
        } else if (dynamic_cast<Hexagon*>(figures[i])){
            figure = "Hexagon";
        }
        std::cout << i + 1 << "Figure: " << figure << std::endl;
        std::cout << "Center: " << figures[i]->center_of_figure() << std::endl;
    }
}