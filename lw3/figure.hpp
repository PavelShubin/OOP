#ifndef FIGURE_HPP
#define FIGURE_HPP

#include <iostream>
#include <vector>

class Figure
{
public:
    struct Point
    {
        double x;
        double y;
        Point() { x = 0; y = 0; }

        Point(double cord_x, double cord_y) {
            x = cord_x;
            y = cord_y;
        }
    };

    virtual ~Figure() noexcept;

    friend std::ostream& operator<<(std::ostream& os, const Figure& figure) noexcept;

    void center() const noexcept;

    explicit virtual operator double() const noexcept = 0;

    Figure& operator=(const Figure& other) noexcept;
    Figure& operator=(Figure&& other) noexcept;
    bool operator==(const Figure &other) const;
    bool operator!=(const Figure &other) const;

protected:
    bool sides_parallel(const Point& k1, const Point& k2, const Point& k3, const Point& k4) const;
    double calculateDistance(const Point& k1, const Point& k2) const;
    size_t quantity;
    Point *data;
};

class Square final: public Figure
{
private:
    bool isValidSquare() const;

public:

    Square(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);

    explicit virtual operator double() const noexcept override;

    friend std::istream& operator>>(std::istream& is, Square& square) noexcept;
};

class Rectangle final: public Figure
{
private:
    bool isValidRectangle() const;
public:
    Rectangle(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);

    explicit virtual operator double() const noexcept override;

    friend std::istream& operator>>(std::istream& is, Rectangle& rectangle) noexcept;
};

class Trapezoid final: public Figure
{
private:
    bool isValidTrapezoid() const;

public:

    Trapezoid(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);

    explicit virtual operator double() const noexcept override;

    friend std::istream& operator>>(std::istream& is, Trapezoid& trapezoid) noexcept;
};

#endif