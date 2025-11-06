#include "figure.h"
#include <memory>
#include <cmath>

template<Scalar T>
class Rhombus : public Figure<T> {
protected:
    T d1; 
    T d2; // меньшая диагональ (если другое не задано р*2)

    void calcut() override {
        this->points.clear();

        T half_d1 = d1 / 2;
        T half_d2 = d2 / 2;

        T cx = this->center.x;
        T cy = this->center.y;

        //верх-право-низ-лево
        Point<T> top(cx, cy + half_d2);
        Point<T> right(cx + half_d1, cy);
        Point<T> bottom(cx, cy - half_d2);
        Point<T> left(cx - half_d1, cy);

        this->points.push_back(std::make_unique<Point<T>>(top));
        this->points.push_back(std::make_unique<Point<T>>(right));
        this->points.push_back(std::make_unique<Point<T>>(bottom));
        this->points.push_back(std::make_unique<Point<T>>(left));
    }

    const char* name() const override {
        return "Rhombus";
    }

public:
    Rhombus() : Rhombus(Point<T>{}, T{1}, T{1}) {}
    //ромбоквадрат
    Rhombus(const Point<T>& center, T radius)
        : Rhombus(center, radius, radius) {}
    Rhombus(const Point<T>& center, T diag1, T diag2)
        : d1(diag1), d2(diag2) {
        if (d1 <= 0) d1 = T{1};
        if (d2 <= 0) d2 = T{1};
        this->center = center;
        this->radius = (d1 > d2 ? d1 : d2) / 2; 
        calcut();
    }
    T getd1() const { return d1; }
    T getd2() const { return d2; }

    bool operator==(const Rhombus<T>& other) const {
        return Figure<T>::operator==(other) &&
               d1 == other.d1 &&
               d2 == other.d2;
    }
};