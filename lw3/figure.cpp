#include "figure.hpp"
#include <iostream>
#include <stdexcept>
#include <string.h>
#include <cmath>

Figure& Figure::operator=(const Figure& other) noexcept
{
    if (this != &other) {
        delete[] data;
        data = new Point[other.quantity];
        quantity = other.quantity;
        std::copy(other.data, other.data + quantity, data);
    }
    return *this;
}

Figure& Figure::operator=(Figure &&other) noexcept
{
    if (this != &other) {
        delete[] data;
        data = other.data;
        quantity = other.quantity;
        other.data = nullptr;
        other.quantity = 0;
    }
    return *this;
}
Figure::~Figure() noexcept
{
    delete[] data;
    quantity = 0;
}

bool Figure::operator==(const Figure &other) const
{
    if (quantity != other.quantity) {
        return false;
    }
    for (int i = 0; i < quantity; i++) {
        if (!(data[i].x == other.data[i].x && data[i].y == other.data[i].y)) {
            return false;
        }
    }
    return true;
}

bool Figure::operator!=(const Figure &other) const
{
    return !(*this == other);
}

double Figure::calculateDistance(const Point& k1, const Point& k2) const
{
    double xDiff = k2.x - k1.x;
    double yDiff = k2.y - k1.y;
    return sqrt(xDiff * xDiff + yDiff * yDiff);
}

std::ostream& operator<<(std::ostream& os, const Figure& figure) noexcept 
{
    for (int i = 1; i < figure.quantity + 1; i++) {
        os << "Vertex " << i << ": (" << figure.data[i - 1].x << ", " << figure.data[i - 1].y << ")" << std::endl;
    }
    return os;
}

void Figure::center() const noexcept
{
    double s_x = 0;
    double s_y = 0;
    for (int i = 0; i < quantity; i++) {
        s_x += data[i].x;
        s_y += data[i].y;
    }
    s_x /= quantity;
    s_y /= quantity;
    std::cout << "Center of figure: (" << s_x << ", " << s_y << ")" << std::endl;
}

bool Figure::sides_parallel(const Point& k1, const Point& k2, const Point& k3, const Point& k4) const
{
    if (k1.y - k2.y == 0) {
        return (k3.y - k4.y == 0);
    }
    if (k1.x - k2.x == 0) {
        return (k3.x - k4.x == 0);
    }


    double slope1 = (k2.y - k1.y) / (k2.x - k1.x);
    double slope2 = (k4.y - k3.y) / (k4.x - k3.x);\
    
    if (std::abs(slope1 - slope2) < 1e-6) {
        return true;
    }
    return false;
}



Square::operator double() const noexcept {
    double side = calculateDistance(data[0], data[1]);
    return side * side;
}

bool Square::isValidSquare() const
{
    if (data[0].x == data[1].x && data[1].x == data[2].x) { return false; }
    if (data[0].y == data[1].y && data[1].y == data[2].y) { return false; }
    double side1 = calculateDistance(data[0], data[1]);
    double side2 = calculateDistance(data[1], data[2]);
    double side3 = calculateDistance(data[2], data[3]);
    double side4 = calculateDistance(data[3], data[0]);

    if (side1 == side2 && side2 == side3 && side3 == side4) {
        double diagonal1 = calculateDistance(data[0], data[2]);
        double diagonal2 = calculateDistance(data[1], data[3]);

        return diagonal1 == diagonal2;
    }
    return false;
}

Square::Square(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{   
    data = new Point[4];
    quantity = 4;
    data[0] = Point(x1, y1);
    data[1] = Point(x2, y2);
    data[2] = Point(x3, y3);
    data[3] = Point(x4, y4);
    if (!isValidSquare()) {
        throw std::runtime_error("Invalid square vertices");
    }
}

std::istream& operator>>(std::istream& is, Square& square) noexcept 
{
    double x1, y1, x2, y2, x3, y3, x4, y4;
    is >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    square = Square(x1, y1, x2, y2, x3, y3, x4, y4);
    return is;
}



Rectangle::operator double() const noexcept {
    double side1 = calculateDistance(data[0], data[1]);
    double side2 = calculateDistance(data[1], data[2]);
    return side1 * side2;
}

bool Rectangle::isValidRectangle() const
{
    if (data[0].x == data[1].x && data[1].x == data[2].x) { return false; }
    if (data[0].y == data[1].y && data[1].y == data[2].y) { return false; }
    double side1 = calculateDistance(data[0], data[1]);
    double side2 = calculateDistance(data[1], data[2]);
    double side3 = calculateDistance(data[2], data[3]);
    double side4 = calculateDistance(data[3], data[0]);

    double diagonal1 = calculateDistance(data[0], data[2]);
    double diagonal2 = calculateDistance(data[1], data[3]);

    return (side1 == side3 && side2 == side4 && diagonal1 == diagonal2);
}

Rectangle::Rectangle(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{
    data = new Point[4];
    quantity = 4;
    data[0] = Point(x1, y1);
    data[1] = Point(x2, y2);
    data[2] = Point(x3, y3);
    data[3] = Point(x4, y4);
    if (!isValidRectangle()) {
        throw std::runtime_error("Invalid rectangle vertices");
    }
}

std::istream& operator>>(std::istream& is, Rectangle& rectangle) noexcept 
{
    double x1, y1, x2, y2, x3, y3, x4, y4;
    is >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    rectangle = Rectangle(x1, y1, x2, y2, x3, y3, x4, y4);
    return is;
}



Trapezoid::operator double() const noexcept {
    double side1, side2, h;
    if (sides_parallel(data[0], data[1], data[2], data[3])) {
        side1 = calculateDistance(data[0], data[1]);
        side2 = calculateDistance(data[2], data[3]);
        if (data[0].y - data[3].y == data[1].y - data[2].y) { h = abs(data[0].y - data[3].y); }
        else { h = abs(data[0].x - data[3].x); }
    } else {
        side1 = calculateDistance(data[1], data[2]);
        side2 = calculateDistance(data[3], data[0]);
        if (data[1].y - data[0].y == data[2].y - data[3].y) { h = abs(data[1].y - data[0].y); }
        else { h = abs(data[1].x - data[0].x); }
    }
    return 0.5 * (side1 + side2) * h;
}

bool Trapezoid::isValidTrapezoid() const
{
    if (data[0].x == data[1].x && data[1].x == data[2].x) { return false; }
    if (data[0].y == data[1].y && data[1].y == data[2].y) { return false; }
    if (sides_parallel(data[0], data[1], data[2], data[3])) {
        return !(sides_parallel(data[1], data[2], data[3], data[0]));
    }
    return sides_parallel(data[1], data[2], data[3], data[0]);
}

Trapezoid::Trapezoid(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{
    data = new Point[4];
    quantity = 4;
    data[0] = Point(x1, y1);
    data[1] = Point(x2, y2);
    data[2] = Point(x3, y3);
    data[3] = Point(x4, y4);
    if (!isValidTrapezoid()) {
        throw std::runtime_error("Invalid trapezoid vertices");
    }
}

std::istream& operator>>(std::istream& is, Trapezoid& trapezoid) noexcept 
{
    double x1, y1, x2, y2, x3, y3, x4, y4;
    is >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    trapezoid = Trapezoid(x1, y1, x2, y2, x3, y3, x4, y4);
    return is;
}
