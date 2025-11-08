#pragma once

#include "figure.h"
#include <memory>
#include <iostream>
#include <stdexcept>
#include <algorithm> // для move

template<typename T>
class Array {
public:
    Array() : figures(nullptr), size(0), capacity(0) {}

    ~Array() {
        delete[] figures;
    }

    void Add(Figure<T>* fig) {
        if (!fig) return;
        if (size >= capacity) {
            resize(capacity == 0 ? 1 : capacity * 2);
        }

        figures[size] = std::shared_ptr<Figure<T>>(fig);
        ++size;
    }

    void Remove(size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }

        for (size_t i = index; i < size - 1; ++i) {
            figures[i] = std::move(figures[i + 1]);
        }
        --size;
    }

    void Print() const {
        for (size_t i = 0; i < size; ++i) {
            std::cout << "Figure " << i << ": " << *figures[i] << std::endl;
        }
    }

    double TotalArea() const {
        double sum = 0.0;
        for (size_t i = 0; i < size; ++i) {
            sum += static_cast<double>(*figures[i]);
        }
        return sum;
    }

    void Centers() const {
        for (size_t i = 0; i < size; ++i) {
            std::cout << "Figure " << i
                      << " | Center: " << figures[i]->getCenter()
                      << " | Area: " << static_cast<double>(*figures[i])
                      << std::endl;
        }
    }

private:
    std::shared_ptr<Figure<T>>* figures; 
    size_t size;   
    size_t capacity; 

    void resize(size_t new_capacity) {
        auto new_figures = new std::shared_ptr<Figure<T>>[new_capacity];

        for (size_t i = 0; i < size; ++i) {
            new_figures[i] = std::move(figures[i]);
        }

        delete[] figures;
        figures = new_figures;
        capacity = new_capacity;
    }
};