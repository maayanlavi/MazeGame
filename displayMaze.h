#pragma once
#include "Command.h"
#include "CLI.h"
using namespace std;

class displayMaze : public Command
{
public:
	displayMaze(CLI* view) : m_view(view) {}
	void execute()
	{
		m_view->display();

	}
private:
	CLI* m_view;
};
