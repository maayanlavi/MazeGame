#pragma once
#include "Command.h"
#include "MyModel.h"

using namespace std;

class GenerateMaze : public Command
{
public:
	GenerateMaze(MyModel* model) : m_model(model) {}
	void execute()
	{
		m_model->generate();
		string s = "maze is ready";
		m_model->setAction(s);
		m_model->notify();
	}
private:
	MyModel* m_model;
};
