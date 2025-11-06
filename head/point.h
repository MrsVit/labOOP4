#include <iostream>
#include <type_traits>
#include <concepts>
#include <cmath>
#pragma once

using namespace std; //на всякий случай

template<typename T>
concept Scalar = std::is_arithmetic_v<T>;

template<Scalar T>
class Point {
public:
    T x, y;
    Point() : x(T{}), y(T{}) {}
    Point(T x, T y) : x(x), y(y) {}
    Point(const Point &other) : x(other.x), y(other.y) {} //copy-move по порядку
    Point(Point &&other) noexcept : x(std::move(other.x)), y(std::move(other.y)) {}

    Point &operator=(const Point &other) {
        if (this != &other) {
            x = other.x;
            y = other.y;
        }
        return *this;
    }

    Point &operator=(Point &&other) noexcept {
        if (this != &other) {
            x = std::move(other.x);
            y = std::move(other.y);
        }
        return *this;
    }

    ~Point() = default;
    bool operator==(const Point &other) const {
        return x == other.x && y == other.y;
    }

    bool operator!=(const Point &other) const {
        return !(*this == other);
    }

    double dist(const Point &other) const {
        T dx = x - other.x;
        T dy = y - other.y;
        return sqrt(dx * dx + dy * dy);
    }
    T getX() const { return x; }
    T getY() const { return y; }

    friend std::ostream &operator<<(std::ostream &os, const Point &p) {
        os << "(" << p.x << "; " << p.y << ")";
        return os;
    }

    friend std::istream &operator>>(std::istream &is, Point &p) {
        is >> p.x >> p.y;
        return is;
    }
};

