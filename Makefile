CXX = g++
CXXFLAGS = -std=c++11 -Wall

automaton: obj/main.o obj/regex.o include/regex.hpp obj/abstractSyntaxTree.o
	$(CXX) $(CXXFLAGS) -o automaton obj/main.o obj/regex.o obj/abstractSyntaxTree.o

obj/main.o: obj/regex.o  include/regex.hpp main.cpp obj/abstractSyntaxTree.o
	$(CXX) $(CXXFLAGS) -c main.cpp -o $@

obj/abstractSyntaxTree.o: include/abstractSyntaxTree.hpp src/abstractSyntaxTree.cpp
	$(CXX) $(CXXFLAGS) -c src/abstractSyntaxTree.cpp -o $@

obj/automaton.o: include/automaton.hpp src/automaton.cpp
	$(CXX) $(CXXFLAGS) -c src/automaton.cpp -o $@

obj/regex.o: include/regex.hpp src/regex.cpp
	$(CXX) $(CXXFLAGS) -c src/regex.cpp -o $@


.PHONY: clean cleanall

clean: 
	rm -f obj/*.o

cleanall:
	rm -f *.out obj/*.o automaton