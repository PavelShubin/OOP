#ifndef MONEY_HPP
#define MONEY_HPP

#include <string>
#include <initializer_list>

class Money
{
public:
    // Construsctors
    Money() noexcept;
    Money(const size_t, unsigned char);
    Money(const unsigned char*);
    Money(const std::initializer_list<unsigned char>&);
    Money(const std::string&);
    Money(const Money&);
    Money(Money&&) noexcept;

    // Destructor
    virtual ~Money() noexcept;

    // Operations
    Money& operator=(const Money&) noexcept;
    Money& operator=(Money&&) noexcept;
    Money operator+(const Money &other) const;
    Money operator-(const Money &other) const;

    // Comparison
    bool operator==(const Money &other) const;
    bool operator!=(const Money &other) const;
    bool operator<(const Money &other) const;
    bool operator>(const Money &other) const;
    
    // Casts
    operator std::string() const noexcept;
    operator int() const noexcept;

    // Size
    size_t lenght() const noexcept;

    // Print
    void print() const;

private:
    unsigned char *digits; // массив цифр
    size_t size; // размер массива
};

#endif