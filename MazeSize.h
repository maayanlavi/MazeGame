#pragma once
#include "Command.h"
#include "CLI.h"
using namespace std;

class MazeSize : public Command
{
public:
	MazeSize(CLI* view) : m_view(view) {}
	void execute()
	{
		m_view->MazeSize();
		//string s = "the size of the maze in the memory is ready";
		//m_view->setAction(s);
		//m_view->notify();
	}
private:
	CLI* m_view;
};
