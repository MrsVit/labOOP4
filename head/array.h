#pragma once

#include "figure.h"
#include <vector>
#include <memory>
#include <iostream>
#include <stdexcept>

template<typename T>
class Array {
public:
    Array() = default;

    void Add(Figure<T>* fig) {
        if (!fig) return;
        figures.push_back(std::shared_ptr<Figure<T>>(fig));
    }

    void Remove(size_t index) {
        if (index >= figures.size()) {
            throw std::out_of_range("Index out of range");
        }
        figures.erase(figures.begin() + index);
    }

    void Print() const {
        for (size_t i = 0; i < figures.size(); ++i) {
            std::cout << "Figure " << i << ": " << *figures[i] << std::endl;
        }
    }

    double TotalArea() const {
        double sum = 0.0;
        for (const auto& fig : figures) {
            sum += static_cast<double>(*fig);
        }
        return sum;
    }

    void Centers() const {
        for (size_t i = 0; i < figures.size(); ++i) {
            std::cout << "Figure " << i
                      << " | Center: " << figures[i]->getCenter()
                      << " | Area: " << static_cast<double>(*figures[i])
                      << std::endl;
        }
    }

    ~Array() = default;

private:
    std::vector<std::shared_ptr<Figure<T>>> figures;
};