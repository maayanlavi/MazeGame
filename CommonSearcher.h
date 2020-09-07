#pragma once

#include "Searcher.h"
#include <Windows.h>
#include <queue>

using namespace std;

template <class T>
class Compare
{
public:
	bool operator() (State<T>* a, State<T>* b)
	{
		return (a->m_cost > b->m_cost);
	}
};


template <class T>
class CommonSearcher :public Searcher<T> {
public:
	CommonSearcher() : m_evaluatedNodes(0) {}

public:
	virtual Solution<T> search(const Searchable<T>& s) = 0;
	virtual int getNumberOfNodesEvaluated() { return m_evaluatedNodes; };
	const State<T> topOpenList() { m_evaluatedNodes++; return m_openList.top(); }
	void popOpenList() { m_openList.pop(); }
	void pushOpenList(State<T> state) { m_openList.push(state); }

protected:
	int m_evaluatedNodes;
	priority_queue<State<T>> m_openList;

};