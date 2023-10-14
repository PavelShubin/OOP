#include "figure.hpp"
#include <iostream>
#include <stdexcept>
#include <string.h>
#include <cmath>

double Figure::calculateDistance(const Point& k1, const Point& k2) const
{
    double xDiff = k2.x - k1.x;
    double yDiff = k2.y - k1.y;
    return sqrt(xDiff * xDiff + yDiff * yDiff);
}


Square::operator double() const noexcept {
    return calculateDistance(p1, p2) * calculateDistance(p1, p2);
}

void Square::center() const noexcept
{
    std::cout << "geometric center: ";
    double result = (p1.x + p2.x + p3.x + p4.x) / 4;
    std::cout << "x:" << result << " ";
    result = (p1.y + p2.y + p3.y + p4.y) / 4;
    std::cout << "y:" << result << std::endl;
}

Square::Square(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
    : p1(x1, y1), p2(x2, y2), p3(x3, y3), p4(x4, y4) {
    if (!isValidSquare()) {
        throw std::runtime_error("Invalid square vertices");
    }
}

Square& Square::operator=(const Square& other) noexcept
{
    p1 = other.p1;
    p2 = other.p2;
    p3 = other.p3;
    p4 = other.p4;
}

Square& Square::operator=(Square&& other) noexcept
{
    p1 = other.p1;
    p2 = other.p2;
    p3 = other.p3;
    p4 = other.p4;
}

bool Square::operator==(const Square& other) const noexcept
{
    return (p1.x == other.p1.x && p1.y == other.p1.y &&
        p2.x == other.p2.x && p2.y == other.p2.y &&
        p3.x == other.p3.x && p3.y == other.p3.y &&
        p4.x == other.p4.x && p4.y == other.p4.y);
}

bool Square::operator!=(const Square& other) const noexcept
{
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& os, const Square& square) noexcept 
{
    os << "Vertex 1: (" << square.p1.x << ", " << square.p1.y << ")" << std::endl;
    os << "Vertex 2: (" << square.p2.x << ", " << square.p2.y << ")" << std::endl;
    os << "Vertex 3: (" << square.p3.x << ", " << square.p3.y << ")" << std::endl;
    os << "Vertex 4: (" << square.p4.x << ", " << square.p4.y << ")" << std::endl;
    return os;
}

std::istream& operator>>(std::istream& is, Square& square) noexcept 
{
    double x1, y1, x2, y2, x3, y3, x4, y4;
    is >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    square = Square(x1, y1, x2, y2, x3, y3, x4, y4);
    return is;
}

bool Square::isValidSquare() const
{
    if (p1.x == p2.x && p2.x == p3.x) { return false; }
    if (p1.y == p2.y && p2.y == p3.y) { return false; }
    double side1 = calculateDistance(p1, p2);
    double side2 = calculateDistance(p2, p3);
    double side3 = calculateDistance(p3, p4);
    double side4 = calculateDistance(p4, p1);

    if (side1 == side2 && side2 == side3 && side3 == side4) {
        double diagonal1 = calculateDistance(p1, p3);
        double diagonal2 = calculateDistance(p2, p4);

        return diagonal1 == diagonal2;
    }
    return false;
}



Rectangle::operator double() const noexcept {
    double side1 = calculateDistance(p1, p2);
    double side2 = calculateDistance(p2, p3);
    return side1 * side2;
}

void Rectangle::center() const noexcept
{
    std::cout << "geometric center: ";
    double result = (p1.x + p2.x + p3.x + p4.x) / 4;
    std::cout << "x:" << result << " ";
    result = (p1.y + p2.y + p3.y + p4.y) / 4;
    std::cout << "y:" << result << std::endl;
}

Rectangle::Rectangle(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
    : p1(x1, y1), p2(x2, y2), p3(x3, y3), p4(x4, y4) {
    if (!isValidRectangle()) {
        throw std::runtime_error("Invalid rectangle vertices");
    }
}

Rectangle& Rectangle::operator=(const Rectangle& other) noexcept
{
    p1 = other.p1;
    p2 = other.p2;
    p3 = other.p3;
    p4 = other.p4;
    return *this;
}

Rectangle& Rectangle::operator=(Rectangle&& other) noexcept
{
    p1 = other.p1;
    p2 = other.p2;
    p3 = other.p3;
    p4 = other.p4;
    return *this;
}

bool Rectangle::operator==(const Rectangle& other) const noexcept
{
    return (p1.x == other.p1.x && p1.y == other.p1.y &&
        p2.x == other.p2.x && p2.y == other.p2.y &&
        p3.x == other.p3.x && p3.y == other.p3.y &&
        p4.x == other.p4.x && p4.y == other.p4.y);
}

bool Rectangle::operator!=(const Rectangle& other) const noexcept
{
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& os, const Rectangle& rectangle) noexcept 
{
    os << "Vertex 1: (" << rectangle.p1.x << ", " << rectangle.p1.y << ")" << std::endl;
    os << "Vertex 2: (" << rectangle.p2.x << ", " << rectangle.p2.y << ")" << std::endl;
    os << "Vertex 3: (" << rectangle.p3.x << ", " << rectangle.p3.y << ")" << std::endl;
    os << "Vertex 4: (" << rectangle.p4.x << ", " << rectangle.p4.y << ")" << std::endl;
    return os;
}

std::istream& operator>>(std::istream& is, Rectangle& rectangle) noexcept 
{
    double x1, y1, x2, y2, x3, y3, x4, y4;
    is >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    rectangle = Rectangle(x1, y1, x2, y2, x3, y3, x4, y4);
    return is;
}

bool Rectangle::isValidRectangle() const
{
    if (p1.x == p2.x && p2.x == p3.x) { return false; }
    if (p1.y == p2.y && p2.y == p3.y) { return false; }
    double side1 = calculateDistance(p1, p2);
    double side2 = calculateDistance(p2, p3);
    double side3 = calculateDistance(p3, p4);
    double side4 = calculateDistance(p4, p1);

    double diagonal1 = calculateDistance(p1, p3);
    double diagonal2 = calculateDistance(p2, p4);

    return (side1 == side3 && side2 == side4 && diagonal1 == diagonal2);
}




Trapezoid::operator double() const noexcept {
    double side1, side2, h;
    if (sides_parallel(p1, p2, p3, p4)) {
        side1 = calculateDistance(p1, p2);
        side2 = calculateDistance(p3, p4);
        if (p1.y - p4.y == p2.y - p3.y) { h = abs(p1.y - p4.y); }
        else { h = abs(p1.x - p4.x); }
    } else {
        side1 = calculateDistance(p2, p3);
        side2 = calculateDistance(p4, p1);
        if (p2.y - p1.y == p3.y - p4.y) { h = abs(p2.y - p1.y); }
        else { h = abs(p2.x - p1.x); }
    }
    return 0.5 * (side1 + side2) * h;
}

void Trapezoid::center() const noexcept
{
    std::cout << "geometric center: ";
    double result = (p1.x + p2.x + p3.x + p4.x) / 4;
    std::cout << "x:" << result << " ";
    result = (p1.y + p2.y + p3.y + p4.y) / 4;
    std::cout << "y:" << result << std::endl;
}

Trapezoid::Trapezoid(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
    : p1(x1, y1), p2(x2, y2), p3(x3, y3), p4(x4, y4) {
    if (!isValidTrapezoid()) {
        throw std::runtime_error("Invalid trapezoid vertices");
    }
}

Trapezoid& Trapezoid::operator=(const Trapezoid& other) noexcept
{
    p1 = other.p1;
    p2 = other.p2;
    p3 = other.p3;
    p4 = other.p4;
    return *this;
}

Trapezoid& Trapezoid::operator=(Trapezoid&& other) noexcept
{
    p1 = other.p1;
    p2 = other.p2;
    p3 = other.p3;
    p4 = other.p4;
    return *this;
}

bool Trapezoid::operator==(const Trapezoid& other) const noexcept
{
    return (p1.x == other.p1.x && p1.y == other.p1.y &&
        p2.x == other.p2.x && p2.y == other.p2.y &&
        p3.x == other.p3.x && p3.y == other.p3.y &&
        p4.x == other.p4.x && p4.y == other.p4.y);
}

bool Trapezoid::operator!=(const Trapezoid& other) const noexcept
{
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& os, const Trapezoid& trapezoid) noexcept 
{
    os << "Vertex 1: (" << trapezoid.p1.x << ", " << trapezoid.p1.y << ")" << std::endl;
    os << "Vertex 2: (" << trapezoid.p2.x << ", " << trapezoid.p2.y << ")" << std::endl;
    os << "Vertex 3: (" << trapezoid.p3.x << ", " << trapezoid.p3.y << ")" << std::endl;
    os << "Vertex 4: (" << trapezoid.p4.x << ", " << trapezoid.p4.y << ")" << std::endl;
    return os;
}

std::istream& operator>>(std::istream& is, Trapezoid& trapezoid) noexcept 
{
    double x1, y1, x2, y2, x3, y3, x4, y4;
    is >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    trapezoid = Trapezoid(x1, y1, x2, y2, x3, y3, x4, y4);
    return is;
}

bool Trapezoid::isValidTrapezoid() const
{
    if (p1.x == p2.x && p2.x == p3.x) { return false; }
    if (p1.y == p2.y && p2.y == p3.y) { return false; }
    if (sides_parallel(p1, p2, p3, p4)) {
        return !(sides_parallel(p2, p3, p4, p1));
    }
    return sides_parallel(p2, p3, p4, p1);
}

bool Trapezoid::sides_parallel(const Point& k1, const Point& k2, const Point& k3, const Point& k4) const
{
    if (k1.y - k4.y == k2.y - k3.y) { return true; }
    if (k1.x - k4.x == k2.x - k3.x) { return true; }
    return false;
}
