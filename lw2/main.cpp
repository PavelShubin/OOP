#include "money.hpp"
#include "iostream"

int main() {
    Money m1("1.23");
    Money m2("2.34");
    Money m3 = m1 + m2;
    std::string ans = static_cast<std::string>(m3);
    std::cout << ans << std::endl;
    return 0;
}