#pragma once
#include "Command.h"
#include "CLI.h"
using namespace std;

class FileSize : public Command
{
public:
	FileSize(CLI* view) : m_view(view) {}
	void execute()
	{
		m_view->FileSize();
		//string s = "the size of the maze in file is ready";
		//m_view->setAction(s);
		//m_view->notify();
	}
private:
	CLI* m_view;
};
