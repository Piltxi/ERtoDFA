#include <iostream>
#include <map>
#include <set>
#include <string>
#include <fstream>
#include <cctype>
#include <list>
#include <queue>
#include <sstream>
#include <vector>


#include "include/abstractSyntaxTree.hpp"
#include "include/automaton.hpp"
#include "include/regex.hpp"

// Comment if you don't want to generate png of the automaton
#define DOT

/**
 * @brief Function to acquire data on a regular expression (alphabet, expression) from a file. 
 * 
 * @param nameFile file name with regex
 * @return Regex regex object imported from file
 */
Regex importRegex (const char* nameFile) {

    Regex regex; 

    ifstream fi (nameFile); 
    if (!fi.is_open()) {
        cout<<"\nERROR - Opening file...\n";
        return regex; 
    }
    
    // Alphabet acquisition...
    string line; 
    getline(fi, line); 

    set<char>regexAlphabet; 

    stringstream alphabet(line); 
    char symb;
    while(alphabet>>symb)
            regexAlphabet.insert(symb);

        
    regex.setAlphabet(regexAlphabet); 

    // Expression acquisition...
    string expression; 
    getline(fi, expression); 
    
    regex.setExpression(expression); 

    return regex; 
}

/**
 * @brief Returns the first non-blank character starting from the specified position (inclusive).
 *
 * @param S The string to search for the non-blank character in.
 * @param j The position from which to start the search.
 * @return int The position of the first non-blank character found.
 */
int skipblank(string S, int j) {
    while (j < S.length() && S[j] == ' ') j++;
    return j;
}

/**
 * @brief Returns a "compacted" string where all blank characters are removed.
 *
 * This function removes all blank characters from the input string and returns the resulting string.
 *
 * @param S The string from which to remove blank characters.
 * @return string The "compacted" string without blank characters.
 */
string removeblank(string S) {
    int n = S.length();
    int j = skipblank(S, 0);
    string compact = "";
    while (j < n) {
        compact.push_back(S.at(j));
        j = skipblank(S, ++j);
    }
    return compact;
}

/**
 * @brief Calculates the length of the substring that correctly balances parentheses starting from the specified position.
 *
 * This function calculates the length of the substring within the input string that starts from the given position and correctly balances parentheses.
 *
 * @param S The string in which to find the balanced substring.
 * @param j The starting position from which to search for the balanced substring.
 * @return int The length of the balanced substring.
 */
int getSubTree(string S, int j) {
    int s = j;
    j++;
    int numpar = 1;
    
    while (numpar > 0) {
        if (S.at(j) == '(') numpar++;
        if (S.at(j) == ')') numpar--;
        j++;
    }
    return j - s;
}

/**
 * @brief Builds an Abstract Syntax Tree (AST) for a given regular expression.
 *
 * This function constructs an Abstract Syntax Tree (AST) from a given regular expression and a corresponding alphabet.
 *
 * @param regex The regular expression object that provides the alphabet.
 * @param inputRegex The input regular expression to construct the AST from.
 * @return AST* A pointer to the root of the constructed AST.
 * @throw invalid_argument if an unknown character or operator is encountered in the input.
 */
AST* buildSyntaxTree (const Regex& regex, string inputRegex) {

    int lenght = inputRegex.size(); 

    if (lenght == 1 || lenght == 3) {

        char character = inputRegex.at(max(0, lenght-2));
        
        if (regex.getAlphabet().count(character) == 0)
        throw invalid_argument ("unknow "+string(1,character)+"...");

        return new AST (character); 
    }

    char op = inputRegex.at(1); 
    
    if (operators.count(op) == 0) 
    throw invalid_argument("unknow "+string(1,op)+" operator...");

    int startIndex = 2; 
    int stopIndex = getSubTree(inputRegex, startIndex); 

    string leftRegex = inputRegex.substr(startIndex, stopIndex);
    startIndex+=stopIndex; 

    if (op == '*') {

        AST* leftTree = buildSyntaxTree (regex, leftRegex);
        return new AST (op, leftTree, nullptr); 
    }

    else {
        
        stopIndex = getSubTree (inputRegex, startIndex);
        string rightRegex = inputRegex.substr(startIndex, stopIndex);

        AST* leftTree = buildSyntaxTree (regex, leftRegex);
        AST* rightTree = buildSyntaxTree (regex, rightRegex);
        
        return new AST (op, leftTree, rightTree); 
    }
}

int main (int argc, char** argv) {

    if (argc < 2) {
        cout << "insufficient arguments - please enter the file name or bye bye!!" << endl; 
        return -1;
    }

    Regex regex = importRegex(argv[1]);
    AST *ast = buildSyntaxTree (regex, removeblank(regex.getExpression()));

    regex.viewRegex(); 
    cout<<"Regex from Abstract Syntax Tree: \n\t"<<ast->REview()<<endl; 

    return 0; 
}