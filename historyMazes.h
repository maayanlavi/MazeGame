#pragma once

#include <map>
#include <vector>
#include <string>
#include <fstream>
#include "Solution.h"
#include "MazeGame.h"
using namespace std;

class historyMazes
{
public:
	historyMazes() {
		ifstream in("AllSolutions.txt");
		string name;
		string sol1;
		string sol2;
		while (in.good())
		{
			getline(in, name);
			Solution<Position> s;
			AllMazeSol[name] = s;
		}
	}

	map<string, MazeGame*> getAllMaze() { return AllMaze; }
	map <string, Solution<Position>> getAllMazeSol() { return AllMazeSol; }
	void setInAllMaze(string s, MazeGame* m)
	{
		AllMaze[s] = m;
	}
	void setInAllMazeSol(string s, Solution<Position> sol)
	{
		AllMazeSol[s] = sol;
	}

	bool isInSol(string s)
	{
		if (AllMazeSol.find(s) == AllMazeSol.end()) {
			return false;
		}
		else {
			return true;
		}
	}

protected:
	map<string, MazeGame*> AllMaze;
	map <string, Solution<Position>> AllMazeSol;

};