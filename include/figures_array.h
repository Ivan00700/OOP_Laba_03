#pragma once

#include "figure.h"
#include "rhomb.h"
#include "pentagon.h"
#include "hexagon.h"
#include "point.h"
#include <cstddef>
#include <iostream>


// класс Array_of_figures представляет из себя реализацию массива для хранения фигур (в массиве хранятся указатели на фигуры)
class Array_of_figures{
    private:
        size_t number_of_figures; // количество фигур в массиве
        size_t array_capacity; // вместимость массива, по умолчанию вместимость равна пяти эментам 
        Figure **figures;  // указатели на фигуры (если фигур меньше чем вместимость массива, то пустые ячейки заполнены nullptr)

        // дополнительный метод для увеличения вместимости массива
        void resize_capacity(); // реализовано

    public:
        Array_of_figures(); // реализовано
        Array_of_figures(Figure* figure); // реализовано

        void add_figure(Figure* figure); // реализовано
        
        /*
        реализовать!!!
        Вызывать для всего массива общие функции (1-3 см. выше).Т.е. распечатывать для 
        каждой фигуры в массиве геометрический центр и площадь. 
        */
        void area_of_all_figures() const; // реализовано
        void center_of_all_figures() const; // реализовано
        /*
         Необходимо уметь вычислять общую площадь фигур в массиве. 
        */ 
        double area_sum_of_all_figures()const; // реализовано
        
        /*
        Удалять из массива фигуру по индексу;  
        */ 
        bool delete_figure_by_index(size_t index); // реализовано

        Figure* operator[](size_t index); // реализовано

        ~Array_of_figures(); // реализовано

        size_t number_of_figures_value() const; // реализовано (количество фигур)
        size_t capacity_value() const; // реализовано (вместимость массива)
};