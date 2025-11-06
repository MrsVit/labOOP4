# pragma once
#include <iostream>
#include <istream>
#include <ostream>
#include <vector>
#include <memory>
#include <cmath>
#include "./point.h"   

template<Scalar T>
class Figure {
protected:
    Point<T> center;
    T radius;
    std::vector<std::unique_ptr<Point<T>>> points;
    virtual void calcut() {};
    virtual const char* name() const = 0;

public:
    Figure() : center(Point<T>{}), radius(T{}) {}
    Figure(const Point<T>& center, T radius)
        : center(center), radius(radius) {
        calcut();
    }

    virtual ~Figure() = default;
    virtual double area() const {
        if (points.size() < 3) return 0.0;
        double area = 0.0;
        for (size_t i = 0; i < points.size(); ++i) {
            size_t j = (i + 1) % points.size();
            area += points[i]->x * points[j]->y - points[j]->x * points[i]->y;
        }
        return std::abs(area) / 2.0;
    }

    virtual void print(std::ostream& os) const {
        os << name() << "[Center: " << center << ", Radius: " << radius << "] Points: ";
        for (const auto& p : points) {
            os << *p << " ";
        }
    }

    virtual void read(std::istream& is) {
        is >> center.x >> center.y >> radius;
        calcut();
    }

    Point<T> getCenter() const { return center; }
    T getRadius() const { return radius; }

    virtual operator double() const {
        return area();
    }

    virtual bool operator==(const Figure<T>& other) const {
        if (center != other.center || radius != other.radius || points.size() != other.points.size())
            return false;
        for (size_t i = 0; i < points.size(); ++i) {
            if (*points[i] != *other.points[i])
                return false;
        }
        return true;
    }

    friend std::ostream& operator<<(std::ostream& os, const Figure<T>& f) {
        f.print(os);
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Figure<T>& f) {
        f.read(is);
        return is;
    }
};

