#include "../head/point.h"
#include "../head/rhombus.h"
#include "../head/5-squere.h"
#include "../head/trpezoid.h"
#include "../head/array_no_vector.h"

#include <iostream>
#include <memory>
#include <limits>

int main() {
    Array<double> figures;
    int choice;

    std::cout << "=== LAB 4 ===\n";
    std::cout << "Supported figures:\n";
    std::cout << "1. Rhombus (input: center.x, center.y, diagonal1, diagonal2)\n";
    std::cout << "2. Pentagon (input: center.x, center.y, radius)\n";
    std::cout << "3. Trapezoid (input: center.x, center.y, radius, height, base_ratio)\n\n";

    while (true) {
        std::cout << "\nMenu:\n"
                     "1. Add rhombus\n"
                     "2. Add pentagon\n"
                     "3. Add trapezoid\n"
                     "4. Print all figures\n"
                     "5. Print centers and areas\n"
                     "6. Total area\n"
                     "7. Remove figure\n"
                     "0. Exit\n"
                     "→ ";

        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << " Invalid input. Please try again.\n";
            continue;
        }

        switch (choice) {
            case 0:
                std::cout << "Exiting.\n";
                return 0;

            case 1: {
                std::cout << "Enter rhombus data (cx cy d1 d2): ";
                Rhombus<double>* rh = new Rhombus<double>();
                if (std::cin >> *rh) {
                    figures.Add(rh);
                    std::cout << " Rhombus added.\n";
                } else {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << " Input error.\n";
                    delete rh;
                }
                break;
            }

            case 2: {
                std::cout << "Enter pentagon data (cx cy radius): ";
                Fivesquere<double>* pent = new Fivesquere<double>();
                if (std::cin >> *pent) {
                    figures.Add(pent);
                    std::cout << " Pentagon added.\n";
                } else {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << " Input error.\n";
                    delete pent;
                }
                break;
            }

            case 3: {
                std::cout << "Enter trapezoid data (cx cy radius height ratio): ";
                Trapezoid<double>* trap = new Trapezoid<double>();
                if (std::cin >> *trap) {
                    figures.Add(trap);
                    std::cout << " Trapezoid added.\n";
                } else {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << " Input error.\n";
                    delete trap;
                }
                break;
            }

            case 4:
                std::cout << "\n--- All figures ---\n";
                figures.Print();
                break;

            case 5:
                std::cout << "\n--- Centers and areas ---\n";
                figures.Centers();
                break;

            case 6:
                std::cout << "\nTotal area: " << figures.TotalArea() << "\n";
                break;

            case 7: {
                size_t idx;
                std::cout << "Enter index of figure to remove: ";
                if (std::cin >> idx) {
                    try {
                        figures.Remove(idx);
                        std::cout << " Figure removed.\n";
                    } catch (const std::exception& e) {
                        std::cout << " " << e.what() << "\n";
                    }
                } else {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << " Invalid index.\n";
                }
                break;
            }

            default:
                std::cout << " Unknown command.\n";
                break;
        }
    }

    return 0;
}