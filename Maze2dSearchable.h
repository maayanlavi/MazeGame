#pragma once
#include "Searchable.h"
#include "MazeGame.h"
//#include "Maze2dState.h"

class Position;

using namespace std;
//template <class T=Position>
class Maze2dSearchable : public Searchable<Position>
{
public:

	Maze2dSearchable(MazeGame* maze) : s_maze(maze) { s_maze->generate(); }

	virtual const State<Position>& getStartState() const {
		Position* start;
		start = &(s_maze->getMaze()->getStartPosition());
		State<Position>* st = new State<Position>(*start);
		return *st;
	}

	virtual const State<Position>& getGoalState() const {
		Position* goal;
		goal = &(s_maze->getMaze()->getGoalPosition());
		State<Position>* st = new State<Position>(*goal);
		return *st;
	}

	virtual std::vector<State<Position>> getAllPossibleStates(State<Position>* ms) const {


		//Cell** pos= ms->getState();
		//std::vector<Maze2dState> res;
		return s_maze->getMaze()->CalculateStates(ms);

	}



private:
	MazeGame* s_maze;
};
