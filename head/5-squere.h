#include "figure.h"
#include <memory>
#include <cmath>
#include <numbers>

template<Scalar T>
class Fivesquere : public Figure<T> {
protected:
    void calcut() override {
        this->points.clear();

        constexpr size_t N = 5;
        T cx = this->center.x;
        T cy = this->center.y;
        const double start_angle = std::numbers::pi;
        for (size_t i = 0; i < N; ++i) {
            double angle = start_angle + 2.0 * std::numbers::pi * i / N;
            T x = cx + this->radius * std::cos(angle);
            T y = cy + this->radius * std::sin(angle);
            this->points.push_back(make_unique<Point<T>>(x, y));
        }
    }

    const char* name() const override {
        return "Fivesquere";
    }

public:
    Fivesquere() : Fivesquere(Point<T>{}, T{1}) {}
    Fivesquere(const Point<T>& center, T radius)
        : Figure<T>(center, radius) {
    }
    bool operator==(const Fivesquere<T>& other) const {
        return Figure<T>::operator==(other);
    }
};
