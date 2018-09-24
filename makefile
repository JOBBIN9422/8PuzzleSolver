CXX=g++
CXXFLAGS=-Wall -g

main: main.o Node.o Solver.o
	$(CXX) $(CXXFLAGS) -o main main.o Node.o Solver.o

main.o: main.cpp Node.h Solver.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Node.o: Node.cpp Node.h
	$(CXX) $(CXXFLAGS) -c Node.cpp
	
Solver.o: Solver.cpp Solver.h
	$(CXX) $(CXXFLAGS) -c Solver.cpp
