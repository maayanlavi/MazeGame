#pragma once
#include "Command.h"
#include "MyModel.h"

using namespace std;

class saveMaze : public Command
{
public:
	saveMaze(MyModel* model) : m_model(model) {}
	void execute()
	{
		m_model->save();
		string s = "The maze is saved in the file ";
		m_model->setAction(s);
		m_model->notify();
	}
private:
	MyModel* m_model;
};
