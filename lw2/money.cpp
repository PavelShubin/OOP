#include "money.hpp"
#include <iostream>
#include <stdexcept>
#include <string.h>

Money::Money() noexcept: digits(nullptr), size(0) {}

Money::Money(const size_t t, unsigned char a): digits(new unsigned char[t]), size(t)
{
    if (a < '0' || a > '9') {
        throw std::invalid_argument("Invalid value");
    }
    for (int i = 0; i < size; i++) {
        digits[i] = a - '0';
    }
}

Money::Money(const std::initializer_list<unsigned char> &t) : digits(nullptr), size(t.size())
{
    if (size == 0) {
        throw std::invalid_argument("List can't be empty");
    }
    
    for (auto& elem: t) {
        if (elem < '0' or elem > '9') {
            throw std::invalid_argument("Must be only digits");
        }
    }
    digits = new unsigned char[size];
    int i = size;
    for (auto& elem: t) {
        i--;
        digits[i] = elem - '0';
    }
}

Money::Money(const unsigned char* s_digits, size_t l) : digits(nullptr)
{
    if (s_digits == nullptr) {
        throw std::invalid_argument("can't be nullptr");
    }
    size = l;

    for (int i = 0; i < size; i++) {
        if (s_digits[i] < 0 || s_digits[i] > 9) {
            throw std::invalid_argument("Invalid money value");
        }
    }

    digits = new unsigned char[size];

    for (int i = 0; i < size; i++) {
        digits[i] = s_digits[i];
    }
}

Money::Money(const std::string &t) : digits(new unsigned char[t.length()]), size(t.length())
{
    if (size == 0) {
        throw std::invalid_argument("Can't be empty");
    }
    for (int i = 0; i < size; i++) {
        if (t[i] < '0' || t[i] > '9') {
            throw std::invalid_argument("Only digits");
        }
        digits[size - i - 1] = t[i] - '0';
    }
}

Money::Money(const Money &other): digits(new unsigned char[other.size]), size(other.size)
{
    std::copy(other.digits, other.digits + other.size, digits);
}

Money::Money(Money &&other) noexcept : digits(other.digits), size(other.size)
{
    other.digits = nullptr;
    other.size = 0;
}

Money::~Money() noexcept
{
    delete[] digits;
    size = 0;
}

Money& Money::operator=(const Money& other) noexcept
{
    if (this != &other) {
        delete[] digits;
        digits = new unsigned char[other.size];
        size = other.size;
        std::copy(other.digits, other.digits + size, digits);
    }
    return *this;
}

Money& Money::operator=(Money &&other) noexcept
{
    if (this != &other) {
        delete[] digits;
        digits = other.digits;
        size = other.size;
        other.digits = nullptr;
        other.size = 0;
    }
    return *this;
}

Money Money::operator+(const Money &other) const
{
    size_t max_size = std::max(size, other.size);
    unsigned char *result = new unsigned char[max_size];
    unsigned char temp = 0;
    unsigned char first, second;
    for (int i = 0; i < max_size; i++) {
        first = (i < size) ? digits[i] : 0;
        second = (i < other.size) ? other.digits[i] : 0;
        unsigned char sum = first + second + temp;
        result[i] = sum % 10;
        temp = sum / 10;
    }
    if (temp > 0) {
        unsigned char *temp_result = new unsigned char[max_size + 1];
        std::copy(result, result + max_size, temp_result);
        temp_result[max_size] = temp;
        delete[] result;
        result = temp_result;
        max_size += 1;
    }
    Money m(result, max_size);
    delete[] result;
    return m;
}

Money Money::operator-(const Money &other) const
{
    if (*this < other) {
        throw std::invalid_argument("Result is negative");
    }

    size_t max_size = std::max(size, other.size);
    unsigned char *result = new unsigned char[max_size];
    unsigned char temp = 0;
    unsigned char first, second;
    for (int i = 0; i < max_size; i++) {
        first = (i < size) ? digits[i] : 0;
        second = (i < other.size) ? other.digits[i] : 0;
        unsigned char diff = first - second - temp;
        if (diff > first) {
            diff += 10;
            temp = 1;
        } else {
            temp = 0;
        }
        result[i] = diff;
    }

    int new_size = max_size;
    while (result[new_size - 1] == 0 && new_size > 1) {
        new_size--;
    }

    Money m(result, new_size);
    delete[] result;
    return m;

}

bool Money::operator==(const Money &other) const
{
    if (size != other.size) {
        return false;
    }
    for (int i = 0; i < size; i++) {
        if (digits[i] != other.digits[i]) {
            return false;
        }
    }
    return true;
}

bool Money::operator!=(const Money &other) const
{
    return !((*this) == other);
}

bool Money::operator<(const Money &other) const
{
    if (size < other.size) { return true; }
    if (size > other.size) { return false; }
    for (int i = 0; i < size; i++) {
        if (digits[size - i - 1] < other.digits[size - i - 1]) { return true; }
        if (digits[size - i - 1] > other.digits[size - i - 1]) { return false; }
    }
    return false;
}

bool Money::operator>(const Money &other) const
{
    if (size > other.size) { return true; }
    if (size < other.size) { return false; }
    for (int i = 0; i < size; i++) {
        if (digits[size - i - 1] > other.digits[size - i - 1]) { return true; }
        if (digits[size - i - 1] < other.digits[size - i - 1]) { return false; }
    }
    return false;
}

Money::operator std::string() const noexcept
{
    size_t res_size = 4;
    if (size > 3) { res_size = size + 1; }
    std::string result(res_size, '0');
    int dot = res_size - 3;
    result[dot] = '.';
    int temp = res_size - 1;
    for (int i = 0; i < size; i++) {
        if (temp == dot) { temp--; }
        result[temp] = digits[i] + '0';
        temp--;
    }
    return result;
}

Money::operator int() const noexcept
{
    int result = 0, k = 1;
    for (int i = 0; i < size; i++) {
        result += digits[i] * k;
        k *= 10;
    }
    return result;
}

size_t Money::length() const noexcept
{
    return size;
}

void Money::print() const
{
    std::string ans = static_cast<std::string>(*this);
    std::cout << ans << std::endl;
}