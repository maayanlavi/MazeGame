#pragma once
#include "Command.h"
#include "MyModel.h"

using namespace std;

class loadMaze : public Command
{
public:
	loadMaze(MyModel* model) : m_model(model) {}
	void execute()
	{
		m_model->load();
		string s = "The maze is loaded from the file ";
		m_model->setAction(s);
		m_model->notify();
	}
private:
	MyModel* m_model;
};
