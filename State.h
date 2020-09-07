#pragma once

#include <string>
#include <memory>
#include <iostream>
using namespace std;

template <class T>
class State
{
public:
	State(T state) : m_state(state), m_cost(1), m_cameFrom(nullptr) {}
	~State() {};
	T getState() { return m_state; }
	double getCost() { return m_cost; }
	void setCameFrom(State<T>* dad)
	{
		m_cameFrom = dad;
	}
	void setCost(double cost) { m_cost = cost; }

	bool operator == (const State<T>& s) {
		if (m_state == s.m_state)
			return true;
		else
			return false;
	}

	State<T>* getCameFrom()
	{
		return m_cameFrom;
	}

	bool operator<(const State<T>& _other) const {
		return m_cost < _other.m_cost;
	}

	friend ostream& operator<<(ostream& os, const State<T>& p);



protected:
	T						m_state;
	double					m_cost;
	State<T>*				m_cameFrom;
};

template <class T>
ostream& operator<<(ostream& os, const State<T>& p)
{
	cout << p.m_state << endl;
	return os;

}






