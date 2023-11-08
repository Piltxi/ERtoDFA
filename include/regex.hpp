#ifndef REGEX_H
#define REGEX_H

#include <set>
#include <string>

class Regex {
private:
    std::set<char> alphabet;
    std::string expression;

public:
    Regex();
    Regex(const std::set<char>& alphabet, const std::string& expression);

    const std::string& getExpression() const;
    const std::set<char>& getAlphabet() const;
    void setExpression(const std::string& expression);
    void setAlphabet(const std::set<char>& alphabet);
    void viewRegex();
};

#endif
