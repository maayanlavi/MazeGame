#pragma once
#include "Command.h"
#include "MyModel.h"

using namespace std;

class solve : public Command
{
public:
	solve(MyModel* model) : m_model(model) {}
	void execute()
	{
		m_model->solve();
		string s = "solution is ready";
		m_model->setAction(s);
		m_model->notify();
	}
private:
	MyModel* m_model;
};
