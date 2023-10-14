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

        Point(double cord_x, double cord_y) {
            x = cord_x;
            y = cord_y;
        }
    };

    virtual ~Figure() noexcept = default;

    explicit virtual operator double() const noexcept = 0;

    Figure& operator=(const Figure& other) = default;
    Figure& operator=(Figure&& other) = default;

protected:
    double calculateDistance(const Point& k1, const Point& k2) const;
};

class Square final: public Figure
{
private:
    Point p1;
    Point p2;
    Point p3;
    Point p4;

public:
    explicit virtual operator double() const noexcept override;

    void center() const noexcept;

    Square(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);

    Square& operator=(const Square& other) noexcept;
    Square& operator=(Square&& other) noexcept;
    bool operator==(const Square& other) const noexcept;
    bool operator!=(const Square& other) const noexcept;

    friend std::ostream& operator<<(std::ostream& os, const Square& square) noexcept;

    friend std::istream& operator>>(std::istream& is, Square& square) noexcept;

private:
    bool isValidSquare() const;
};

class Rectangle final: public Figure
{
private:
    Point p1;
    Point p2;
    Point p3;
    Point p4;

public:
    explicit virtual operator double() const noexcept override;

    void center() const noexcept;

    Rectangle(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);

    Rectangle& operator=(const Rectangle& other) noexcept;
    Rectangle& operator=(Rectangle&& other) noexcept;
    bool operator==(const Rectangle& other) const noexcept;
    bool operator!=(const Rectangle& other) const noexcept;

    friend std::ostream& operator<<(std::ostream& os, const Rectangle& rectangle) noexcept;

    friend std::istream& operator>>(std::istream& is, Rectangle& rectangle) noexcept;

private:
    bool isValidRectangle() const;
};

class Trapezoid final: public Figure
{
private:
    Point p1;
    Point p2;
    Point p3;
    Point p4;

public:
    explicit virtual operator double() const noexcept override;

    void center() const noexcept;

    Trapezoid(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);

    Trapezoid& operator=(const Trapezoid& other) noexcept;
    Trapezoid& operator=(Trapezoid&& other) noexcept;
    bool operator==(const Trapezoid& other) const noexcept;
    bool operator!=(const Trapezoid& other) const noexcept;

    friend std::ostream& operator<<(std::ostream& os, const Trapezoid& trapezoid) noexcept;

    friend std::istream& operator>>(std::istream& is, Trapezoid& trapezoid) noexcept;

private:
    bool isValidTrapezoid() const;
    bool sides_parallel(const Point& k1, const Point& k2, const Point& k3, const Point& k4) const;
};

#endif