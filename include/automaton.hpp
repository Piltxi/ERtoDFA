#ifndef AUTOMATON_H
#define AUTOMATON_H

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
// Some debug print
// #define DEBUG

const char epsilon = '*'; // '*' simulates the Greek epsilon

using namespace std;

template <typename State, typename Symbol, typename TransitionType>
class Automaton {
private:
    State initialState;
    State finalStates;
    set<Symbol> alphabet;
    TransitionType transitions;
    vector<State> allStates;

public:
    Automaton() {}

    void setInitialState(const State& initialState);
    void setFinalStates(const State& finalStates);
    void setAlphabet(const set<Symbol>& alphabet);
    void setTransitions(const TransitionType& transitions);

    const TransitionType& getTransitions() const;
    const State& getStartState() const;
    const State& getFinalStates() const;
    const set<Symbol>& getAlphabet() const;

    void addState(const State& state);
    const vector<State>& getAllStates() const;
    void printAll() const;
    const set<int>& getStateByIndex(int index) const;
    int countAllStates() const;
    void addTransition (const State&, const Symbol&, const State&); 
};

template <typename State, typename Symbol, typename TransitionType>
void generateNDFADotFile(const Automaton<State, Symbol, TransitionType>& automaton, const string& imageName);

template <typename State, typename Symbol, typename TransitionType>
void generateDFADotFile(const Automaton<State, Symbol, TransitionType>& automaton, const string& imageName);

template <typename State, typename Symbol, typename TransitionType>
void writeOutputDFA(const Automaton<State, Symbol, TransitionType>& automaton, const string& nameFile);

bool isState (const char);

bool isSymbol (const char);

#endif
