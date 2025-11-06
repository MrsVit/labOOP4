        //  A -------- B
        //   \        /
        //    D ---- C вот так
#include "figure.h"
#include <cmath>
#include <memory>

template<Scalar T>
class Trapezoid : public Figure<T> {
protected:
    T h;
    T div; //отношение оснований

    void calcut() override {
        this->points.clear();

        // Большее основание = 2 * radius
        T large = 2 * this->radius;
        T small = large * div;

        T half_large = large / 2;
        T half_small = small / 2;
        T cx = this->center.x;
        T cy = this->center.y;

        T top_y = cy + h / 2;
        T bot_y = cy - h / 2;

        Point<T> A(cx - half_small, top_y);
        Point<T> B(cx + half_small, top_y);
        Point<T> C(cx + half_large, bot_y);
        Point<T> D(cx - half_large, bot_y);

        this->points.push_back(std::make_unique<Point<T>>(A));
        this->points.push_back(std::make_unique<Point<T>>(B));
        this->points.push_back(std::make_unique<Point<T>>(C));
        this->points.push_back(std::make_unique<Point<T>>(D));
    }

    const char* name() const override {
        return "Trapezoid";
    }

public:
    Trapezoid() : Trapezoid(Point<T>{}, T{1}, T{1}, T{0.5}) {}
    Trapezoid(const Point<T>& center, T radius, T height, T ratio = T{0.5})
        : h(height), div(ratio) {
        if (div <= 0 || div >= 1) div = T{0.5};
        if (h <= 0) h = T{1};
        this->center = center;
        this->radius = radius;
        calcut();
    }

    T getHeight() const { return h; }
    T getRatio() const { return div; }
    bool operator==(const Trapezoid<T>& other) const {
        return Figure<T>::operator==(other) &&
               h == other.h &&
               div == other.div;
    }
};

