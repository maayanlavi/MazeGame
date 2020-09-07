#include "Observable.h"

void Observable::addObserver(Observer& observer)
{
	m_observers.push_back(&observer);
}
void Observable::notify()
{
	for (auto it = m_observers.begin(); it != m_observers.end(); ++it)
		(*it)->update(*this);
}

string Observable::getAction() const { return action; }
void Observable::setAction(string s) { action = s; }