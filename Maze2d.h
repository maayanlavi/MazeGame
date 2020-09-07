#pragma once
#include <iostream>
#include <cstdio>
# include <vector>
#include "State.h"
using namespace std;

#define SIZE 11

class Position {
private:
	int _x;
	int _y;
public:
	Position();
	Position(int x, int y);
	Position(const Position& m);
	int getX() const;
	int getY() const;
	void setX(int x);
	void setY(int y);

	friend bool operator!=(const Position& p1, const Position& p2);
	friend bool operator==(const Position& p1, const Position& p2);
	friend ostream& operator<<(ostream& os, const Position& p);

};


struct Cell
{
	Position p;
	bool visited;
	bool top_wall;
	bool bot_wall;
	bool left_wall;
	bool right_wall;
	char display;

	Cell();


	bool operator==(const Cell& c1)const;
	Cell& operator=(const Cell& other);

};

class Maze2d {
private:
	Cell Board[SIZE][SIZE];
	Cell* _start;
	Cell* _end;
public:
	Maze2d();
	Maze2d(vector<char>& vec);
	Maze2d(vector<vector<char>> vec);
	Maze2d& operator=(const Maze2d& m);
	void Redraw();
	virtual bool Isvalid(int NextX, int Nexty);
	void Setdisplay(int x, int y, string str);
	void SetStartPosition(int x, int y);
	Position getStartPosition();
	Position getGoalPosition();
	bool IsVisited(int x, int y);
	void Setvisited(int x, int y);
	void SetWall(int x, int y, char c);
	void SetEndPosition(int x, int y);
	string* getPossibleMoves(Position p);
	void initMaze();
	void displaySolve(int x, int y);
	vector<char> getdata();
	Position* getStartState();
	Position* getGoalState();
	std::vector<State<Position>> CalculateStates(State<Position>* st);
	Cell getStart();
	Cell getEnd();
	Cell& getCell(int x, int y);
	Cell* getCellpointer(int x, int y);

	friend ostream& operator<<(ostream& os, const Maze2d& maze);
};


