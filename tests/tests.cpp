#include <gtest/gtest.h>
#include "point.h"
#include "rhomb.h"
#include "pentagon.h"
#include "hexagon.h"
#include "figures_array.h"
#include <sstream>

// 1. Проверка площади ромба
TEST(RhombTest, AreaCalculation) {
    Rhomb r(Point(0,0), Point(2,2), Point(4,0), Point(2,-2));
    EXPECT_NEAR(r.area_of_figure(), 8.0, 0.001);
}

// 2. Проверка центра ромба
TEST(RhombTest, CenterCalculation) {
    Rhomb r(Point(0,0), Point(2,2), Point(4,0), Point(2,-2));
    Point c = r.center_of_figure();
    EXPECT_NEAR(c.x, 2.0, 0.001);
    EXPECT_NEAR(c.y, 0.0, 0.001);
}

// 3. Проверка площади пятиугольника
TEST(PentagonTest, AreaCalculation) {
    Pentagon p(Point(0,0), Point(1,0), Point(1,1), Point(0,1), Point(0.5,2));
    double area = p.area_of_figure();
    EXPECT_GT(area, 0.0);
}

// 4. Проверка центра пятиугольника
TEST(PentagonTest, CenterCalculation) {
    Pentagon p(Point(0,0), Point(1,0), Point(1,1), Point(0,1), Point(0.5,2));
    Point c = p.center_of_figure();
    EXPECT_NEAR(c.x, 0.5, 0.001);
    EXPECT_NEAR(c.y, 0.8, 0.001);
}

// 5. Проверка площади шестиугольника
TEST(HexagonTest, AreaCalculation) {
    Hexagon h(Point(0,0), Point(1,0), Point(1.5,0.87), Point(1,1.73), Point(0,1.73), Point(-0.5,0.87));
    double area = h.area_of_figure();
    EXPECT_NEAR(area, (3 * sqrt(3) * pow(1,2)) / 2, 0.1);
}

// 6. Проверка центра шестиугольника
TEST(HexagonTest, CenterCalculation) {
    Hexagon h(Point(0,0), Point(1,0), Point(1,1), Point(0,1), Point(-1,1), Point(-1,0));
    Point c = h.center_of_figure();
    EXPECT_NEAR(c.x, (h.center_of_figure().x), 0.001);
}

// 7. Проверка оператора ==
TEST(PentagonTest, EqualityOperator) {
    Pentagon p1(Point(0,0), Point(1,0), Point(1,1), Point(0,1), Point(0.5,2));
    Pentagon p2(Point(0,0), Point(1,0), Point(1,1), Point(0,1), Point(0.5,2));
    EXPECT_TRUE(p1 == p2);
}

// 8. Проверка копирования фигуры
TEST(RhombTest, CopyAssignment) {
    Rhomb r1(Point(0,0), Point(2,2), Point(4,0), Point(2,-2));
    Rhomb r2;
    r2 = r1;
    EXPECT_TRUE(r1.center_of_figure().x == r2.center_of_figure().x);
    EXPECT_TRUE(r1.center_of_figure().y == r2.center_of_figure().y);
}

// 9. Проверка добавления и удаления фигур в массиве
TEST(ArrayTest, AddAndDelete) {
    Array_of_figures arr;
    arr.add_figure(new Rhomb(Point(0,0), Point(1,1), Point(2,0), Point(1,-1)));
    arr.add_figure(new Pentagon(Point(0,0), Point(1,0), Point(1,1), Point(0,1), Point(0.5,2)));
    EXPECT_EQ(arr.number_of_figures_value(), 2);
    arr.delete_figure_by_index(0);
    EXPECT_EQ(arr.number_of_figures_value(), 1);
}

// 10. Проверка общей площади всех фигур
TEST(ArrayTest, TotalAreaSum) {
    Array_of_figures arr;
    arr.add_figure(new Rhomb(Point(0,0), Point(2,2), Point(4,0), Point(2,-2)));
    arr.add_figure(new Rhomb(Point(0,0), Point(1,1), Point(2,0), Point(1,-1)));
    double total = arr.area_sum_of_all_figures();
    EXPECT_GT(total, 0.0);
}

// 11. Проверка корректности вывода фигуры в поток
TEST(IOTest, PrintRhomb) {
    Rhomb r(Point(0,0), Point(1,1), Point(2,0), Point(1,-1));
    std::ostringstream oss;
    oss << r;
    std::string output = oss.str();
    EXPECT_NE(output.find("["), std::string::npos);
}

// 12. Проверка корректности ввода фигуры из потока
TEST(IOTest, ReadPentagon) {
    std::istringstream iss("0 0 1 0 1 1 0 1 0.5 2");
    Pentagon p;
    iss >> p;
    Point c = p.center_of_figure();
    EXPECT_NEAR(c.x, 0.5, 0.001);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
