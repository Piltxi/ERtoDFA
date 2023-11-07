
<h3 align="center">from ER to DFA</h3>

<div align="center">

</div>

---

<p align="center"> Implementation of models to handle regular expressions, the corresponding transformation into a non-deterministic automaton and the conversion into a deterministic automaton. 
Implementation of the Thompson algorithm and use of the Subset Construction algorithm. 
    <br> 
</p>

## 📝 Table of Contents

- [Problem Statement](#problem_statement)
- [Idea / Solution](#idea)
- [Future Scope](#future_scope)
- [Built with](#tech_stack)
- [Authors](#authors)

## 🧐 Problem Statement <a name = "problem_statement"></a>

The problem requires designing an operative and efficient data structure to store information about automata.
In particular, it is necessary to implement the entire conversion process from regular expression to deterministic finite automaton. The difficulty increases further due to the format of the text files (look at the files in the path input/input.txt). 
Furthermore, the implementation of the Thompson's construction algorithm TCA and the implementation of the subset construction algorithm are required.


## 💡 Idea / Solution <a name = "idea"></a>

Transform the input regular expression into its tree representation: thus generate an abstract syntax tree. 
Using templates and exploiting generics types, define a class that can be used for both non-deterministic finite automata and deterministic finite automata.
<br><br>
For the first part of the solution, we implement a DFS visit in post order of the AST. Using a stack, create all the components of the non-deterministic finite automaton.
Thanks to the use of the stack, the complete non-deterministic finite automaton is obtained (Hopefully)
<br>
For the second part, implement the subset construction algorithm and the espilon closure model.
it is important to verify the correctness of the transitions between states within the automaton.

## 🚀 Future Scope <a name = "future_scope"></a>

Study the behavior of automata; state model design.
Examples of algorithmic construction and complex data structures.

## 🏁 Getting Started <a name = "getting_started"></a>

These instructions will get you a copy of the project up and running on your local machine for development
and testing purposes. See [deployment](#deployment) for notes on how to deploy the project on a live system.

### Clone repository
```
git clone hhh
```

### Installing

```
make
```

### Run

```
make debuga
```

```
./automaton [yourInputRegex.txt]
```

## ⛏️ Built With <a name = "tech_stack"></a>

- [Graphviz](https://graphviz.org/) Dot file generation and graphic representation of automata
- [C++](https://isocpp.org/) Main program
- [STL C++](https://learn.microsoft.com/en-us/cpp/standard-library/cpp-standard-library-reference?view=msvc-170) Use of STL data structures

## ✍️ Authors <a name = "authors"></a>

- [@piltxi]

