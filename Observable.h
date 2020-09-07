#pragma once

#include <vector>
#include <string>
#include "Observer.h"
using namespace std;

class Observable
{
public:
	void addObserver(Observer& observer);
	void notify();

	string getAction() const;
	void setAction(string s);


private:
	vector<Observer*> m_observers;
	string action;

};