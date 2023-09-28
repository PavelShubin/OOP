#include <iostream>
#include <string>
#include "functions.h"


int main() {
    std::string input;
    std::cout << "Введите строку: ";
    std::getline(std::cin, input);

    std::string output = removeVowels(input);
    std::cout << "Строка без гласных букв: " << output << std::endl;

    return 0;
}
