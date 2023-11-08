#include "../include/abstractSyntaxTree.hpp"

set<char> operators = {'*','|','.'}; 

// Costruttore della classe AST
AST::AST(char character, AST* left, AST* right) : character(character), left(left), right(right) {}

AST::AST(char character) : character(character), left(nullptr), right(nullptr) {}

// Metodi della classe AST
char AST::getCharacter() const {
    return character;
}

AST* AST::getLeft() {
    return left;
}

AST* AST::getRight() {
    return right;
}

std::string AST::REview() {
    std::string ReRep = "";

    if (left != nullptr) {
        std::string leftRE = left->REview();

        if (right != nullptr) {
            std::string rightRE = right->REview();
            ReRep.push_back(character);

            ReRep.push_back('(');
            ReRep.append(leftRE);
            ReRep.push_back(')');

            ReRep.push_back('(');
            ReRep.append(rightRE);
            ReRep.push_back(')');
        } else {
            ReRep.push_back(character);

            ReRep.push_back('(');
            ReRep.append(leftRE);
            ReRep.push_back(')');
        }
    } else {
        ReRep.push_back(character);
    }

    return ReRep;
}
