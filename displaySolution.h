#pragma once
#include "Command.h"
#include "CLI.h"

using namespace std;

class displaySolution : public Command
{
public:
	displaySolution(CLI* view) : m_view(view) {}
	void execute()
	{
		m_view->displaySolution();
		//string s = "display solution is ready";
		//m_view->setAction(s);
		//m_view->notify();
	}
private:
	CLI* m_view;
};
