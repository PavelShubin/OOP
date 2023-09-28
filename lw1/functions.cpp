#include "functions.h"

bool isVowel(char c) {
    c = std::tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
}

std::string removeVowels(const std::string& input) {
    std::string result = "";

    for (char c : input) {
        if (!isVowel(c)) {
            result += c;
        }
    }

    return result;
}
