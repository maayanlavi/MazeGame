#pragma once
//#include "maze2d.h"
#include "State.h"
#include <vector>

template <class T>
class Searchable
{
public:
	virtual const State<T>& getStartState() const = 0;
	virtual const State<T>& getGoalState() const = 0;
	virtual std::vector<State<T>> getAllPossibleStates(State<T>* ms) const = 0;

};