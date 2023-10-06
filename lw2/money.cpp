#include "money.hpp"
#include <iostream>
#include <stdexcept>
#include <string.h>

Money::Money() noexcept: digits(nullptr), size(0) {}

Money::Money(const size_t t, unsigned char a): digits(new unsigned char[t]), size(t)
{
    if (a < 0 || a > 9) {
        throw std::invalid_argument("Invalid value\n");
    }
    for (int i = 0; i < size; i++) {
        digits[i] = a;
    }
}

Money::Money(const std::initializer_list<unsigned char> &t) : digits(new unsigned char[t.size()]), size(t.size())
{
    std::copy(t.begin(), t.end(), digits);
}

Money::Money(const unsigned char* s_digits)
{
    if (s_digits == nullptr) {
        throw std::invalid_argument("can't be nullptr\n");
    }
    size = strlen(reinterpret_cast<const char*>(s_digits));

    digits = new unsigned char[size];

    for (int i = 0; i < size; i++) {
        if (s_digits[i] < 0 || s_digits[i] > 9) {
            throw std::invalid_argument("Invalid money value\n");
        }
        digits[i] = s_digits[i];
    }
}

Money::Money(const std::string &t) : digits(new unsigned char[t.length() - 1]), size(t.length() - 1)
{
    bool flag = false;
    int mark = size - 1;
    for (size_t i = 0; i < size + 1; i++)
    {
        if (t[i] == '.') {
            if (flag) {
                throw std::invalid_argument("Trouble with dot. Must be 'xxxx.xx'\n");
            }
            flag = true;
            if (i != size - 2) { throw std::invalid_argument("Trouble with dot. Must be 'xxxx.xx'\n"); }
            continue;
        }
        if (!std::isdigit(t[i]))
            throw std::invalid_argument("Invalid money value. Must be 'xxxx.xx'\n");

        digits[mark] = t[i] - '0';
        mark--;
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
    size_t M_size;
    if (size > other.size) {
        M_size = size;
    } else {
        M_size = other.size;
    }
    unsigned char *data = new unsigned char[M_size];
    unsigned char temp = 0;
    for (int i = 0; i < M_size; i++) {
        if (i < size) {
            temp += digits[i];
        }
        if (i < other.size) {
            temp += other.digits[i];
        }
        data[i] = temp % 10;
        temp /= 10;
    }
    if (temp != 0) {
        unsigned char *new_data = new unsigned char[M_size + 1];
        std::copy(data, data + size, new_data);
        delete[] data;
        new_data[M_size] = temp;
        Money ans(new_data);
        return ans;
    }
    Money ans(data);
    return ans;
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

size_t Money::lenght() const noexcept
{
    return size;
}

void Money::print() const
{
    std::string ans = static_cast<std::string>(*this);
    std::cout << ans << std::endl;
}