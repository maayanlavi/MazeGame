#pragma once
#include <iostream> 
#include "CommonSearcher.h"
using namespace std;

template <class T>
class Astar : public CommonSearcher<T> {

public:
	Astar() :CommonSearcher<T>() { }

	virtual double Cost(State<T> state, State<Position> goal) = 0;

	bool IsInVec(std::vector<State<T>*> vec, State<T>* s)
	{

		if (count(vec.begin(), vec.end(), s))
			return false;
		return true;
	}

	bool IsInQueue(std::priority_queue<State<T>> q, State<T> s)
	{
		while (!q.empty())
		{
			if (s == q.top())
				return true;
			q.pop();
		}
		return false;
	}



	virtual Solution<T> search(const Searchable<T>& s) {
		Solution<T> sol;
		State<T>* st = new State<T>(s.getStartState());
		sol.setState(st);
		st->setCost(Cost(*st, s.getGoalState()));
		this->pushOpenList(*st);
		while (!this->m_openList.empty())
		{
			State<T>* min = new State<T>(this->topOpenList());
			min->setCost(Cost(*min, s.getGoalState()));
			this->popOpenList();
			sol.setState(min);
			if (*min == s.getGoalState()) {
				sol.setState(min);
				return sol;
			}
			else
			{
				std::vector<State<T>> neighbors = s.getAllPossibleStates(min);
				int size = neighbors.size();
				for (int i = 0; i < size; ++i)
				{
					State<T>* n = &neighbors[i];
					if (!(IsInQueue(this->m_openList, neighbors[i])) && (IsInVec(sol.getSol(), n)))
					{
						sol.setState(n);
						neighbors[i].setCameFrom(min);
						this->pushOpenList(neighbors[i]);
					}

				}

			}

		}
		return sol;
	}

};






