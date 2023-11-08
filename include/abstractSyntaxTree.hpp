#ifndef AST_H
#define AST_H

#include <string>
#include <set>

using namespace std; 

extern set<char> operators; 

/**
 * @brief defined Class to implement the abstract syntax tree.
 * Each object contains pointers to child objects (left, right). 
 * Implements the necessary and fundamental methods for using the tree.
 * 
 * Contains Review recursive method to print a regular expression according to linear representation
 */
class AST {

    private:
        char character; 
        AST* left; 
        AST* right; 
    
    public: 
        AST(char character, AST* left, AST* right);
        AST(char character);

        char getCharacter () const; 
        AST* getLeft();
        AST* getRight();
        std::string REview();
}; 

#endif