#include <iostream>
#include "../include/figures_array.h"

int main() {
    std::cout << "=== Лабораторная №3: Наследование и полиморфизм ===" << std::endl;
    std::cout << "Доступные фигуры: Rhomb, Pentagon, Hexagon" << std::endl;

    Array_of_figures figures_array;

    while (true) {
        std::cout << "\nМеню:\n";
        std::cout << "1. Добавить фигуру\n";
        std::cout << "2. Вывести все фигуры (координаты)\n";
        std::cout << "3. Вывести площади всех фигур\n";
        std::cout << "4. Вывести центры всех фигур\n";
        std::cout << "5. Вывести суммарную площадь\n";
        std::cout << "6. Удалить фигуру по индексу\n";
        std::cout << "0. Выход\n";
        std::cout << "Ваш выбор: ";

        int choice;
        std::cin >> choice;

        if (choice == 0) {
            break;
        }

        switch (choice) {
            case 1: {
                std::cout << "Выберите тип фигуры (1 - Rhomb, 2 - Pentagon, 3 - Hexagon): ";
                int type;
                std::cin >> type;

                Figure* new_figure = nullptr;

                if (type == 1) {
                    new_figure = new Rhomb();
                    std::cout << "Введите координаты ромба (4 точки x y):\n";
                    std::cin >> *new_figure;
                } else if (type == 2) {
                    new_figure = new Pentagon();
                    std::cout << "Введите координаты пятиугольника (5 точек x y):\n";
                    std::cin >> *new_figure;
                } else if (type == 3) {
                    new_figure = new Hexagon();
                    std::cout << "Введите координаты шестиугольника (6 точек x y):\n";
                    std::cin >> *new_figure;
                } else {
                    std::cout << "Неверный выбор типа фигуры!" << std::endl;
                    break;
                }

                figures_array.add_figure(new_figure);
                std::cout << "Фигура добавлена успешно!" << std::endl;
                break;
            }

            case 2: {
                std::cout << "\n=== Все фигуры ===\n";
                for (size_t i = 0; i < figures_array.number_of_figures_value(); i++) {
                    std::cout << i + 1 << ". " << *figures_array[i] << std::endl;
                }
                break;
            }

            case 3: {
                std::cout << "\n=== Площади всех фигур ===\n";
                figures_array.area_of_all_figures();
                break;
            }

            case 4: {
                std::cout << "\n=== Геометрические центры ===\n";
                figures_array.center_of_all_figures();
                break;
            }

            case 5: {
                std::cout << "\nСуммарная площадь всех фигур: "
                          << figures_array.area_sum_of_all_figures() << std::endl;
                break;
            }

            case 6: {
                std::cout << "Введите индекс фигуры для удаления (начиная с 1): ";
                size_t index;
                std::cin >> index;
                if (figures_array.delete_figure_by_index(index - 1)) {
                    std::cout << "Фигура удалена успешно." << std::endl;
                } else {
                    std::cout << "Ошибка: фигуры с таким индексом не существует." << std::endl;
                }
                break;
            }

            default:
                std::cout << "Неверный пункт меню!" << std::endl;
        }
    }

    std::cout << "\nЗавершение программы..." << std::endl;
    return 0;
}
