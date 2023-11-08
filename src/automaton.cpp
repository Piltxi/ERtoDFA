#include "../include/automaton.hpp"
using namespace std;

template <typename State, typename Symbol, typename TransitionType>
void Automaton<State, Symbol, TransitionType>::setInitialState(const State& initialState) {
    this->initialState = initialState;
}

template <typename State, typename Symbol, typename TransitionType>
void Automaton<State, Symbol, TransitionType>::setFinalStates(const State& finalStates) {
    this->finalStates = finalStates;
}

template <typename State, typename Symbol, typename TransitionType>
void Automaton<State, Symbol, TransitionType>::setAlphabet(const set<Symbol>& alphabet) {
    this->alphabet = alphabet;
}

template <typename State, typename Symbol, typename TransitionType>
void Automaton<State, Symbol, TransitionType>::setTransitions(const TransitionType& transitions) {
    this->transitions = transitions;
}

template <typename State, typename Symbol, typename TransitionType>
const TransitionType& Automaton<State, Symbol, TransitionType>::getTransitions() const {
    return transitions;
}

template <typename State, typename Symbol, typename TransitionType>
const State& Automaton<State, Symbol, TransitionType>::getStartState() const {
    return initialState;
}

template <typename State, typename Symbol, typename TransitionType>
const State& Automaton<State, Symbol, TransitionType>::getFinalStates() const {
    return finalStates;
}

template <typename State, typename Symbol, typename TransitionType>
const set<Symbol>& Automaton<State, Symbol, TransitionType>::getAlphabet() const {
    return alphabet;
}

template <typename State, typename Symbol, typename TransitionType>
void Automaton<State, Symbol, TransitionType>::addState(const State& state) {
    if (find(allStates.begin(), allStates.end(), state) == allStates.end())
        allStates.push_back(state);
}

template <typename State, typename Symbol, typename TransitionType>
const vector<State>& Automaton<State, Symbol, TransitionType>::getAllStates() const {
    return allStates;
}

template <typename State, typename Symbol, typename TransitionType>
void Automaton<State, Symbol, TransitionType>::printAll() const {
    // Implementazione predefinita di stampa per l'automa
}

template <typename State, typename Symbol, typename TransitionType>
void Automaton<State, Symbol, TransitionType>::addTransition (const State&, const Symbol&, const State&) {
        // default addTransition
}

/**
 * @brief Customized printing method for non-deterministic finite automata (DFA).
 * 
 * This specialization of the printAll function is used to print detailed information about a non-deterministic finite automaton (NDFA).
 * It includes the alphabet, the number of states, the start state, the set of states, transition details, and final state.
 * 
 * @note This specialized printing is tailored for NDFA objects with specific template parameters.
 */
template <>
void Automaton<int, char, multimap<pair<int, char>, int>>::printAll() const {

    cout<<"\nnondeterministic finite automaton data:\n"; 
    cout << "Alphabet:";
    for (const char& symbol : alphabet)
        cout << " '" << symbol << "'";
    cout<<endl; 

    cout<<"Number of States: "<<(getAllStates().size())<<"\tStart State: "<<getStartState()<<endl;

    cout<<"States in order of visit: ";
    for (const int& state : getAllStates())
        cout<<state<<" "; 
    cout<<endl; 

    pair<int, char> currentKey;
    multimap< pair<int, char>, int> transitions = getTransitions(); 

    cout << "\nTransitions:" <<  endl;
    for (const auto& entry : transitions) {
        if (entry.first != currentKey) {
            (currentKey != pair <int, char>() ? cout<<endl : cout<<"" );
            entry.first.second=='*' ? cout<< "fromState: " << entry.first.first <<" >"<<"\u03B5"<<endl : cout<< "fromState: " << entry.first.first <<" >"<<entry.first.second<<endl ;
            currentKey = entry.first;
        }
        cout << "\t-> " << entry.second << endl;
    }

    cout << "\nFinal State: " << getFinalStates()<<endl; 
    
    cout << endl; 
}

/**
 * @brief Customized printing method for deterministic finite automata (DFA).
 * 
 * This specialization of the printAll function is used to print detailed information about a deterministic finite automaton (DFA) after subset construction.
 * It includes the alphabet, the number of states, the start state, the set of states, transition details, and final state(s).
 * 
 * @note This specialized printing is tailored for DFA objects with specific template parameters.
 */
