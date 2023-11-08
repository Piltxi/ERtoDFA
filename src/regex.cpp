#include "../include/regex.hpp"
#include <iostream>
#include <sstream>

Regex::Regex() {}

Regex::Regex(const std::set<char>& alphabet, const std::string& expression) : alphabet(alphabet), expression(expression) {}

const std::string& Regex::getExpression() const {
    return expression;
}

const std::set<char>& Regex::getAlphabet() const {
    return alphabet;
}

void Regex::setExpression(const std::string& expression) {
    this->expression = expression;
}

void Regex::setAlphabet(const std::set<char>& alphabet) {
    this->alphabet = alphabet;
}

void Regex::viewRegex() {
    std::cout << "Alphabet:\n";
    for (const char& symbol : alphabet)
        std::cout << symbol << " ";
    std::cout << std::endl;

    std::cout << "Regular expression:\n" << expression << std::endl << std::endl;
}
