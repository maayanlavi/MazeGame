#pragma once
#include "Command.h"
#include "CLI.h"

using namespace std;

class AllFiles : public Command
{
public:
	AllFiles(CLI* view) : m_view(view) {}
	void execute()
	{
		m_view->ShowAllFiles();
		//string s = "All file in this path are ready";
		//m_view->setAction(s);
		//m_view->notify();
	}
private:
	CLI* m_view;
};
