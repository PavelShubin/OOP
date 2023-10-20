#include <iostream>
#include <memory>
#include <vector>
#include "figure.hpp"

int main() {
    std::vector<std::unique_ptr<Figure>> figures;

    while (true) {
        std::cout << "Select a figure type (1 - Square, 2 - Rectangle, 3 - Trapezoid): ";
        int choice;
        std::cin >> choice;

        if (choice == 1) {
            double x1, y1, x2, y2, x3, y3, x4, y4;
            std::cout << "Enter the coordinates of the square points: ";
            std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

            figures.push_back(std::make_unique<Square>(x1, y1, x2, y2, x3, y3, x4, y4));
        } else if (choice == 2) {
            double x1, y1, x2, y2, x3, y3, x4, y4;
            std::cout << "Enter the coordinates of the Rectangle points: ";
            std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

            figures.push_back(std::make_unique<Square>(x1, y1, x2, y2, x3, y3, x4, y4));
        } else if (choice == 3) {
            double x1, y1, x2, y2, x3, y3, x4, y4;
            std::cout << "Enter the coordinates of the Trapezoid points: ";
            std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

            figures.push_back(std::make_unique<Square>(x1, y1, x2, y2, x3, y3, x4, y4));
        } else {
            break;
        }
    }
    for (const auto& figure : figures) {
        figure->center();
        double area = static_cast<double>(*figure);
        std::cout << "Figure area: " << area << std::endl;
    }


    double totalArea = 0.0;
    for (const auto& figure : figures) {
        totalArea += static_cast<double>(*figure);
    }
    std::cout << "Total figure area: " << totalArea << std::endl;

    // Remove a figure based on its index
    int indexToRemove;
    std::cout << "Enter the index of the figure to remove: ";
    std::cin >> indexToRemove;

    if (indexToRemove >= 0 && indexToRemove < figures.size()) {
        figures.erase(figures.begin() + indexToRemove);
    }

    return 0;
}