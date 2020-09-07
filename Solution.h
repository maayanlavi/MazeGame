#pragma once
#include <iostream>
#include <vector>
#include "State.h"

class Position;
using namespace std;
template <class T>

class Solution
{
public:
	Solution() {}
	~Solution() {};
	void setState(State<T>* state) {
		m_solution.push_back(state);

	}

	std::vector<State<T>*> getSol() {
		return m_solution;
	}

	//State<T>& operator[](int index) {

	//	if (index >= SIZE - 1 || index<0) {
	//		cout << "Array index out of bound, exiting";
	//		exit(0);
	//	}
	//	return m_solution[index];
	//}

	friend ostream& operator<<(ostream& os, const Solution<Position>& p);
	//friend ofstream& operator>>(ofstream& os, const Solution<Position>& p);


private:
	std::vector<State<T>*> m_solution;

};

//ofstream& operator>>(ofstream& os, const Solution<Position>& p)
//{
//
//	os << p;
//	return os;
//
//}


ostream& operator<<(ostream& os, const Solution<Position>& p)
{
	int size = p.m_solution.size();
	for (int i = 0; i < size; ++i)
	{
		cout << p.m_solution[i]->getState().getX() << ", " << p.m_solution[i]->getState().getY() << endl;
	}

	return os;
}