template <>
void Automaton<set<int>, char, map<pair<set<int>, char>, set<int>>>::printAll() const{

    cout<<"\ndeterministic finite automaton data after subset construction:\n"; 
    cout << "Alphabet:";
    for (const char& symbol : alphabet)
        cout << " '" << symbol << "'";
    cout<<endl; 

    cout<<"Number of States: "<<(getAllStates().size()); 
    cout<< "\tStart State: { ";
    for (const int& state: getStartState()) 
        cout<<state << " ";
    cout << "} "<< endl; 

    int index = 0; 
    cout<<"States: \n";
    for (const set<int>& subState : getAllStates()) {
        cout<<index<<"] "; 
        for (int value : subState) {
            cout << value << " ";
        }
        index++; cout << endl;
    }
    cout<<endl; 

   cout << "Transitions:" << endl;
    
    const auto& transitions = getTransitions();
    
    for (const auto& entry : transitions) {
        const set<int>& fromState = entry.first.first;
        const char symbol = entry.first.second;
        const set<int>& toState = entry.second;

        cout << "fromState: {";
        bool firstState = true;
        for (const int& state : fromState) {
            if (!firstState) {
                cout << ", ";
            }
            cout << state;
            firstState = false;
        }
        cout << "} > " << symbol << endl;

        cout << "\t-> {";
        bool firstToState = true;
        for (const int& state : toState) {
            if (!firstToState) {
                cout << ", ";
            }
            cout << state;
            firstToState = false;
        }
        cout << "}" << endl;
    }

    cout << "\nIndex of final State: { ";
    for (const int& state: getFinalStates()) cout<<state << " ";
    cout << "} "<< endl; 

    for (const int& elements : getFinalStates()){
        cout<<elements<<"] { "; 
        for (const int& state: getStateByIndex(elements))
            cout<<state<<" "; 
        cout<<"}"<<endl; 
    }

    cout << endl; 
}

/**
 * @brief checks character validity to represent new state
    To be implemented when changing the type of acceptable values
 * 
 * @param character 
 * @return true accepted character
 * @return false rejected character
 */
bool isState (const char character) {
    
    #ifdef DEBUG
        cout << "STATE -> check on " << character << ".\n"; 
    #endif

    if (isdigit(character))
        return true; 
    
    return false; 
}

/**
 * @brief checks character validity to represent new symbol
    To be implemented when changing the type of acceptable values
 * 
 * @param character 
 * @return true accepted character
 * @return false rejected character
 */
bool isSymbol (const char character) {
    
    #ifdef DEBUG
        cout << "SYMBOL -> check on " << character << ".\n"; 
    #endif

    if (isalpha(character) || isdigit(character))
        return true; 

    return false; 
}

/**
 * @brief Customized method for add transitions in NDFA.
 *
 * This specialization of the printAll function is used to print detailed information about a non-deterministic finite automaton (NDFA).
 * This method is specialized for adding transitions where State is of type int, not set<int>. 
 * It ensures that the number of transitions for the input alphabet '*' is limited to 2, and for other input alphabets, only one transition is allowed.
 *
 * @note This specialized is tailored for NDFA objects with specific template parameters.
 * @param stateInReading The state from which the transition originates.
 * @param inputAlpha The input alphabet symbol for the transition.
 * @param toState The state to which the transition leads.
 * @throw runtime_error if the number of transitions for '*' exceeds 2 or if a duplicate transition for another alphabet is added.
 */
template <>
void Automaton<int, char, multimap<pair<int, char>, int>>::addTransition(const int& stateInReading, const char& inputAlpha, const int& toState) {

    auto starTransitionsRange = transitions.equal_range(make_pair(stateInReading, '*'));
    size_t starCount = distance(starTransitionsRange.first, starTransitionsRange.second);
    
    if (inputAlpha == '*') {
        if (starCount < 2) {
            transitions.emplace(make_pair(make_pair(stateInReading, inputAlpha), toState));
        } else {
            throw runtime_error ("\nERROR - Transitions number, addTransition\n");
        }
    } else {
        auto existingTransitionsRange = transitions.equal_range(make_pair(stateInReading, inputAlpha));
        size_t count = distance(existingTransitionsRange.first, existingTransitionsRange.second);
        
        if (count == 0) {
            transitions.emplace(make_pair(make_pair(stateInReading, inputAlpha), toState));
        } else {
            throw runtime_error ("\nERROR - Transitions number, addTransition\n");
        }
    }
}

/**
 * @brief Find the index of a state in the deterministic automaton (DFA).
 * 
 * This function searches for a specific state within the list of all states in a deterministic automaton (DFA).
 * If the state is found, its index in the list is returned. If the state is not found, -1 is returned, indicating that
 * the state is not present in the automaton.
 * 
 * @param dfa The deterministic automaton (DFA) to search within.
 * @param state The state for which to find the index.
 * @return int The index of the state if found, or -1 if the state is not present.
 */
int getIndexForState(const Automaton<set<int>, char, map<pair<set<int>, char>, set<int>>>& dfa, const set<int>& state) {
    int index = 0;
    for (const set<int>& subState : dfa.getAllStates()) {
        if (subState == state) {
            return index;
        }
        index++;
    }
    return -1;
}
