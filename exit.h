#pragma once
#include "Command.h"
#include "MyModel.h"

using namespace std;

class Exit : public Command
{
public:
	Exit(MyModel* model) : m_model(model) {}
	void execute()
	{
		m_model->exit();
	}
private:
	MyModel* m_model;
};
