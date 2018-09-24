//James Aubin 
//522009777
//CSCE 420
//Due: February 12, 2018
//main.cpp
#include <iostream>
#include <sstream>
#include "Node.h"
#include "Solver.h"

using namespace std;

vector<vector<int>> makeBoardFromInput();

int main()
{
	cout << "Enter 8-puzzle starting state by rows (0 for blank): ";
	vector<vector<int>> startBoard = makeBoardFromInput();
	Solver* solver = new Solver(startBoard);

	cout << endl << "Enter 8-puzzle ending state by rows (0 for blank): ";
	vector<vector<int>> goalBoard = makeBoardFromInput();
	cout << endl;

	solver->AStar(goalBoard);
}

vector<vector<int>> makeBoardFromInput()
{	
	vector<int> currentRow;
	vector<vector<int>> board;
	vector<int> boundary(5, -1); //top/bottom border (represented by value -1)
	board.push_back(boundary);

	string userInput;
	cin >> userInput;
	stringstream boardStream(userInput);

	int currTileNum;

	while (boardStream >> currTileNum)
	{
		currentRow.push_back(currTileNum);
		if(currentRow.size() == 3)
		{
			currentRow.insert(currentRow.begin(), -1);
			currentRow.push_back(-1);
			board.push_back(currentRow);
			currentRow.clear();
		}
		if (boardStream.peek() == ',')
		{
			boardStream.ignore();
		}		
	}
	
	board.push_back(boundary);
	return board;
}
