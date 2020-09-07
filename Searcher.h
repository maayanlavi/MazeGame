#pragma once
#include "Solution.h"
#include "searchable.h"
#include <queue>

template <class T>
class Searcher
{
public:

	virtual Solution<T> search(const Searchable<T>& s) = 0;
	virtual int getNumberOfNodesEvaluated() = 0;

};